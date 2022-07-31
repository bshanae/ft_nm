/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_remove.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 17:01:41 by bshanae           #+#    #+#             */
/*   Updated: 2019/12/18 17:01:41 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_btree.h"

static void				static_replace(
	t_btree_node **main, t_btree_node **new, t_btree_f_del del)
{
	if (del)
		del((*main)->data);
	free(*main);
	*main = new ? *new : NULL;
}

static void				static_swap(t_btree_node *a, t_btree_node *b)
{
	void				*temp;

	temp = a->data;
	a->data = b->data;
	b->data = temp;
}

static t_btree_node		**static_find_replace(t_btree_node *root)
{
	t_btree_node		*temp;

	if (!(root->right->left))
		return (&(root->right));
	temp = root->right;
	while (temp->left->left)
		temp = temp->left;
	return (&(temp->left));
}

static t_btree_node		*static_delete_node(
	t_btree_node **node, VOID_REF data, t_btree_f_cmp cmp, t_btree_f_del del)
{
	int					cmp_root;
	t_btree_node		**temp;

	if (!*node)
		return (NULL);
	cmp_root = cmp(data, (*node)->data);
	if (cmp_root < 0)
		return (static_delete_node(&((*node)->left), data, cmp, del));
	if (cmp_root > 0)
		return (static_delete_node(&((*node)->right), data, cmp, del));
	if ((*node)->left && (*node)->right)
	{
		temp = static_find_replace(*node);
		static_swap(*node, *temp);
		static_delete_node(temp, data, cmp, del);
	}
	else if ((*node)->left)
		static_replace(node, &((*node)->left), del);
	else if ((*node)->right)
		static_replace(node, &((*node)->right), del);
	else
		static_replace(node, NULL, del);
	return (*node);
}

t_btree_node			*btree_remove(t_btree *btree, VOID_REF data)
{
	if (!btree->is_valid)
	{
		ft_raise_warning(&btree->error_config, "Btree is invalid");
		return (NULL);
	}
	return (static_delete_node(&btree->root, data, btree->f_cmp, btree->f_del));
}
