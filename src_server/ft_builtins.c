/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_builtins.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pba <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/20 16:04:35 by pba               #+#    #+#             */
/*   Updated: 2016/05/10 03:50:37 by pba              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"

/*
** In ft_builtins() fonction, we check if the written command is builtin
** (Here "cd", or "pwd")
*/

int				ft_builtins(t_env *serv_env)
{
	if (ft_strcmp(serv_env->cmd[0], "cd") == 0)
	{
		if (open_dir(args(serv_env->cmd), serv_env) == -1)
		{
			ft_putstr("cd : no such file or directory : ");
			ft_putendl(serv_env->cmd[1]);
		}
	}
	else if (ft_strcmp(serv_env->cmd[1], "pwd") == 0)
		get_pwd(serv_env);
	else
		return (0);
	return (1);
}
