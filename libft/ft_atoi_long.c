/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_long.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pba <pba@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/28 20:34:00 by pba               #+#    #+#             */
/*   Updated: 2016/02/07 23:30:45 by pba              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void			special_cases(const char **s, int *length, int *signs)
{
	while (**s == ' ' || **s == '\t' || **s == '\n' || **s == '\v'
			|| **s == '\r' || **s == '\f')
	{
		(*s)++;
		(*length)--;
	}
	if (**s == '+' || **s == '-')
	{
		if (**s == '-')
			*signs = -1;
		(*s)++;
		(*length)--;
	}
}

long				ft_atoi_long(const char *str)
{
	int				len;
	long			nb;
	int				sign;
	int				done;

	len = ft_strlen(str) + 1;
	nb = 0;
	sign = 1;
	done = 0;
	special_cases(&str, &len, &sign);
	while (--len)
	{
		if (*str < '0' || *str > '9')
		{
			if (done == 0)
				return (0);
			else
				break ;
		}
		nb *= 10;
		nb = nb + (*str++ - '0');
		done = 1;
	}
	return (sign * nb);
}
