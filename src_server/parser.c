/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pba <pba@42.fr>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/20 16:20:34 by pba               #+#    #+#             */
/*   Updated: 2016/05/31 04:58:35 by pba              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include		"ft_p.h"

/*
** We remove th '\n' at the end of the command line.
** We check if the path does exist for us to get the path.
** And finally, we execute the command.
*/

void			parser(t_env *serv_env, char *line)
{
	line = ft_strtrim(line);
	if (check_path(serv_env->env) == 1)
		serv_env->path = get_path(serv_env->env);
	if (line && line[0] != '\0')
		exec_cmd(line, serv_env);
	if (check_path(serv_env->env) == 1)
		free(serv_env->path);
}
