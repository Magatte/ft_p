/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pba <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/21 20:22:33 by pba               #+#    #+#             */
/*   Updated: 2016/05/28 02:37:48 by pba              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"

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

static int				init_transfer(t_transfer *transf,
							int sock, char **cmd, int *fd)
{
	struct stat 	stat;

	if ((*fd = check_error(sock, cmd)) == 0)
	{
		ft_strcpy(transf->msg, "[put_file_ER]");
		return (0);
	}
	transf->transfer = 1;
	ft_memset((void *)transf->f_name, 0, 256);
	ft_memset((void *)transf->msg, 0, 13);
	fstat(*fd, &stat);
	transf->size = stat.st_size;
	if (cmd && cmd[1] && ft_strlen(cmd[1]) < 256)
		ft_strcpy(transf->f_name, cmd[1]);
	if (transf->transfer == 1)
		ft_strcpy(transf->msg, "[put_file_OK]");
	else
		ft_strcpy(transf->msg, "[get_file_OK]");
	return (1);
}

int					put_file(int sock, char **cmd)
{
	int				fd;
	int				n;
	int				r;
	t_transfer		transf;
	int				buf[USHRT_MAX];

	if (init_transfer(&transf, sock, cmd, &fd) == 0)
	{
		send(sock, &transf, sizeof(transf), 0);
		return (0);
	}
	if (send(sock, &transf, sizeof(transf), 0) == -1)
		return (0);
	n = transf.size / USHRT_MAX + 1;
	while (n--)
	{
		ft_memset((void *)buf, 0, USHRT_MAX);
		r = read(fd, buf, USHRT_MAX);
		send(sock, buf, r, 0);
	}
	return (1);
}
