/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 16:49:46 by bshanae           #+#    #+#             */
/*   Updated: 2019/12/18 16:49:46 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_list.h"

t_list_item				*list_push(t_list *list, VOID_REF data)
{
	t_list_item			*item;
	t_list_item			*iter;

	if (!list_verify(list))
		return (NULL);
	item = list_item_new(data, list->element_size);
	if (!list->begin)
		list->begin = item;
	else
		list->end->next = item;
	list->end = item;
	return (item);
}
