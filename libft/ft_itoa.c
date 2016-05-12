/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pba <pba@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/05 17:53:56 by pba               #+#    #+#             */
/*   Updated: 2015/05/08 04:52:10 by pba              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

int			ft_count(int n)
{
	int		i;

	i = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n /= 10;
		++i;
	}
	return (i);
}

char		*limits(int n)
{
	if (n == INT_MIN)
		return ("-2147483648");
	else
		return ("0");
}

char		*ft_itoa(int n)
{
	int		len;
	char	*str;

	len = ft_count(n);
	if (n == INT_MIN || n == 0)
		return (limits(n));
	if (n >= 0)
	{
		if ((str = (char*)malloc(sizeof(char) * (len + 1))) == NULL)
			return (NULL);
	}
	else
	{
		if ((str = (char*)malloc(sizeof(char) * (++len + 1))) == NULL)
			return (NULL);
		*str = '-';
		n = -n;
	}
	str[len--] = '\0';
	while (n != 0)
	{
		str[len--] = (n % 10) + '0';
		n /= 10;
	}
	return (str);
}
