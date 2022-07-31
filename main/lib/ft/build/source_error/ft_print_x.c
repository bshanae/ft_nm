/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _ft_print_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshanae <bshanae@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/18 16:44:37 by bshanae           #+#    #+#             */
/*   Updated: 2019/12/18 16:45:31 by bshanae          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_error.h"

static void			basic_print(const char *string)
{
	const int 		length = ft_strlen(string);

	write(1, string, length);
}

void				ft_print_warning(t_error_config *config, CHAR_REF message)
{
	basic_print("\033[0;31m");
	if (config)
	{
		basic_print(config->warning_prefix);
		if (config->message_print)
		{
			basic_print(" : ");
			basic_print(message);
		}
	}
	else
	{
		basic_print("LIBFT WARNING : ");
		basic_print(message);
	}
	basic_print("\n");
	basic_print("\033[0m");
}

void				ft_print_error(t_error_config *config, CHAR_REF message)
{
	basic_print("\033[0;31m");
	if (config)
	{
		basic_print(config->error_prefix);
		if (config->message_print)
		{
			basic_print(" : ");
			basic_print(message);
		}
	}
	else
	{
		basic_print("LIBFT ERROR : ");
		basic_print(message);
	}
	basic_print("\n");
	basic_print("\033[0m");
}
