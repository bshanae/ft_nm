/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_destroy.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 17:03:55 by bshanae           #+#    #+#             */
/*   Updated: 2019/12/18 17:03:55 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_btree.h"

static void				static_helper(t_btree *btree, t_btree_node **node)
{
	if (!*node)
		return ;
	if ((*node)->left)
		static_helper(btree, &(*node)->left);
	if ((*node)->right)
		static_helper(btree, &(*node)->right);
	btree_node_delete(node, btree->f_del);
}

void					btree_destroy(t_btree *btree)
{
	btree->is_valid = false;
	static_helper(btree, &btree->root);
	btree->element_size = 0;
	btree->f_cmp = NULL;
	btree->f_del = NULL;
}
