/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Artur <Artur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/04 21:44:39 by Artur             #+#    #+#             */
/*   Updated: 2020/08/06 11:00:07 by Artur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int 				is_in_type_list(int c)
{
	return ((c == 'c') || (c == 's') || (c == 'p') || (c == 'd') || (c == 'i')
					|| (c == 'u') || (c == 'x') || (c == 'X') || (c == '%'));
}

int 				is_in_flags_list(int c)
{
	return ((c == '-') || (c == ' ') || (c == '0') || (c == '.') || (c == '*'));
}

int 				process_str(int c, t_flags flags, va_list args)
{
	int 			count;

	count = 0;
	if (c == 'c')
		count = process_char(va_arg(args, int), flags);
	else if (c == 's')
		count = process_string(va_arg(args, char *), flags);
	else if (c == 'p')
		count = process_pointer(va_arg(args, unsigned long long), flags);
	else if (c == 'i' || c == 'd')
		count = process_int(va_arg(args, int), flags);
	else if (c == 'u')
		count = process_uint((unsigned int)va_arg(args, unsigned int), flags);
	else if (c == 'x')
		count = process_hex(va_arg(args, unsigned int), 1, flags);
	else if (c == 'X')
		count = process_hex(va_arg(args, unsigned int), 0, flags);
	else if (c == '%')
		count = process_percent(flags);
	return (count);
}
