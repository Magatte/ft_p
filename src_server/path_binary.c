/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_binary.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pba <pba@42.fr>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/21 23:10:27 by pba               #+#    #+#             */
/*   Updated: 2016/06/05 12:14:51 by pba              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"

/*
** By using the access sycall we search for the commands in the path directories
** Access returns 0 in case of success and -1 otherwise.
** In case of success, we use execv to execute de command.
** After execution the process is killed.
*/

void			path_binary(t_env *serv_env)
{
	char		*cmd;
	char		*binary;
	int			i;

	binary = serv_env->cmd[0];
	i = 0;
	while (serv_env->path[i])
	{
		cmd = ft_strjoin(ft_strjoin(serv_env->path[i], "/"), binary);
		if ((!access(cmd, X_OK)) || (!access(binary, X_OK)))
		{
			dup2(serv_env->cs, 1);
			dup2(serv_env->cs, 2);
			execv(cmd, serv_env->cmd);
			execv(binary, serv_env->cmd);
			close(serv_env->cs);
		}
		i++;
		free(cmd);
	}
}
