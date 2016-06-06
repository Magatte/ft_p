/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftp_ping.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pba <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/27 00:33:31 by pba               #+#    #+#             */
/*   Updated: 2016/06/05 06:55:50 by pba              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"

/*
** setitimer sets the interval time used to trigger SIGALRM.
** every 5 seconds SIGALRM is triggered.
*/

void					ftp_ping(void)
{
	struct itimerval	it_val;

	it_val.it_value.tv_sec = INTERVAL / 100;
	it_val.it_value.tv_usec = (INTERVAL * 100) % 100000;
	it_val.it_interval = it_val.it_value;
	if (setitimer(ITIMER_REAL, &it_val, NULL) == -1)
	{
		perror("error calling setitimer()");
		exit(1);
	}
}
