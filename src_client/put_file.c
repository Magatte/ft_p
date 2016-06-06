/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pba <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/21 20:22:33 by pba               #+#    #+#             */
/*   Updated: 2016/06/04 22:07:06 by pba              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"

/*
** init_transfer checks if the file can be copied,
** puts some informations such as the size of the file,
** a result message, the file name, and sends it to the server.
** if all succeeds we read the file and send it to the server.
*/

int					put_file(int sock, char **cmd)
{
	int				fd;
	int				n;
	int				r;
	t_transfer		transf;
	int				buf[USHRT_MAX];

	if (cmd[1] == NULL || ft_strequ(cmd[1], "$"))
		return (0);
	if (init_transfer(&transf, sock, cmd, &fd) == 0)
	{
		send(sock, &transf, sizeof(t_transfer), 0);
		return (0);
	}
	if (send(sock, &transf, sizeof(t_transfer), 0) == -1)
		return (0);
	if (transf.size == 0)
		return (1);
	n = transf.size / USHRT_MAX + 1;
	while (n--)
	{
		ft_memset((void *)buf, 0, USHRT_MAX);
		r = read(fd, buf, USHRT_MAX);
		send(sock, buf, r, 0);
	}
	return (1);
}
