/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_raise_x.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 16:46:09 by bshanae           #+#    #+#             */
/*   Updated: 2019/12/18 16:46:09 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_error.h"

void				ft_raise_warning(t_error_config *config, CHAR_REF message)
{
	ft_print_warning(config, message);
	if (config && config->warning_as_error)
		exit(2);
}

void				ft_raise_error(t_error_config *config, CHAR_REF message)
{
	ft_print_error(config, message);
	exit(1);
}
