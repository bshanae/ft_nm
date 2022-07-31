/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_iter_set.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 16:55:54 by bshanae           #+#    #+#             */
/*   Updated: 2019/12/18 16:55:54 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_vector.h"

t_vector_iter		vector_iter_set(t_vector *vector, size_t index)
{
	return ((t_vector_iter){vector, index});
}
