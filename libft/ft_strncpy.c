/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pba <pba@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/25 18:05:54 by pba               #+#    #+#             */
/*   Updated: 2014/12/12 23:21:09 by pba              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char		*ft_strncpy(char *dst, const char *src, size_t n)
{
	char *my_dst;
	char *last;

	my_dst = dst;
	last = dst + n;
	while (n-- && *src)
	{
		*my_dst = *src;
		++my_dst;
		++src;
	}
	while (my_dst != last)
	{
		*my_dst = '\0';
		++my_dst;
	}
	return (dst);
}
