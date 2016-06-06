/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pwd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pba <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/22 18:24:37 by pba               #+#    #+#             */
/*   Updated: 2016/06/05 11:48:19 by pba              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"

/*
** "/" is the server root.
** there's no way to get out this directory.
*/

static char			*pwd_error(t_env *serv_env)
{
	ft_putstr_red_fd("Sending did not work.", serv_env->cs);
	ft_putchar_fd('\n', serv_env->cs);
	return (NULL);
}

char				*get_pwd(t_env *serv_env)
{
	char			buf[PATH_MAX];
	char			*pwd;

	ft_memset((void *)buf, 0, 1024);
	pwd = ft_strdup(getcwd(buf, PATH_MAX));
	if (ft_strequ(pwd, serv_env->home))
	{
		if (send(serv_env->cs, "/\n", 2, 0) == -1)
			return (pwd_error(serv_env));
	}
	else
	{
		pwd = pwd + serv_env->home_len;
		if (send(serv_env->cs, pwd, ft_strlen(pwd), 0) == -1
				|| send(serv_env->cs, "\n", 1, 0) == -1)
			return (pwd_error(serv_env));
	}
	return (pwd);
}
