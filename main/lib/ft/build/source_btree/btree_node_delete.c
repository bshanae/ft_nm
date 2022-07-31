/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   btree_node_delete.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 17:03:40 by bshanae           #+#    #+#             */
/*   Updated: 2019/12/18 17:03:40 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_btree.h"

void					btree_node_delete(
	t_btree_node **node, t_btree_f_del del)
{
	if (del)
		del((*node)->data);
	free((*node)->data);
    free(*node);
	*node = NULL;
}
