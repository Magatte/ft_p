/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   status.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pba <pba@42.fr>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/12 17:06:55 by pba               #+#    #+#             */
/*   Updated: 2016/05/16 02:30:49 by pba              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"

void			status(t_env *serv_env, int fd, int mode)
{
	if (mode == 1)
	{
		ft_putstr_blue_fd("[SUCCESS] ", fd);
		ft_putstr_blue_fd(serv_env->cmd[0], fd);
		ft_putchar_fd('\n', fd);
	}
	if (mode == 2)
	{
		ft_putstr_red_fd("[FAILURE] ", fd);
		ft_putstr_red_fd(serv_env->cmd[0], fd);
		ft_putchar_fd('\n', serv_env->cs);
	}
}
