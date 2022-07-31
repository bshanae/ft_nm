/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_find.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 17:03:49 by bshanae           #+#    #+#             */
/*   Updated: 2019/12/18 17:03:49 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_btree.h"

static t_btree_node		*static_helper(
	t_btree_node **root, CHAR_REF data, t_btree_f_cmp cmp)
{
	int cmp_res;

	if (!*root)
		return (NULL);
	cmp_res = cmp((*root)->data, data);
	if (!cmp_res)
		return ((t_btree_node *)*root);
	else
		return (static_helper(((cmp_res >= 0) ?
			&((*root)->left) : &((*root)->right)), data, cmp));
}

t_btree_node			*btree_find(t_btree *btree, VOID_REF data)
{
	if (!btree->is_valid)
	{
		ft_raise_warning(&btree->error_config, "Btree is invalid");
		return (NULL);
	}
	return (static_helper(&btree->root, data, btree->f_cmp));
}
