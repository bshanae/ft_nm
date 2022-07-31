/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_config_create.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 16:45:59 by bshanae           #+#    #+#             */
/*   Updated: 2019/12/18 16:45:59 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_error.h"

t_error_config		error_config_create(void)
{
	t_error_config	config;

	config.message_print = true;
	config.warning_as_error = false;
	ft_strcpy(config.warning_prefix, "FT_WARNING");
	ft_strcpy(config.error_prefix, "FT_ERROR");
	return (config);
}
