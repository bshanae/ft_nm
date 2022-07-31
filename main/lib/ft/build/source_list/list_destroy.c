/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_destroy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 16:49:33 by bshanae           #+#    #+#             */
/*   Updated: 2019/12/18 16:49:33 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_list.h"

void				list_destroy(t_list *list)
{
	t_list_item		*iter;
	t_list_item		*next;

	if (!list->begin)
		return ;
	iter = list->begin;
	while (iter)
	{
		next = iter->next;
		list_item_delete(iter);
		iter = next;
	}
	list->begin = NULL;
	list->end = NULL;
	list->element_size = 0;
}
