/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_file_serv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pba <pba@42.fr>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 04:34:41 by pba               #+#    #+#             */
/*   Updated: 2016/06/05 06:55:35 by pba              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"

/*
** put_dile_serv waits receives the transfer structure
** it displays the result message
** if the result message is OK it begins copying what it receives from the
** socket into a new file.
*/

static void				write_progress(t_env *serv_env, int r)
{
	unsigned int		percent;
	unsigned int		i;
	static int			putsum = 0;

	putsum += r;
	percent = putsum * 100;
	percent /= serv_env->transf.size;
	ft_putchar_fd('\r', serv_env->cs);
	i = 0;
	while (i <= percent)
	{
		if (percent > 99)
			ft_putstr_fd("\e[102m ", serv_env->cs);
		else
			ft_putstr_fd("\e[101m ", serv_env->cs);
		++i;
	}
	if (--i >= 100)
		putsum = 0;
}

static void				progress_empty(t_env *serv_env)
{
	int					i;

	i = 0;
	while (i++ < 100)
		ft_putstr_fd("\e[102m ", serv_env->cs);
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
		if (r == 0)
			break ;
	}
	return (r);
}

static void				write_file(t_env *serv_env, int fd, int empty_file)
{
	int					n;
	int					r;
	int					size;
	int					buf[USHRT_MAX];

	n = serv_env->transf.size / USHRT_MAX + 1;
	while (n-- && !empty_file)
	{
		if (n > 0)
			size = USHRT_MAX;
		else
			size = (serv_env->transf.size > USHRT_MAX) ?
				serv_env->transf.size % USHRT_MAX : serv_env->transf.size;
		ft_memset((void *)buf, 0, USHRT_MAX);
		r = read_until_max(serv_env->cs, buf, size);
		write_progress(serv_env, r);
		write(fd, buf, r);
	}
	if (empty_file)
		progress_empty(serv_env);
	ft_putstr_fd("\e[49m", serv_env->cs);
	ft_putnbr_fd(100, serv_env->cs);
	ft_putstr_fd("%\n", serv_env->cs);
}

int						put_file_serv(t_env *serv_env)
{
	int					fd;
	int					empty_file;

	if (serv_env->result.client != 1)
		return (0);
	empty_file = 0;
	if (recv(serv_env->cs, &serv_env->transf,
				sizeof(serv_env->transf), 0) == -1)
		return (0);
	if (!ft_strequ(serv_env->transf.msg, "[put_file_OK]"))
	{
		ft_putstr_red_fd("[put_file_ERROR]\n", 1);
		return (0);
	}
	ft_putstr_blue_fd(serv_env->transf.msg, 1);
	ft_putchar_fd('\n', 1);
	if (!(fd = create_file(serv_env->transf.f_name)))
		return (0);
	if (serv_env->transf.size == 0)
		empty_file = 1;
	write_file(serv_env, fd, empty_file);
	close(fd);
	return (1);
}
