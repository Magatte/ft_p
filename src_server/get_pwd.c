/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pwd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pba <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/22 18:24:37 by pba               #+#    #+#             */
/*   Updated: 2015/11/02 03:25:23 by pba              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"

/*
** If we are in server home directory we write "/".
*/

void			get_pwd(t_env *serv_env)
{
	char		buf[PATH_MAX + 1];
	char		*pwd;

	pwd = ft_strdup(getcwd(buf, PATH_MAX));
	if (ft_strcmp(pwd, serv_env->home) == 0)
		ft_putendl("/");
	else
		ft_putendl(pwd + serv_env->home_len);
}
