/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pba <pba@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/26 16:31:39 by pba               #+#    #+#             */
/*   Updated: 2015/02/10 03:36:39 by pba              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t j;
	size_t i;

	i = 0;
	if (s2[0] == 0)
		return ((char*)s1);
	while (i <= n && s1[i] != '\0')
	{
		j = 0;
		while (s2[j] == s1[i + j] && s1[i + j])
			++j;
		if (i + j > n)
			return (NULL);
		if (s2[j] == '\0')
			return ((char*)s1 + i);
		++i;
	}
	return (NULL);
}
