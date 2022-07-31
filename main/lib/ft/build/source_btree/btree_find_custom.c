/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_find_custom.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 17:03:18 by bshanae           #+#    #+#             */
/*   Updated: 2019/12/18 17:03:18 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_btree.h"

static t_btree_node		*static_helper(
	t_btree_node **root, CHAR_REF data, t_btree_f_cmp cmp)
{
	int					cmp_res;

	if (!*root)
		return (NULL);
	cmp_res = cmp((*root)->data, data);
	if (!cmp_res)
		return ((t_btree_node *)*root);
	else if (cmp_res < 0)
		return (static_helper((&((*root)->right)), data, cmp));
	else
		return (static_helper((&((*root)->left)), data, cmp));
}

t_btree_node			*btree_find_custom(
	t_btree *btree, t_btree_f_cmp cmp, VOID_REF data)
{
	if (!btree->is_valid)
	{
		ft_raise_warning(&btree->error_config, "Btree is invalid");
		return (NULL);
	}
	return (static_helper(&btree->root, data, cmp));
}
