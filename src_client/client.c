/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pba <pba@42.fr>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/22 00:07:43 by pba               #+#    #+#             */
/*   Updated: 2016/05/08 18:02:48 by pba              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"

void					usage(char *str)
{
	printf("Usage : %s <addr> <port>\n", str);
	exit(-1);
}

int						main(int ac, char **av)
{
	char				*line;
	int					port;
	int					sock;

	if (ac != 3)
		usage(av[0]);
	port = ft_atoi(av[2]);
	sock = create_client(av[1], port);
	ft_putstr_green_fd("(^_^) ", 1);
	line = NULL;
	while (get_next_line(0, &line) > 0)
	{
		ft_putstr_green_fd("(^_^) ", 0);
		if (send(sock, line, sizeof(line), 0) == -1)
			break ;
	}
	close(sock);
	return (0);
}
