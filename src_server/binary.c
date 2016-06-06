/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   binary.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pba <pba@42.fr>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/20 16:14:45 by pba               #+#    #+#             */
/*   Updated: 2016/06/05 04:06:18 by pba              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"

/*
** the binary function is designed to execute binary commands
** by making a fork.
** the father process waits for the child process to end.
*/

int					binary(t_env *serv_env)
{
	int				child_exit_status;
	pid_t			pid;

	child_exit_status = -1;
	pid = fork();
	if (pid > 0)
	{
		wait4(pid, &child_exit_status, 0, NULL);
		serv_env->result.code_return = child_exit_status;
		if (serv_env->result.code_return == 256)
			status(serv_env, serv_env->cs, 2);
		else
			status(serv_env, serv_env->cs, 1);
		notify_send(serv_env->cs, &serv_env->result);
	}
	if (pid == 0)
	{
		path_binary(serv_env);
		ft_strcpy(serv_env->result.command, serv_env->cmd[0]);
		exit(1);
	}
	return (serv_env->result.code_return);
}
