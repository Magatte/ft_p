/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pba <pba@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/22 21:14:40 by pba               #+#    #+#             */
/*   Updated: 2016/02/26 10:12:52 by pba              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void		*ft_realloc(void *ptr, size_t size)
{
	char	*str;
	char	*my_str;
	int		len;

	str = NULL;
	len = ft_strlen((char *)ptr);
	str = (char *)malloc((sizeof(*ptr) + 1) * len + size);
	if (str == NULL)
		return (NULL);
	str[len + size] = '\0';
	my_str = str;
	while (len--)
	{
		*my_str = *((char *)ptr);
		++my_str;
		++ptr;
	}
	bzero(my_str, size);
	return (str);
}
