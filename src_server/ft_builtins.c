/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtins.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pba <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/20 16:04:35 by pba               #+#    #+#             */
/*   Updated: 2016/05/16 03:41:17 by pba              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"

/*
** In ft_builtins() fonction, we check if the written command is builtin
** (Here "cd", or "pwd")
*/

int				ft_builtins(t_env *serv_env)
{
	int			result;

	if (ft_strequ(serv_env->cmd[0], "cd"))
	{
		if ((result = open_dir(args(serv_env->cmd), serv_env)) == -1)
		{
			status(serv_env, serv_env->cs, 2);
			ft_putstr_fd("No such file or directory : ", serv_env->cs);
			ft_putendl_fd(serv_env->cmd[1], serv_env->cs);
			notify_send(serv_env->cs, &serv_env->result);
		}
		if (result && result != -2)
			status(serv_env, serv_env->cs, 1);
		notify_send(serv_env->cs, &serv_env->result);
	}
	else if (ft_strequ(serv_env->cmd[0], "pwd"))
	{
		status(serv_env, serv_env->cs, 1);
		get_pwd(serv_env);
		notify_send(serv_env->cs, &serv_env->result);
	}
	else
		return (0);
	return (1);
}
