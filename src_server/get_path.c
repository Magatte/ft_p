/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pba <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/20 16:54:40 by pba               #+#    #+#             */
/*   Updated: 2015/11/02 03:22:01 by pba              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"

/*
** After checking we copy the path and return an array of string pointers.
*/

char			**get_path(char **env)
{
	char		**path;
	int			i;

	path = NULL;
	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) != 0 || ft_strlen(env[i]) <= 5)
			i++;
		else
		{
			path = ft_strsplit(env[i], '=');
			break ;
		}
	}
	if (path)
		path++;;
	return ((path) ? ft_strsplit(*path, ':') : NULL);
}
