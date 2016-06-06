/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_dir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pba <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/11 10:00:55 by pba               #+#    #+#             */
/*   Updated: 2016/06/05 11:50:08 by pba              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"

/*
** For the open_dir function we made added two strings in our t_env structure :
** the first one (pwd) refers to current path
** the second one stands for the old_pwd i.e. the previous path
** First step : we call chdir function
** and check if we inside the server home directory.
** If it does match pwd and old_pwd are changed.
** If it doesn't match these ones aren't changed and
** an error message is shown.
*/

static int		get_to_path(const char *path, char *buf, t_env *serv_env)
{
	int			result;

	result = chdir(path);
	if (ft_strnequ(serv_env->home, getcwd(buf, PATH_MAX),
			ft_strlen(serv_env->home)))
	{
		serv_env->old_pwd = serv_env->pwd;
		serv_env->pwd = ft_strdup(getcwd(buf, PATH_MAX));
	}
	else
	{
		chdir(serv_env->pwd);
		ft_putendl_fd("You can't go below home directory.", serv_env->cs);
		result = -2;
	}
	return (result);
}

int				open_dir(int args, t_env *serv_env)
{
	char		buf[PATH_MAX + 1];

	if (args > 1)
	{
		ft_putendl_fd("Too many arguments.", serv_env->cs);
		return (-3);
	}
	else if (args == 0)
		return (chdir(serv_env->home));
	if (ft_strequ(serv_env->cmd[1], "~") || ft_strequ(serv_env->cmd[1], "/"))
	{
		serv_env->old_pwd = serv_env->pwd;
		serv_env->pwd = ft_strdup(getcwd(buf, PATH_MAX));
		return (chdir(serv_env->home));
	}
	else if (ft_strequ(serv_env->cmd[1], "-"))
	{
		serv_env->old_pwd = serv_env->pwd;
		serv_env->pwd = ft_strdup(getcwd(buf, PATH_MAX));
		return (chdir(serv_env->old_pwd));
	}
	return (get_to_path(serv_env->cmd[1], buf, serv_env));
}
