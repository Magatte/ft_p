/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pba <pba@42.fr>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/25 15:31:03 by pba               #+#    #+#             */
/*   Updated: 2016/05/22 12:21:18 by pba              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"

/*
** Here we have to find out if the command is builtin or binary 
** by calling first ft_builtins and secondly calling ft_binary.
** Each of these functions is exclusive.
** If the command isn't builtin nor binary 
** this does mean the command doesn't exist. Thus, an error message appears :
** "[FAILURE]" + the command.
*/

void			exec_cmd(char *line, t_env *serv_env)
{
	serv_env->cmd = NULL;
	serv_env->cmd = ft_strsplit(line, ' ');
	if ((builtins(serv_env) == 1))
		return ;
	binary(serv_env);
}
