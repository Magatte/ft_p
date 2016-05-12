/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pba <pba@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/25 01:01:34 by pba               #+#    #+#             */
/*   Updated: 2014/12/12 01:21:18 by pba              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

char		*ft_strcpy(char *dst, const char *src)
{
	char *my_dst;

	my_dst = dst;
	while (*src)
	{
		*my_dst = *src;
		++my_dst;
		++src;
	}
	*my_dst = '\0';
	return (dst);
}
