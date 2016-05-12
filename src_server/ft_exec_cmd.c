/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pba <pba@42.fr>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/25 15:31:03 by pba               #+#    #+#             */
/*   Updated: 2016/05/10 04:02:48 by pba              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"

/*
** Here we have to find out if the command is builtin or binary 
** by calling first ft_builtins and secondly calling ft_binary.
** Each of these functions is exclusive.
** If the command isn't builtin nor binary 
** this does mean the command doesn't exist. Thus, an error message appears :
** "zsh : comd not found : " + the written command.
*/

void			ft_exec_cmd(char *line, t_env *serv_env)
{
	serv_env->cmd = ft_strsplit(line, ' ');
	ft_putstr("1ere commande : ");
	ft_putendl(serv_env->cmd[0]);
	if ((ft_builtins(serv_env) == 1))
		return ;
	else if (ft_binary(serv_env) == 0)
	{
		write(2, "zsh : comd not found : ", 23);
		ft_putendl(line);
		exit(0);
	}
}
