/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_until_notif.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pba <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 22:54:19 by pba               #+#    #+#             */
/*   Updated: 2016/06/01 22:58:03 by pba              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"

t_result				*read_until_notif(int socket_read, int socket_write)
{
	char				code[CODESIZE];
	static t_result		result;
	char 				*p;
	char				c;

	CODE_INIT(p, code, CODESIZE);
	ft_bzero((void *)&result, sizeof(result));
	while (recv(socket_read, &c, 1, 0) > 0)
	{
		if (c == CODEITEM)
		{
			*p++ = c;
			if ((p - code) == CODESIZE)
				break ;
		}
		else
		{
			write(socket_write, code, p - code);
			CODE_INIT(p, code, CODESIZE);
			write(socket_write, &c, 1);
		}
	}
	recv(socket_read, &result, sizeof(t_result), 0);
	return (&result);
}
