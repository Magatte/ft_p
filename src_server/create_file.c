/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pba <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/31 04:39:22 by pba               #+#    #+#             */
/*   Updated: 2016/05/31 05:44:50 by pba              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
