/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_transfer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pba <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 03:23:58 by pba               #+#    #+#             */
/*   Updated: 2016/06/05 06:46:54 by pba              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_p.h"

/*
** init_transfer checks if the file can be open
** and retrieves some informations such as the file size,
** its name and sets a result message
** puts it in a transfer structure
*/

static int			check_error(int sock, char **cmd)
{
	int				fd;
	int				len;

	(void)sock;
	if (cmd[1] == NULL)
		return (0);
	len = ft_strlen(cmd[1]);
	cmd[1][len] = '\0';
	if ((fd = open(cmd[1], O_RDONLY)) == -1)
		return (0);
	return (fd);
}

int					init_transfer(t_transfer *transf,
						int sock, char **cmd, int *fd)
{
	struct stat		stat;

	if ((*fd = check_error(sock, cmd)) == 0)
	{
		ft_strcpy(transf->msg, "[get_file_ER]");
		return (0);
	}
	transf->transfer = 2;
	ft_memset((void *)transf->f_name, 0, 256);
	ft_memset((void *)transf->msg, 0, 14);
	fstat(*fd, &stat);
	transf->size = stat.st_size;
	if (cmd && cmd[1] && ft_strlen(cmd[1]) < 256)
		ft_strcpy(transf->f_name, cmd[1]);
	if (transf->transfer == 2)
		ft_strcpy(transf->msg, "[get_file_OK]");
	else
		ft_strcpy(transf->msg, "[put_file_OK]");
	return (1);
}
