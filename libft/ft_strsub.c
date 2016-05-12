/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pba <pba@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/01 17:45:13 by pba               #+#    #+#             */
/*   Updated: 2015/01/10 12:01:32 by pba              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*s2;

	s2 = (char *)malloc(len + 1);
	if (s2 != NULL)
	{
		ft_strncpy(s2, s + start, len);
		s2[len] = '\0';
	}
	return (s2);
}
