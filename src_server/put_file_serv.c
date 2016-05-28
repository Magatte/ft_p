/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_file_serv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pba <pba@42.fr>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 04:34:41 by pba               #+#    #+#             */
/*   Updated: 2016/05/27 03:12:33 by pba              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"

/*
**
*/

int					create_file(char *file_name)
{
	int				fd;

	if ((fd = open(file_name, O_RDWR | O_APPEND | O_CREAT,
					S_IRUSR | S_IWUSR)) == -1)
	{
		perror("Error: ");
		return (0);
	}
	return (fd);
}

void					write_progress(t_env *serv_env, int r)
{
	int					percent;
	int					i;
	int					n;
	static int			sum = 0;

	dup2(serv_env->cs, 2);
	sum += r; 
	percent = sum / serv_env->transf.size * 100;
	i = 0;
	while (i <= percent)
	{
		n = 0;
		ft_putchar_fd('\r', 2);
		while (n++ < i)
		{
			if (i > 99)
				ft_putstr_fd("\e[102m ", 2);
			else
				ft_putstr_fd("\e[101m ", 2);
		}
		ft_putstr_fd("\e[49m", 2);
		ft_putnbr_fd(i, 2);
		ft_putstr_fd("%", 2);
		++i;
	}
}

static void			write_file(t_env *serv_env, int fd)
{
	int				n;
	int				r;
	int				buf[USHRT_MAX + 1];

	n = serv_env->transf.size / USHRT_MAX + 1;
	while (n--)
	{
		ft_memset((void *)buf, 0, USHRT_MAX);
		r = recv(serv_env->cs, buf, USHRT_MAX, 0);
		write_progress(serv_env, r);
		write(fd, buf, r);
	}
	dup2(serv_env->cs, 2);
	ft_putchar_fd('\n', 2);
}

int					put_file_serv(t_env *serv_env)
{
	int				fd;

	read(serv_env->cs, &serv_env->transf, sizeof(serv_env->transf)); 
	if (!ft_strequ(serv_env->transf.msg, "[put_file_OK]"))
	{
		ft_putstr_red_fd("[put_file_ERROR]", 2);
		ft_putchar_fd('\n', 2);
		return (0);
	}
	ft_putstr_blue_fd(serv_env->transf.msg, 2);
	ft_putchar_fd('\n', 2);
	if (!(fd = create_file(serv_env->transf.f_name)))
		return (0);
	write_file(serv_env, fd);
	close(fd);
	return(1);
}
