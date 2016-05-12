/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pba <pba@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/05 16:11:06 by pba               #+#    #+#             */
/*   Updated: 2015/05/08 05:00:15 by pba              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s)
{
	char	*str;
	int		len;
	int		i;

	while (*s == ' ' || *s == '\n' || *s == '\t')
		++s;
	len = ft_strlen(s);
	if (len == 0)
		++len;
	while (s[len - 1] == ' ' || s[len - 1] == '\n' || s[len - 1] == '\t')
		--len;
	str = (char*)malloc((len + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (len--)
		str[i++] = *s++;
	str[i] = '\0';
	return (str);
}
