/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   epur_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pba <pba@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/23 16:30:40 by pba               #+#    #+#             */
/*   Updated: 2015/05/08 04:34:06 by pba              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*hard_start(char *str)
{
	while (*str)
	{
		if (*str == ' ' || *str == '\t')
			str++;
		else
			break ;
	}
	return (str);
}

void			start(char *str, int *i)
{
	while (str[*i])
	{
		if (str[*i] == ' ' || str[*i] == '\t')
			(*i)++;
		else
			break ;
	}
}

char			*epur_str(char *str)
{
	char		*dest;
	int			i;
	int			j;

	if ((dest = (char*)malloc(sizeof(char) * ft_strlen(str) + 1)))
	{
		str = hard_start(str);
		i = 0;
		j = 0;
		while (str[i])
		{
			if (str[i] == '\t' || str[i] == ' ')
			{
				dest[j++] = ' ';
				start(str, &i);
				dest[j] = str[--i];
			}
			else
				dest[j++] = str[i];
			i++;
		}
		dest[j] = '\0';
	}
	return (dest);
}
