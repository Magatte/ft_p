/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pba <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/18 09:42:54 by pba               #+#    #+#             */
/*   Updated: 2016/05/04 03:24:46 by pba              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				is_number(char *str)
{
	int			i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '-' && i == 0 && str[0] != 48)
			++i;
		if (!(ft_isdigit(str[i])))
			return (0);
		++i;
	}
	return (1);
}

int				check_overflow(char *str)
{
	int			sign;

	sign = 1;
	if (str[0] == '-')
	{
		sign = -1;
		++str;
	}
	if (ft_strlen(str) > 10)
		return (1);
	if (ft_strlen(str) == 10)
	{
		if (ft_atoi_long(str) * sign > INT_MAX
				|| ft_atoi_long(str) * sign < INT_MIN)
			return (1);
	}
	return (0);
}

int				ft_isint(char *str)
{
	if (!(is_number(str)))
		return (0);
	if ((check_overflow(str)))
		return (0);
	return (1);
}
