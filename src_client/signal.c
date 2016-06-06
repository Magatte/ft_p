/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pba <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/27 00:10:39 by pba               #+#    #+#             */
/*   Updated: 2016/06/05 07:02:26 by pba              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"

/*
** 2 signals are handled : SIGALARM for my ftp_ping
** and SIG_INT for the server to know a client has stopped and kill the process.
*/

static void				sig_handle(int sig_no)
{
	t_result			result;
	char				buf[5];

	if (sig_no == SIGALRM)
	{
		if (result.code_return == -2)
		{
			ft_putstr_red_fd("\nftp : connection off\n", 2);
			exit(-2);
		}
	}
	else if (sig_no == SIGINT)
	{
		ft_memset((void *)buf, 0, 6);
		ft_strcpy(buf, "quit$");
		send(g_sock, buf, 5, 0);
		ft_putstr_red_fd("\nftp : connection off\n", 2);
		exit(-2);
	}
}

void					ftp_signal(void)
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
