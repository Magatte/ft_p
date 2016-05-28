/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pba <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/27 00:10:39 by pba               #+#    #+#             */
/*   Updated: 2016/05/28 14:39:50 by pba              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"

static void				sig_handle(int sig_no)
{
	t_result			result;

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
		ft_putstr_red_fd("\nftp : connection off\n", 2);
		exit(-2);
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
