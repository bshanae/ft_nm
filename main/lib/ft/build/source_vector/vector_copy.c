/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_clear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 16:06:38 by bshanae           #+#    #+#             */
/*   Updated: 2019/12/18 16:55:07 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_vector.h"

t_bool						vector_copy(t_vector *destination, t_vector *source)
{
	if (destination->element_size != source->element_size)
		return (false);
	if (destination->capacity < source->length)
		vector_realloc(destination, source->capacity, false);
	ft_memcpy(destination->storage, source->storage,
		source->element_size * source->length);
	return (true);
}
