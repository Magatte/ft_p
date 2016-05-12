/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_blue_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pba <pba@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/09 18:44:05 by pba               #+#    #+#             */
/*   Updated: 2016/02/08 09:50:43 by pba              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

void		ft_putnbr_blue_fd(int n, int fd)
{
	if (n == INT_MAX)
	{
		ft_putstr_blue_fd("2147483647", fd);
		return ;
	}
	if (n == INT_MIN)
	{
		ft_putstr_blue_fd("-2147483648", fd);
		return ;
	}
	if (n < 0)
	{
		ft_putchar_blue_fd('-', fd);
		n = -n;
	}
	if (n >= 10)
	{
		ft_putnbr_blue_fd(n / 10, fd);
		ft_putnbr_blue_fd(n % 10, fd);
	}
	else
		ft_putchar_blue_fd(n + '0', fd);
}
