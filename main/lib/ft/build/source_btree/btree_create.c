/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 17:02:06 by bshanae           #+#    #+#             */
/*   Updated: 2019/12/18 17:02:06 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_btree.h"

t_btree					btree_create(size_t element_size, t_btree_f_cmp cmp)
{
	t_btree				btree;

	btree.is_valid = cmp != NULL;
	btree.error_config = error_config_create();
	ft_strcpy(btree.error_config.warning_prefix, "Libft btree warning");
	ft_strcpy(btree.error_config.error_prefix, "Libft btree error");
	btree.root = NULL;
	btree.element_size = element_size;
	btree.f_cmp = cmp;
	btree.f_del = NULL;
	return (btree);
}
