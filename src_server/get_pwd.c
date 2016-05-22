/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pwd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pba <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/22 18:24:37 by pba               #+#    #+#             */
/*   Updated: 2016/05/21 16:49:00 by pba              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"

/*
** If we are in server home directory we write "/".
*/

static char			*pwd_error(t_env *serv_env)
{
	dup2(serv_env->cs, 2);
	ft_putstr_red_fd("Sending did not work.", 2);
	ft_putchar_fd('\n', 2);
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
