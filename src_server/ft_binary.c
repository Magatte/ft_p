/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_binary.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pba <pba@42.fr>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/20 16:14:45 by pba               #+#    #+#             */
/*   Updated: 2016/05/16 02:29:43 by pba              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"

/*
** The ft_binary function is designed for binary command execution.
** To execute our own binary file we need to call the fork() function.
** The father process is suspended with the system call wait 
** until the child process exits.
*/

int					ft_binary(t_env *serv_env)
{
	int				child_exit_status;
	pid_t			pid;

	child_exit_status = -1;
	pid = fork();
	if (pid > 0)
	{
		wait4(pid, &child_exit_status, 0, NULL);
		serv_env->result.code_return = child_exit_status;
		ft_strcpy(serv_env->result.command, serv_env->cmd[0]);
		if (serv_env->result.code_return == 256)
			status(serv_env, serv_env->cs, 2);
		notify_send(serv_env->cs, &serv_env->result);
	}
	if (pid == 0)
	{
		path_binary(serv_env);
		exit(1);
	}
	return (serv_env->result.code_return);
}
