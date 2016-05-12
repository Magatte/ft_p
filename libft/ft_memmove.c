/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pba <pba@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/28 05:35:57 by pba               #+#    #+#             */
/*   Updated: 2015/01/10 11:46:51 by pba              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

void		*ft_memmove(void *dst, const void *src, size_t len)
{
	char *my_dst;

	my_dst = dst;
	if ((const char*)src <= my_dst)
	{
		my_dst += len - 1;
		src += len - 1;
		while (len--)
			*my_dst-- = *(const char*)src--;
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
