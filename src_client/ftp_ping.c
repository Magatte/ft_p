/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_ping.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pba <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/27 00:33:31 by pba               #+#    #+#             */
/*   Updated: 2016/06/05 06:56:15 by pba              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"

/*
** settimer sets the interval time for SIGALRM to be triggered.
*/

void					ftp_ping(void)
{
	struct itimerval	it_val;

	it_val.it_value.tv_sec = INTERVAL / 500;
	it_val.it_value.tv_usec = (INTERVAL * 100) % 50000;
	it_val.it_interval = it_val.it_value;
	if (setitimer(ITIMER_REAL, &it_val, NULL) == -1)
	{
		perror("error when calling setitimer()");
		exit(1);
	}
}
