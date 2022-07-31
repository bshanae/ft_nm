/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 21:06:57 by bshanae           #+#    #+#             */
/*   Updated: 2019/05/28 21:07:04 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_vector.h"
#include "libft_ft_printf.h"

void						vector_print(t_vector *me, t_vector_f1 f, void *ptr)
{
	u_long					i;

	ft_printf("{");
	i = 0;
	while (i < me->length)
	{
		f(me->storage + i++ * me->element_size, ptr);
		if (i < me->length)
			ft_printf(", ");
	}
	ft_printf("}\n");
}
