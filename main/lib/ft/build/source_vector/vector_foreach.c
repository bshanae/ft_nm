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

void						vector_foreach(
	t_vector *me, t_vector_f1 f, void *ptr)
{
	u_long					i;

	i = 0;
	while (i < me->length)
		f(me->storage + i++ * me->element_size, ptr);
}
