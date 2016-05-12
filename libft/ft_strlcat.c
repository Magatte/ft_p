/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pba <pba@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/27 00:48:16 by pba               #+#    #+#             */
/*   Updated: 2014/11/27 16:56:08 by pba              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t len;
	size_t add_max;

	i = 0;
	while (dst[i] != '\0' && i < size)
		++i;
	len = i + ft_strlen(src);
	add_max = size - i - 1;
	if (i != size)
	{
		dst += i;
		i = 0;
		while (src[i] != '\0' && i < add_max)
		{
			dst[i] = src[i];
			++i;
		}
		dst[i] = '\0';
	}
	return (len);
}
