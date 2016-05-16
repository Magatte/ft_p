/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   notify_send.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pba <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/15 23:46:37 by pba               #+#    #+#             */
/*   Updated: 2016/05/15 23:46:53 by pba              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"

void	notify_send(int socket, t_result *result)
{
	unsigned char	c;
	size_t			n;

	n = CODESIZE;
	c = CODEITEM;
	while (n--)
		write(socket, &c, 1);
	write(socket, result, sizeof(result));
}
