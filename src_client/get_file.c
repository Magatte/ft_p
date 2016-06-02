/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pba <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 01:16:49 by pba               #+#    #+#             */
/*   Updated: 2016/06/01 22:40:45 by pba              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"

static void				write_progress(int r, int size)
{
	unsigned int		percent;
	unsigned int		i;
	static int			getsum = 0;

	getsum += r;
	percent = getsum * 100; 
	percent /= size;
	ft_putchar_fd('\r', 1);
	i = 0;
	while (i <= percent)
	{
		if (percent > 99)
			ft_putstr_fd("\e[102m ", 1);
		else
			ft_putstr_fd("\e[101m ", 1);
		++i;
	}
	if (--i >= 100)
		getsum = 0;
}

static int				read_until_max(int sock, int *buf, int size)
{
	int					len;
	int					r;

	r = 0;
	while (r < size)
	{
		len = (r == 0) ? 0 : r - 1;
		r += recv(sock, &buf[len], size - r, 0);
	}
	return (r);
}

static void				write_file(int sock, int fd, int size)
{
	int					n;
	int					r;
	int					buf[USHRT_MAX];

	n = size / USHRT_MAX + 1;
	while (n--)
	{
		ft_memset((void *)buf, 0, USHRT_MAX);
		if (n > 0)
			r = read_until_max(sock, buf, USHRT_MAX);
		else
		{
			if (size > USHRT_MAX)
				r = read_until_max(sock, buf, size % USHRT_MAX);
			else
				r = read_until_max(sock, buf, size);
		}
		write_progress(r, size);
		write(fd, buf, r);
	}
	ft_putstr_fd("\e[49m", 1);
	ft_putnbr_fd(100, 1);
	ft_putstr_fd("%\n", 1);
}

int						get_file(int sock, char **cmd)
{
	int					fd;
	int					len;
	t_transfer			transf;

	len = ft_strlen(cmd[1]);
	cmd[1][len -1] = '\0';
	if (recv(sock, &transf, sizeof(t_transfer), 0) == -1)
		return (0);
	if (!ft_strequ(transf.msg, "[get_file_OK]"))
		return (0);
	if ((fd = create_file(cmd[1])) == 0)
		return (0);
	write_file(sock, fd, transf.size);
	close(fd);
	return (1);
}
