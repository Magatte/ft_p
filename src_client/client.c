/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pba <pba@42.fr>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/22 00:07:43 by pba               #+#    #+#             */
/*   Updated: 2016/06/04 04:15:18 by pba              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"

int						g_sock;

static void				usage(char *str)
{
	printf("Usage : %s <addr> <port>\n", str);
	exit(-1);
}

static char 			*ft_prompt(void)
{
	char 				*line;
	char				*tmp;

	ft_putstr_green_fd("ft_p> ", 0);
	if (get_next_line(0, &line) <= 0)
		line = NULL;
	tmp = line;
	line = ft_strjoin(line, "$");
	free(tmp);
	return (line);
}

static void				quit_if_off(t_result *result)
{
	if (result->code_return == -2)
	{
		ft_putstr_red_fd("ftp : connection off\n", 2);
		exit(1);
	}
}

static void				client(int sock, char *line, char **cmd)
{
	t_result			*result;

	while ((line = ft_prompt()) != NULL)
	{
		if (!ft_strequ(line, "$"))
		{
			if (send(sock, line, ft_strlen(line), 0) == -1)
				break ;
			cmd = ft_strsplit(line, ' ');
			if (cmd && ft_strequ(cmd[0], "put"))
				put_file(sock, cmd);
			else if (cmd && ft_strequ(cmd[0], "get"))
				get_file(sock, cmd);
			quit_if_off((result = read_until_notif(sock, 1)));
		}
		free(line);
	}
}

int						main(int ac, char **av)
{
	int					sock;
	char				*line;
	char				**cmd;

	if (ac != 3)
		usage(av[0]);
	if ((sock = create_client(av[1], av[2])) == -1)
		exit (-1);
	ftp_signal();
	line = NULL;
	cmd = NULL;
	client(sock, line, cmd);
	close(sock);
	return (0);
}
