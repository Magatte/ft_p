/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inter.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pba <pba@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/29 08:52:30 by pba               #+#    #+#             */
/*   Updated: 2015/05/08 05:00:56 by pba              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void		ft_putchar(char c)
{
	write(1, &c, 1);
}

int			is_first(char *str, char c, int len)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			break ;
		++i;
	}
	if (i == len)
		return (1);
	return (0);
}

int			is_instring(char *str, char c)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		++i;
	}
	return (0);
}

void		inter(char *str, char *str2)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (is_instring(str2, str[i]) & is_first(str, str[i], i))
			ft_putchar(str[i]);
		++i;
	}
}
