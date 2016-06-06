/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_client.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pba <pba@42.fr>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/06 02:21:15 by pba               #+#    #+#             */
/*   Updated: 2016/06/05 07:00:01 by pba              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"

/*
** Steps to create a client :
** 1- use getaddrinfo to fill the specifications of our socket (hints and res)
** 2- getaddrinfo() allocates and initializes a linked list of client.
** res is the head of the list.
** 3- we loop in &res and connect each socket to an internet address;
** specifications :
** AI_PASSIVE : if node != NULL AI_PASSIVE is ignored
** AF_UNSPEC : getaddrinfo() should return any socket addresses
** that can be use with node and service
** SOCK_STREAM => stream socket != SOCK_DGRAM
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
