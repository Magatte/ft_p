/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pba <pba@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/02 21:20:31 by pba               #+#    #+#             */
/*   Updated: 2016/02/08 04:21:35 by pba              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	size_t		len;
	char		*my_s1;
	char		*my_s2;

	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	my_s1 = ft_memalloc(len);
	my_s2 = my_s1;
	while ((s1 == NULL) ? 0 : *s1)
	{
		*my_s1 = *s1;
		++my_s1;
		++s1;
	}
	while ((s2 == NULL) ? 0 : *s2)
	{
		*my_s1 = *s2;
		++my_s1;
		++s2;
	}
	*my_s1 = '\0';
	return (my_s2);
}
