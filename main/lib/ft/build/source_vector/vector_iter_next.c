/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_iter_next.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 16:55:47 by bshanae           #+#    #+#             */
/*   Updated: 2019/12/18 16:55:47 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_vector.h"

int				vector_iter_next(t_vector_iter *iter)
{
	if (iter->index == iter->vector->length - 1)
		return (0);
	iter->index++;
	return (1);
}
