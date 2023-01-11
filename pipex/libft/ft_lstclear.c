/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbaskhan <tbaskhan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/22 17:53:12 by tbaskhan          #+#    #+#             */
/*   Updated: 2021/12/24 16:16:48 by tbaskhan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*storage;
	t_list	*clear;

	storage = *lst;
	while (storage)
	{
		clear = storage->next;
		ft_lstdelone(storage, del);
		storage = clear;
	}
	*lst = NULL;
}
