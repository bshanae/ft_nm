/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_enlarge.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 16:09:23 by bshanae           #+#    #+#             */
/*   Updated: 2019/05/28 20:58:05 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_vector.h"

size_t					vector_index(t_vector *me, void *ptr)
{
	if (ptr < me->storage)
		return (-1);
	if (ptr > me->storage + (me->length - 1) * me->element_size)
		return (-1);
	return ((ptr - me->storage) / me->element_size);
}
