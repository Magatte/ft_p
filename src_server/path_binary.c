/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_binary.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pba <pba@42.fr>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/21 23:10:27 by pba               #+#    #+#             */
/*   Updated: 2016/05/10 03:57:08 by pba              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"

/*
** The path_binary function is designed for binary commands such as "ls".
** First we have to check in every folder of the environment path variable 
** if we have execution rights on the binary file named by its path.
** We use for that the function access.
** Access returns 0 in case of success and -1 otherwise.
** In case of success, we use execv to execute de command.
*/

void			path_binary(t_env *serv_env)
{
	char		*tmp;
	char		*binary;
	int			i;

	binary = serv_env->cmd[0];
	i = 0;
	while (serv_env->path[i])
	{
		tmp = ft_strjoin(ft_strjoin(serv_env->path[i], "/"), binary);
		if ((!access(tmp, X_OK)) || (!access(binary, X_OK)))
		{
			execv(tmp, serv_env->cmd);
			execv(binary, serv_env->cmd);
		}
		i++;
		free(tmp);
	}
}
