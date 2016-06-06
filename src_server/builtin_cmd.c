/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pba <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/05 07:07:23 by pba               #+#    #+#             */
/*   Updated: 2016/06/05 11:40:59 by pba              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"

void				handle_quit(t_env *serv_env)
{
	if (serv_env->result.client != 1)
	{
		serv_env->result.code_return = -1;
		return ;
	}
	ft_putstr_red_fd("client [", 1);
	ft_putnbr_fd(serv_env->cs, 1);
	ft_putstr_red_fd("] disconnected\n", 1);
	serv_env->result.code_return = -2;
	notify_send(serv_env->cs, &serv_env->result);
	exit(1);
}

void				handle_cd(t_env *serv_env)
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

void				handle_pwd(t_env *serv_env)
{
	if (get_pwd(serv_env) == NULL)
		serv_env->result.code_return = -1;
	else
		serv_env->result.code_return = 1;
}

void				handle_put(t_env *serv_env)
{
	if (!serv_env->cmd[1] || put_file_serv(serv_env) == 0)
	{
		serv_env->result.code_return = -1;
		return ;
	}
	serv_env->result.code_return = 1;
}

void				handle_get(t_env *serv_env)
{
	if (!serv_env->cmd[1] || get_file_serv(serv_env) == 0)
	{
		serv_env->result.code_return = -1;
		return ;
	}
	serv_env->result.code_return = 1;
}
