/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_verify.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 16:50:08 by bshanae           #+#    #+#             */
/*   Updated: 2019/12/18 16:50:08 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_list.h"

t_bool				list_verify(t_list *list)
{
	if (!list->is_valid)
		ft_raise_warning(&list->error_config, "List is invalid");
	else if ((!list->begin && list->end) || (list->begin && !list->end))
		ft_raise_warning(&list->error_config, "Internal error");
	else
		return (true);
	return (false);
}
