/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file_serv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pba <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 03:13:01 by pba               #+#    #+#             */
/*   Updated: 2016/06/04 22:02:10 by pba              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"

/*
** init_transfer checks if the file can be copied,
** puts some informations such as the size of the file,
** a result message, the file name and sends it to the client.
** if the result message is OK get_file_serv read from the file
** and sends it to the client.
*/

int						get_file_serv(t_env *serv_env)
{
	int					fd;
	int					n;
	int					r;
	int					buf[USHRT_MAX];

	if (serv_env->result.client != 1)
		return (0);
	if (init_transfer(&serv_env->transf, serv_env->cs, serv_env->cmd, &fd) == 0)
	{
		send(serv_env->cs, &serv_env->transf, sizeof(t_transfer), 0);
		ft_putstr_red_fd("[get_file_ERROR]\n", 1);
		return (0);
	}
	ft_putstr_blue_fd(serv_env->transf.msg, 1);
	ft_putchar_fd('\n', 1);
	if (send(serv_env->cs, &serv_env->transf, sizeof(t_transfer), 0) == -1)
		return (0);
	n = serv_env->transf.size / USHRT_MAX + 1;
	while (n--)
	{
		ft_memset((void *)buf, 0, USHRT_MAX);
		r = read(fd, buf, USHRT_MAX);
		send(serv_env->cs, buf, r, 0);
	}
	return (1);
}
