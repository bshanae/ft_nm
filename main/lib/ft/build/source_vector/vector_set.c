/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_set.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 16:56:39 by bshanae           #+#    #+#             */
/*   Updated: 2019/12/18 16:56:39 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_vector.h"

void					vector_set
	(t_vector *me, size_t begin, size_t end, void *data)
{
	void				*iter;

	if (end == -1)
		end = me->length;
	while (begin < end)
	{
		iter = me->storage + begin++ * me->element_size;
		if (data)
			ft_memcpy(iter, data, me->element_size);
		else
			ft_bzero(iter, me->element_size);
	}
}
