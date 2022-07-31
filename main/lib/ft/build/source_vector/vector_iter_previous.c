/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_iter_previous.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 16:55:43 by bshanae           #+#    #+#             */
/*   Updated: 2019/12/18 16:55:43 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_vector.h"

int				vector_iter_previous(t_vector_iter *iter)
{
	if (iter->index == 0)
		return (0);
	iter->index--;
	return (1);
}
