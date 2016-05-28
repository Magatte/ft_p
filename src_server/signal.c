/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pba <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/27 00:10:39 by pba               #+#    #+#             */
/*   Updated: 2016/05/28 08:59:04 by pba              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"

static void				sig_handle(int sig_no)
{
	if (sig_no == SIGALRM)
	{
		ft_putstr_fd("server [", 2);
		ft_putstr_green_fd("online", 2);
		ft_putstr_fd("]\n", 2);
	}
	else if (sig_no == SIGINT)
	{
		ft_putstr_fd("\rserver [", 2);
		ft_putstr_red_fd("offline", 2);
		ft_putstr_fd("]", 2);
		g_env->result.code_return = -2;
		notify_send(g_env->cs, &g_env->result);
		exit(1);
	}
}

void					ftp_signal()
{
	int					sig_no;

	sig_no = 0;
	while (sig_no <= 31)
	{
		if (sig_no == SIGALRM || sig_no == SIGINT)
			signal(sig_no, &sig_handle);
		++sig_no;
	}
}
