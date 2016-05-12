/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pba <pba@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/14 05:09:01 by pba               #+#    #+#             */
/*   Updated: 2015/02/21 19:28:02 by pba              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list	*list;
	t_list	*nextone;

	list = *alst;
	while (list)
	{
		nextone = list->next;
		del(&(list->content), list->content_size);
		free(list);
		list = nextone;
	}
	*alst = NULL;
}
