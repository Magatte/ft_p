/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pba <pba@42.fr>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/25 15:31:03 by pba               #+#    #+#             */
/*   Updated: 2016/06/05 12:54:36 by pba              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"

/*
** Here we have to find out if the command is a builtin or binary one
** If the command isn't builtin nor binary
** this does mean the command isn't valid. Thus, an error message appears :
** "[FAILURE]" + the command.
*/

void			exec_cmd(char *line, t_env *serv_env)
{
	serv_env->cmd = ft_strsplit(line, ' ');
	free(line);
	if ((builtins(serv_env) == 1))
		return ;
	binary(serv_env);
}
