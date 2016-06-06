/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_server.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pba <pba@42.fr>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/05 14:08:18 by pba               #+#    #+#             */
/*   Updated: 2016/06/05 11:40:25 by pba              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"

/*
** Socket is a corner stone concept when a client is communicating with a server
** A network socket is an endpoint of a connection across a computer network
** Currently most sockets are internet sockets, based on IP communication
** Steps to create a server :
** 1- we use getaddrinfo to fill in hints the specification of our socket.
** 2- with the info of hints getaddrinfo fill in the res structure.
** getaddrinfo() allocates and initializes t_addrinfo linked list
** 3- we loop in &res, bind (to an internet address) and listen in each.
** listen is a syscall that sets the number of clients a server can
** simultaneously handle (the size of the queue).
** specifications :
** AI_PASSIVE + node == NULL => an address that binds
** an connection accepting socket
** AF_INET6 => getaddrinfo() IPV6 family address
** SOCK_STREAM => stream socket != SOCK_DGRAM
*/

static int				loop_server(t_addrinfo *res)
{
	t_addrinfo			*tmp;
	int					sock;

	tmp = res;
	while (tmp)
	{
		if ((sock = socket(tmp->ai_family,
					tmp->ai_socktype, tmp->ai_protocol)) >= 0)
		{
			if (!bind(sock, tmp->ai_addr, tmp->ai_addrlen) && !listen(sock, 42))
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

int						create_server(char *port)
{
	t_addrinfo			hints;
	t_addrinfo			*res;
	t_protoent			*proto;
	int					sock;

	if (!(proto = getprotobyname("tcp")))
		return (-1);
	ft_memset((void *)&hints, 0, sizeof(hints));
	hints.ai_flags = AI_PASSIVE;
	hints.ai_family = AF_INET6;
	hints.ai_socktype = SOCK_STREAM;
	hints.ai_protocol = proto->p_proto;
	if (getaddrinfo(NULL, port, &hints, &res) != 0)
		return (-1);
	sock = loop_server(res);
	if (sock != -1)
		return (sock);
	printf("Bind error\n");
	return (-1);
}
