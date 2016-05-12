/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pba <pba@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/01 15:54:27 by pba               #+#    #+#             */
/*   Updated: 2015/02/25 04:06:17 by pba              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		len;
	int		count;
	char	*new_str;

	if (s == NULL)
		return (NULL);
	if (f == NULL)
		return (strdup(s));
	len = ft_strlen(s);
	new_str = ft_strnew(len);
	count = 0;
	while (len--)
	{
		new_str[count] = f(count, s[count]);
		++count;
	}
	return (new_str);
}
