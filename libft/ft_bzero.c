/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pba <pba@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/27 17:57:31 by pba               #+#    #+#             */
/*   Updated: 2015/01/07 00:02:26 by pba              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void		ft_bzero(void *s, size_t n)
{
	char *my_s;

	my_s = s;
	while (n--)
	{
		*((char*)my_s) = 0;
		++my_s;
	}
}
