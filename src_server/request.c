/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   requestc                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pba <pba@42.fr>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/05 13:48:57 by pba               #+#    #+#             */
/*   Updated: 2016/06/05 05:03:37 by pba              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"

/*
** concerning the server there's a father socket that accepts connection.
** for each new client that asks for connection a new son socket is created
** and a new processus (fork) too for that new client.
*/

static int					new_client(t_env *serv_env, char *buf)
{
	int						r;
	pid_t					pid;

	pid = fork();
	if (pid > 0)
		wait4(0, NULL, WNOHANG, NULL);
	if (pid == 0)
	{
		ft_memset((void *)buf, 0, PATH_MAX);
		while ((r = recv(serv_env->cs, buf, PATH_MAX, 0)) > 0)
		{
			if (buf[r - 1] == '$')
				serv_env->result.client = 1;
			buf[r - serv_env->result.client] = '\0';
			parser(serv_env, buf);
			ft_memset((void *)buf, 0, PATH_MAX);
		}
		close(serv_env->cs);
		return (0);
	}
	return (1);
}

void						request(t_env *serv_env, int sock, char *buf)
{
	int						cs;
	unsigned int			cslen;
	struct sockaddr_in		csin;

	while ((cs = accept(sock, (struct sockaddr*)&csin, &cslen)) != -1)
	{
		serv_env->cs = cs;
		ft_putstr_blue_fd("Client [", 1);
		ft_putnbr_fd(cs, 1);
		ft_putstr_blue_fd("] connected\n", 1);
		new_client(serv_env, buf);
	}
}
