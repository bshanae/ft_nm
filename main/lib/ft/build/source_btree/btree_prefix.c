/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_prefix.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 17:03:06 by bshanae           #+#    #+#             */
/*   Updated: 2019/12/18 17:03:06 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_btree.h"

static void			static_helper(
	t_btree_node *root, t_btree_f_trv trv, void *ptr)
{
	if (!root)
		return ;
	trv(root->data, ptr);
	static_helper(root->left, trv, ptr);
	static_helper(root->right, trv, ptr);
}

void				btree_prefix(t_btree *btree, t_btree_f_trv trv, void *ptr)
{
	if (!btree->is_valid)
		ft_raise_warning(&btree->error_config, "Btree is invalid");
	else
		static_helper(btree->root, trv, ptr);
}
