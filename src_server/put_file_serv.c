/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_file_serv.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pba <pba@42.fr>                            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/18 04:34:41 by pba               #+#    #+#             */
/*   Updated: 2016/05/22 18:39:13 by pba              ###   ########.fr       */
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

static void			read_until_notify(int socket_read, int socket_write)
{
	char			code[CODESIZE];
	char			*p;
	char			c;
	
	CODE_INIT(p, code, CODESIZE);
	while (read(socket_read, &c, 1) > 0)
	{
		if (c == CODEITEM)
		{
			*p++ = c;
			if ((p - code) == CODESIZE)
				break;
		}
		else
		{
			write(socket_write, code, p - code);
			CODE_INIT(p, code, CODESIZE);
			write(socket_write, &c, 1);
		}
	}
}

int					put_file_serv(t_env *serv_env)
{
	int				fd;
	char			buf[USHRT_MAX];
	int				r;

	ft_memset((void *)buf, 0, USHRT_MAX);
	while ((r = recv(serv_env->cs, buf, 13, 0)))
	{
		if (ft_strequ(buf, "[put_file_ER]"))
		{
			ft_putstr_red_fd("[put_file_ERROR]", 2);
			ft_putchar_fd('\n', 2);
			return (0);
		}
		else if (ft_strequ(buf, "[put_file_OK]"))
			break ;
	}
	ft_putstr_blue_fd(buf, 2);
	ft_putchar_fd('\n', 2);
	if (!(fd = create_file(serv_env->cmd[1])))
		return (0);
	read_until_notify(serv_env->cs, fd);
	close(fd);
	return(1);
}
