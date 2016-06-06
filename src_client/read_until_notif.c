/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_until_notif.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pba <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/01 22:54:19 by pba               #+#    #+#             */
/*   Updated: 2016/06/05 07:01:58 by pba              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"

/*
** when I don't know the size of i have to read from the socket
** (for instance when execve is called) I wait for a code sent by the server
** that tells me I can stop reading from the socket.
** the code = 256 x 0
*/

t_result				*read_until_notif(int socket_read, int socket_write)
{
	char				code[CODESIZE];
	static t_result		result;
	char				*p;
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
