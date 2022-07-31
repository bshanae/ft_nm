/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_at.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 16:06:26 by bshanae           #+#    #+#             */
/*   Updated: 2019/05/14 16:06:31 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_vector.h"

void						*vector_at(t_vector *me, int index)
{
	if (!me || !me->storage || index >= me->length)
		return (NULL);
	if (index < 0)
		index = me->length + index;
	return (me->storage + index * me->element_size);
}
