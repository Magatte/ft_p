/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_lines.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pba <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/26 17:21:40 by pba               #+#    #+#             */
/*   Updated: 2016/04/06 04:21:20 by pba              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			**push_line(char **str, char *line)
{
	int			len;
	char		**tmp;
	int			i;

	len = count_words(str) + 1;
	tmp = str;
	if (!(str = (char **)malloc(sizeof(char *) * (len + 1))))
		return (NULL);
	str[len] = NULL;
	i = 0;
	while (i < len - 1 && tmp)
	{
		str[i] = ft_strdup(tmp[i]);
		++i;
	}
	str[i] = ft_strdup(line);
	free(tmp);
	return (str);
}
