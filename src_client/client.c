/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pba <pba@42.fr>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/22 00:07:43 by pba               #+#    #+#             */
/*   Updated: 2016/05/16 03:00:46 by pba              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"

static void				usage(char *str)
{
	printf("Usage : %s <addr> <port>\n", str);
	exit(-1);
}

static char 			*ft_prompt(void)
{
	char 				*line;

	ft_putstr_green_fd("(^_^) ", 0);
	if (get_next_line(0, &line) <= 0)
		line = NULL;
	return (line);
}

static t_result			*read_until_notif(int socket_read, int socket_write)
{
	static char 		code[CODESIZE];
	static t_result		result;
	char 				*p;
	char				c;

	CODE_INIT(p, code, CODESIZE);
	ft_bzero((void *)&result, sizeof(result));
	while (read(socket_read, &c, 1) > 0)
	{
		if (c == CODEITEM)
		{
			*p++ = c;
			if ((p - code) == CODESIZE)
				break ;
		}
		else
		{
			write(socket_write, code, p - code);
			CODE_INIT(p, code, CODESIZE);
			write(socket_write, &c, 1);
		}
	}
	read(socket_read, &result, sizeof(result));
	return (&result);
}

int						main(int ac, char **av)
{
	t_result			*result;
	int					port;
	int					sock;
	char				*line;

	if (ac != 3)
		usage(av[0]);
	port = ft_atoi(av[2]);
	sock = create_client(av[1], port);
	while ((line = ft_prompt()) != NULL)
	{
		if (send(sock, line, sizeof(line), 0) == -1)
			break;
		result = read_until_notif(sock, 1);
	}
	close(sock);
	return (0);
}
