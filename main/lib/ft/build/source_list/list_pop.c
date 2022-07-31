/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_pop.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 16:50:17 by bshanae           #+#    #+#             */
/*   Updated: 2019/12/18 16:50:17 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_list.h"

t_bool				list_pop(t_list *list)
{
	t_list_item		*iter;

	if (!list_verify(list))
		return (false);
	if (!list->begin)
		return (false);
	if (list->begin == list->end)
	{
		list_item_delete(list->begin);
		list->begin = NULL;
		list->end = NULL;
		return (true);
	}
	iter = list->begin;
	while (iter)
	{
		if (iter->next == list->end)
			break ;
		iter = iter->next;
	}
	list_item_delete(list->end);
	list->end = iter;
	return (true);
}
