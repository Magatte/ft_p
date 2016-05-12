/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pba <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/31 20:44:17 by pba               #+#    #+#             */
/*   Updated: 2015/11/02 01:48:04 by pba              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The aim of this function is to calculate the number of arguments
*/

int				args(char **comd)
{
	int			i;

	i = 0;
	while (comd[i])
		i++;
	return (i - 1);
}
