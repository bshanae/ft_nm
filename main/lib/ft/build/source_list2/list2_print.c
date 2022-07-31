/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list2_print.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 16:52:41 by bshanae           #+#    #+#             */
/*   Updated: 2019/12/18 16:52:41 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_list2.h"

void					list2_print(
	t_list2 *list, t_list2_f_print print, VOID_REF ptr)
{
	t_list2_node		*iter;

	if (!list->is_valid)
		return (ft_raise_warning(&list->error_config, "List is invalid"));
	ft_printf("");
	iter = list->begin;
	while (iter)
	{
		print(iter->data, ptr);
		if ((iter = iter->next))
			ft_printf(" -> ");
	}
	ft_printf("\n");
}
