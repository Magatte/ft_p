/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pba <pba@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/13 17:33:39 by pba               #+#    #+#             */
/*   Updated: 2015/04/30 18:05:26 by pba              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char				*read_buf(int const fd, char *buf, int *ret)
{
	char			tmp[READ_MAX + 1];
	char			*tmpbuf;

	*ret = read(fd, tmp, READ_MAX);
	if (ret == 0)
		return (buf);
	tmp[*ret] = '\0';
	tmpbuf = buf;
	buf = ft_strjoin(buf, tmp);
	ft_strdel(&tmpbuf);
	return (buf);
}

int					get_next_line(int const fd, char **line)
{
	static char		*buf = "";
	int				ret;
	char			*str;

	if (!line || fd < 0)
		return (-1);
	ret = 1;
	if (buf[0] == '\0')
		buf = ft_strnew(0);
	while (ret > 0)
	{
		if ((str = ft_strchr(buf, '\n')))
		{
			*str = '\0';
			*line = ft_strdup(buf);
			str++;
			ft_memmove(buf, str, ft_strlen(str) + 1);
			return (1);
		}
		buf = read_buf(fd, buf, &ret);
		if (ret == 0)
			*line = ft_strdup(buf);
	}
	return (ret);
}
