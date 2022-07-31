/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_create.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 16:49:25 by bshanae           #+#    #+#             */
/*   Updated: 2019/12/18 16:49:25 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_list.h"

t_list				list_create(size_t element_size)
{
	t_list			list;

	list.is_valid = true;
	list.error_config = error_config_create();
	ft_strcpy(list.error_config.warning_prefix, "Libft list warning");
	ft_strcpy(list.error_config.error_prefix, "Libft list error");
	list.begin = NULL;
	list.end = NULL;
	list.element_size = element_size;
	return (list);
}
