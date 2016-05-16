/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   requestc                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pba <pba@42.fr>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/05 13:48:57 by pba               #+#    #+#             */
/*   Updated: 2016/05/12 18:30:57 by pba              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"

static int					new_client(t_env *serv_env, char *buf)
{
	int						r;
	int						child_exit_status;
	pid_t					pid;

	pid = fork();
	if (pid > 0)
		wait(&child_exit_status);
	if (pid == 0)
	{
		while ((r = recv(serv_env->cs, buf, sizeof(buf), 0)) > 0)
		{
			buf[r] = '\0';
			parser(serv_env, buf);
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
		new_client(serv_env, buf);
	}
}
