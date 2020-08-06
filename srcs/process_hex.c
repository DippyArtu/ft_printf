/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Artur <Artur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 10:34:03 by Artur             #+#    #+#             */
/*   Updated: 2020/08/06 10:56:55 by Artur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int 			put_hex_adjusted(char *hex, t_flags flags)
{
	int 			count;

	count = 0;
	if (flags.dot >= 0)
		count += process_width(flags.dot - 1, ft_strlen(hex) - 1, 1);
	count += put_str_adjusted(hex, ft_strlen(hex));
	return (count);
}

static int 			adjust_hex(char *hex, t_flags flags)
{
	int 			count;

	count = 0;
	if (flags.minus == 1)
		count += put_hex_adjusted(hex, flags);
	if (flags.dot >= 0 && (size_t)flags.dot < ft_strlen(hex))
		flags.dot = ft_strlen(hex);
	if (flags.dot >= 0)
	{
		flags.width -= flags.dot;
		count += process_width(flags.width, 0, 0);
	}
	else
		count += process_width(flags.width, ft_strlen(hex), flags.zero);
	if (flags.minus == 0)
		count += put_hex_adjusted(hex, flags);
	return (count);
}

int 				process_hex(unsigned int ui, int lower, t_flags flags)
{
	char 			*hex;
	int 			count;

	count = 0;
	ui = (unsigned int)(4294967295 + 1 + ui);
	if (flags.dot == 0 && ui == 0)
	{
		count += process_width(flags.width, 0, 0);
		return (count);
	}
	hex = ull_base((unsigned long long)ui, 16);
	if (lower == 1)
		hex = ft_str_tolower(hex);
	count += adjust_hex(hex, flags);
	free(hex);
	return (count);
}
