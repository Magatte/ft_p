/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pba <pba@42.fr>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/19 01:45:52 by pba               #+#    #+#             */
/*   Updated: 2016/05/10 03:24:58 by pba              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"

/*
**
*/

void					usage(char *str)
{
	printf("Usage: %s <port>\n", str);
	exit(-1);
}

int						main(int ac, char **av, char **env)
{
	int					port;
	int					sock;
	char				buf[1024];
	t_env				*serv_env;

	if (ac != 2)
		usage(av[0]);
	port = ft_atoi(av[1]);
	sock = create_server(port);
	serv_env = init_env(env);
	request(serv_env, sock, buf);
	close(sock);
	return (0);
}
