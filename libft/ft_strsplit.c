/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pba <pba@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/03 14:29:28 by pba               #+#    #+#             */
/*   Updated: 2016/03/18 16:44:19 by pba              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_count_words(const char *s, char c)
{
	int			count_words;
	int			signal;

	count_words = 0;
	signal = 0;
	while (*s)
	{
		if (*s == c && signal == 1)
			signal = 0;
		if (signal == 0 && *s != c)
		{
			++count_words;
			signal = 1;
		}
		++s;
	}
	return (count_words);
}

static int		ft_word_len(const char *s, char c)
{
	int			len;

	len = 0;
	while (*s != c && *s != '\0')
	{
		++len;
		++s;
	}
	return (len);
}

char			**ft_strsplit(char *s, char c)
{
	char		**t;
	int			nb_word;
	int			i;

	i = 0;
	s = epur_str((char*)s);
	nb_word = ft_count_words((const char*)s, c);
	t = (char **)malloc(sizeof(*t) * (nb_word + 1));
	while (nb_word--)
	{
		while (*s == c && *s != '\0')
			++s;
		t[i] = ft_strsub((const char*)s, 0,
				ft_word_len((const char *)s, c));
		if (t[i] == NULL)
			return (NULL);
		s = s + ft_word_len(s, c);
		++i;
	}
	t[i] = NULL;
	return (t);
}
