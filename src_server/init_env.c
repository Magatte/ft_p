/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pba <pba@42.fr>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/05 13:56:22 by pba               #+#    #+#             */
/*   Updated: 2016/05/27 03:55:13 by pba              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"

t_env					*init_env(char **env)
{
	t_env				*serv_env;
	char				buf[PATH_MAX + 1];

	if ((serv_env = (t_env *)malloc(sizeof(t_env))) == NULL)
		return (NULL);
	serv_env->env = env;
	serv_env->home = NULL;
	serv_env->home = ft_strdup(getcwd(buf, PATH_MAX)); //leaks
	serv_env->home_len = ft_strlen(serv_env->home);
	serv_env->pwd = serv_env->home;
	serv_env->old_pwd = serv_env->home;
	serv_env->path = NULL;
	serv_env->cmd = NULL;
	return (serv_env);
}
