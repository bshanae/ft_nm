/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_insert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 17:02:38 by bshanae           #+#    #+#             */
/*   Updated: 2019/12/18 17:02:38 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_btree.h"

t_btree_node			*static_helper(
	t_btree_node **node, size_t size, VOID_REF data, t_btree_f_cmp cmp)
{
	if (!*node)
		return (*node = btree_node_new(size, data));
	if (cmp(data, (*node)->data) < 0)
		return (static_helper(&((*node)->left), size, data, cmp));
	else
		return (static_helper(&((*node)->right), size, data, cmp));
}

t_btree_node			*btree_insert(t_btree *btree, VOID_REF data)
{
	if (!btree->is_valid)
	{
		ft_raise_warning(&btree->error_config, "Btree is invalid");
		return (NULL);
	}
	return (static_helper(&btree->root,
		btree->element_size, data, btree->f_cmp));
}
