/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pba <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/29 01:55:54 by pba               #+#    #+#             */
/*   Updated: 2016/01/29 02:02:31 by pba              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			**make_map(int dim)
{
	char		**map;
	int			i;

	if ((map = (char **)malloc(sizeof(char *) * (dim + 1))))
	{
		map[dim] = NULL;
		i = 0;
		while (i < dim)
		{
			if ((map[i] = (char *)malloc(sizeof(char) * (dim + 1))))
				map[i][dim] = '\0';
			++i;
		}
	}
	return (map);
}
