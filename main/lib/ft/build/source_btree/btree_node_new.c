/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_node_new.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 17:02:49 by bshanae           #+#    #+#             */
/*   Updated: 2019/12/18 17:02:49 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_btree.h"

t_btree_node			*btree_node_new(size_t size, VOID_REF data)
{
	t_btree_node		*node;

	node = malloc(sizeof(t_btree_node));
	if (!node)
		return (NULL);
	node->left = NULL;
	node->right = NULL;
	node->data = malloc(size);
	if (!node->data)
	{
		free(node);
		return (NULL);
	}
	ft_memcpy(node->data, data, size);
	return (node);
}
