/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pba <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/20 16:04:35 by pba               #+#    #+#             */
/*   Updated: 2016/05/22 12:22:18 by pba              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"

/*
** In ft_builtins() fonction, we check if the written command is builtin
** (Here "cd", or "pwd")
*/

static void			handle_cd(t_env *serv_env)
{
	int				result;

	if ((result = open_dir(args(serv_env->cmd), serv_env)) == -1)
	{
		serv_env->result.code_return = -1;
		ft_putstr_fd("No such file or directory : ", serv_env->cs);
		ft_putendl_fd(serv_env->cmd[1], serv_env->cs);
	}
	else if (result == -2)
		serv_env->result.code_return = -1;
	else if (result == 0)
		serv_env->result.code_return = 1;
}

static void			handle_pwd(t_env *serv_env)
{
	if (get_pwd(serv_env) == NULL)
		serv_env->result.code_return = -1;
	else
		serv_env->result.code_return = 1;
}

static void			handle_put(t_env *serv_env)
{
	if (serv_env->cmd[1] == NULL)
		return ;
	if (put_file_serv(serv_env) == 0)
	{
		serv_env->result.code_return = -1;
		return ;
	}
	serv_env->result.code_return = 1;
}

static const t_func g_func[] =
{
	{"cd", &handle_cd},
	{"pwd", &handle_pwd},
	{"put_file_", &handle_put},
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
