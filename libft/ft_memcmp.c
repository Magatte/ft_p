/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pba <pba@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/28 16:36:35 by pba               #+#    #+#             */
/*   Updated: 2014/12/12 00:46:30 by pba              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "libft.h"

int			ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char *my_s1;
	const unsigned char *my_s2;

	my_s1 = s1;
	my_s2 = s2;
	while (n--)
	{
		if (*my_s1 != *my_s2)
			return (*my_s1 < *my_s2 ? -1 : 1);
		++my_s1;
		++my_s2;
	}
	return (0);
}
