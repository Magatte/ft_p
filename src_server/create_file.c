/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pba <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 04:39:22 by pba               #+#    #+#             */
/*   Updated: 2016/06/05 04:25:20 by pba              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** create a file with the rights to read and write into it.
*/

#include "ft_p.h"

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
