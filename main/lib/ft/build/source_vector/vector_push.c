/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_push_back.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 16:11:50 by bshanae           #+#    #+#             */
/*   Updated: 2019/05/14 16:11:51 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_vector.h"

t_vector_iter		vector_push(t_vector *me, void *data)
{
	if (!me->storage)
		return (vector_iter_set(NULL, -1));
	if ((double)(me->length + 1) / (me->capacity) >= VECTOR_ALLOC_LIMIT)
		vector_realloc(me, me->capacity * VECTOR_ALLOC_MULT, true);
	if (data)
		ft_memcpy(me->storage + me->element_size * me->length,
			data, me->element_size);
	else
		ft_bzero(me->storage + me->element_size * me->length, me->element_size);
	me->length++;
	return (vector_iter_set(me, me->length - 1));
}
