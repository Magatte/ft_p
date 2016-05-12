/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_binary.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pba <pba@42.fr>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/20 16:14:45 by pba               #+#    #+#             */
/*   Updated: 2016/05/10 01:06:26 by pba              ###   ########.fr       */
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

	pid = fork();
	if (pid > 0)
		wait(&child_exit_status);
	if (pid == 0)
	{
		path_binary(serv_env);
		return (0);
	}
	return (42);
}
