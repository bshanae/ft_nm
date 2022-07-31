/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_item_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 16:49:56 by bshanae           #+#    #+#             */
/*   Updated: 2019/12/18 16:49:56 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_list.h"

t_list_item				*list_item_new(VOID_REF data, size_t size)
{
	t_list_item			*item;

	item = ft_malloc(NULL, sizeof(t_list_item));
	item->data = ft_malloc(NULL, size);
	if (data)
		ft_memcpy(item->data, data, size);
	else
		ft_bzero(item->data, size);
	item->next = NULL;
	return (item);
}

void					list_item_delete(t_list_item *item)
{
	free(item->data);
	free(item);
	item->data = NULL;
	item->next = NULL;
}
