/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pba <pba@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/13 06:06:08 by pba               #+#    #+#             */
/*   Updated: 2015/05/15 13:03:39 by pba              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list		*list;

	if ((list = (t_list*)malloc(sizeof(t_list))))
	{
		list->next = NULL;
		if (content == NULL)
		{
			list->content = NULL;
			list->content_size = 0;
		}
		else
		{
			if ((list->content = (void*)malloc(content_size)) == NULL)
				return (NULL);
			ft_memcpy(list->content, content, content_size);
			list->content_size = content_size;
		}
	}
	else
		return (NULL);
	return (list);
}
