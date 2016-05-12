/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pba <pba@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/28 04:16:48 by pba               #+#    #+#             */
/*   Updated: 2014/12/11 06:49:55 by pba              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	while (n--)
	{
		*((char*)dst) = *((char*)src);
		if (*(unsigned char*)src == (unsigned char)c)
			return (++dst);
		++dst;
		++src;
	}
	return (NULL);
}
