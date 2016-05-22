/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pba <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/21 20:22:33 by pba               #+#    #+#             */
/*   Updated: 2016/05/22 18:24:37 by pba              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"

static void			notify_put(int socket)
{
	unsigned char	c;
	size_t			n;

	n = CODESIZE;
	c = CODEITEM;
	while (n--)
		write(socket, &c, 1);
}

static int			check_error(int sock, char **cmd)
{
	int				fd;

	(void)sock;
	if (cmd[1] == NULL)
		return (0);
	if ((fd = open(cmd[1], O_RDONLY)) == -1)
		return (0);
	return (fd);
}

int					put_file(int sock, char **cmd)
{
	int				fd;
	int				n;
	int				r;
	struct stat stat;
	char		buf[USHRT_MAX];

	if ((fd = check_error(sock, cmd)) == 0)
	{
		send(sock, "[put_file_ER]", 16, 0);
		notify_put(sock);
		return (0);
	}
	send(sock, "[put_file_OK]", 13, 0);
	fstat(fd, &stat);
	n = stat.st_size / USHRT_MAX + 1;
	while (n--)
	{
		ft_memset((void *)buf, 0, USHRT_MAX);
		r = read(fd, buf, USHRT_MAX);
		send(sock, buf, r, 0);
	}
	notify_put(sock);
	return (1);
}
