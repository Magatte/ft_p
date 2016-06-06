/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pba <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/20 16:04:35 by pba               #+#    #+#             */
/*   Updated: 2016/06/05 07:09:56 by pba              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"

/*
** if the written command is a builtin command it's executed
** and a notification is sent to indicate the end of the sending operation.
** builtins = pwd, cd, put, get, quit.
*/

static const t_func g_func[] =
{
	{"cd", &handle_cd},
	{"pwd", &handle_pwd},
	{"put", &handle_put},
	{"get", &handle_get},
	{"quit", &handle_quit},
	{0, 0}
};

int					builtins(t_env *serv_env)
{
	int				i;

	i = 0;
	while (g_func[i].cmd != 0)
	{
		if (ft_strequ(serv_env->cmd[0], g_func[i].cmd))
		{
			g_func[i].func(serv_env);
			if (serv_env->result.code_return == -1)
				status(serv_env, serv_env->cs, 2);
			else
				status(serv_env, serv_env->cs, 1);
			notify_send(serv_env->cs, &serv_env->result);
			return (1);
		}
		++i;
	}
	return (0);
}
