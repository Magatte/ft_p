/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pba <pba@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/27 18:25:53 by pba               #+#    #+#             */
/*   Updated: 2015/05/15 11:57:38 by pba              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void		*ft_memcpy(void *dst, const void *src, size_t n)
{
	char *my_dst;

	my_dst = dst;
	while (n--)
		*(my_dst++) = *((char*)(src++));
	return (dst);
}
