/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pba <pba@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/09/02 17:15:04 by pba               #+#    #+#             */
/*   Updated: 2016/01/30 14:16:12 by pba              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_square(int nb)
{
	return (nb * nb);
}

int		ft_sqrt(int nb)
{
	int sqrt;

	sqrt = 0;
	while (sqrt <= nb)
	{
		if (ft_square(sqrt) == nb)
			return (sqrt);
		else if (ft_square(sqrt) > nb)
			break ;
		++sqrt;
	}
	return (sqrt - 1);
}
