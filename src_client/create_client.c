/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_client.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pba <pba@42.fr>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/06 02:21:15 by pba               #+#    #+#             */
/*   Updated: 2016/06/04 00:08:35 by pba              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"

/*
** First thing to do : create a socket
** The second step is to connect our socket to an internet address (like bind)
*/

static int				loop_client(t_addrinfo *res)
{
	t_addrinfo			*tmp;
	int					sock;

	tmp = res;
	while (tmp)
	{
		if ((sock = socket(tmp->ai_family,
						tmp->ai_socktype, tmp->ai_protocol)) >= 0)
		{
			if (!connect(sock, tmp->ai_addr, tmp->ai_addrlen))
			{
				freeaddrinfo(res);
				return (sock);
			}
		}
		close(sock);
		tmp = tmp->ai_next;
	}
	freeaddrinfo(res);
	return (-1);
}

int						create_client(char *addr, char *port)
{
	t_addrinfo			hints;
	t_addrinfo			*res;
	t_protoent			*proto;
	int					sock;

	if (!(proto = getprotobyname("tcp")))
		return (-1);
	ft_memset((void *)&hints, 0, sizeof(hints));
	hints.ai_flags = AI_PASSIVE;
	hints.ai_family = AF_UNSPEC;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_protocol = proto->p_proto;
	if (getaddrinfo(addr, port, &hints, &res) != 0)
		return (-1);
	sock = loop_client(res);
	if (sock != -1)
		return (sock);
	printf("Connect error\n");
	return (-1);
}
