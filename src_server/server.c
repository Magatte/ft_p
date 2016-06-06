/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pba <pba@42.fr>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/08/19 01:45:52 by pba               #+#    #+#             */
/*   Updated: 2016/06/05 12:43:50 by pba              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"

/*
** 1- create a server socket.
** 2- make it wait for connection (request).
** 3- close the socket when all's finished.
*/

t_env					*g_env;

static void				usage(char *str)
{
	printf("Usage: %s <port>\n", str);
	exit(-1);
}

int						main(int ac, char **av, char **env)
{
	int					sock;
	char				buf[PATH_MAX];
	t_env				*serv_env;

	if (ac != 2)
		usage(av[0]);
	if ((sock = create_server(av[1])) == -1)
		exit(-1);
	if ((serv_env = init_env(env)) == NULL)
	{
		ft_putstr_fd("error : attempt to connect the server failed.", 2);
		return (0);
	}
	ftp_signal();
	ftp_ping();
	g_env = serv_env;
	ft_putstr_green_fd("Server connected\n", 2);
	request(serv_env, sock, buf);
	free(serv_env->home);
	free(serv_env);
	close(sock);
	return (0);
}
