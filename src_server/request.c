/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   requestc                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pba <pba@42.fr>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/05 13:48:57 by pba               #+#    #+#             */
/*   Updated: 2016/05/28 03:24:56 by pba              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"

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
			buf[r] = '\0';
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
		ft_putstr_blue_fd("Client [", 2);
		ft_putnbr_fd(cs, 2);
		ft_putstr_blue_fd("] connected\n", 2);
		new_client(serv_env, buf);
	}
}
