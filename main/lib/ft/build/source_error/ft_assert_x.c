/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_assert_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 16:46:23 by bshanae           #+#    #+#             */
/*   Updated: 2019/12/18 16:46:25 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_error.h"

void				ft_assert(
	t_error_config *config, int statement, CHAR_REF message)
{
	if (!statement)
		ft_raise_warning(config, message);
}

void				ft_assert_critical(
	t_error_config *config, int statement, CHAR_REF message)
{
	if (!statement)
		ft_raise_error(config, message);
}
