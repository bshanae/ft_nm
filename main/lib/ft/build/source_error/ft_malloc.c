/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 16:46:50 by bshanae           #+#    #+#             */
/*   Updated: 2019/12/18 16:46:50 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_error.h"

void				*ft_malloc(t_error_config *config, u_long size)
{
	void			*ptr;

	ptr = malloc(size);
	ft_assert_critical(config, ptr != NULL, "Malloc error");
	return (ptr);
}
