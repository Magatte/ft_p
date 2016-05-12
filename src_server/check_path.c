/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pba <pba@42.fr>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/26 21:38:59 by pba               #+#    #+#             */
/*   Updated: 2016/05/05 13:06:23 by pba              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"

/*
** The check_path fonction checks wether the path does exist or not
*/

int				check_path(char **env)
{
	int			i;
	int			signal;

	signal = 0;
	i = 0;
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) != 0 || ft_strlen(env[i]) <= 5)
			i++;
		else
		{
			signal = 1;
			break ;
		}
	}
	return (signal);
}
