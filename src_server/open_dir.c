/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_dir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pba <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/11 10:00:55 by pba               #+#    #+#             */
/*   Updated: 2016/05/10 03:48:27 by pba              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"

/*
** For the open_dir function we made added two strings in our t_env structure :
** the first one (pwd) refers to current path
** the second one stands for the old_pwd i.e. the previous path
** First step : we call chdir function 
** and then compare the current path with the home path.
** If it does match pwd and old_pwd are changed.
** If it doesn't match these ones aren't changed and 
** we go back to the previous path i.e. pwd. 
*/

int			get_to_path(const char *path, char *buf, t_env *serv_env)
{
	int		result;

	result = chdir(path);
	if (ft_strncmp(serv_env->home, getcwd(buf, PATH_MAX),
			ft_strlen(serv_env->home)) == 0)
	{
		serv_env->old_pwd = serv_env->pwd;
		serv_env->pwd = ft_strdup(getcwd(buf, PATH_MAX));
	}
	else
	{
		chdir(serv_env->pwd);
		ft_putendl_fd("You can't go below home directory.", 2);
		result = -2;
	}
	return (result);
}

int			open_dir(int args, t_env *serv_env)
{
	char	buf[PATH_MAX + 1];

	if (args > 1)
	{
		ft_putendl_fd("cd: Too many arguments.", 2);
		return (0);
	}
	else if (args == 0)
		return (chdir(serv_env->home));
	else if (ft_strcmp(serv_env->cmd[1], "~") == 0)
	{
		serv_env->old_pwd = serv_env->pwd;
		serv_env->pwd = ft_strdup(getcwd(buf, PATH_MAX));
		return (chdir(serv_env->home));
	}
	else if (ft_strcmp(serv_env->cmd[1], "-") == 0)
	{
		serv_env->old_pwd = serv_env->pwd;
		serv_env->pwd = ft_strdup(getcwd(buf, PATH_MAX));
		return (chdir(serv_env->old_pwd));
	}
	return (get_to_path(serv_env->cmd[1], buf, serv_env));
}
