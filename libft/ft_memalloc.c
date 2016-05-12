/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pba <pba@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/29 19:54:40 by pba               #+#    #+#             */
/*   Updated: 2014/12/27 08:48:05 by pba              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void		*ft_memalloc(size_t size)
{
	char *s;
	char *my_s;

	s = (char*)malloc(size);
	if (s != NULL)
	{
		my_s = s;
		while (size--)
		{
			*my_s = 0;
			++my_s;
		}
	}
	return (s);
}
