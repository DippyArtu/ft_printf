/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_pointer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Artur <Artur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 13:21:10 by Artur             #+#    #+#             */
/*   Updated: 2020/08/05 16:28:54 by Artur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char 				*process_base(unsigned long long ull_tmp, int base,
							  char *out, int count)
{
	while (ull_tmp != 0)
	{
		if ((ull_tmp % base) < 10)
			out[count - 1] = (ull_tmp % base) + 48;
		else
			out[count - 1] = (ull_tmp % base) + 55;
		ull_tmp /= base;
		count--;
	}
	return (out);
}

char 						*ull_base(unsigned long long ull, int base)
{
	char 					*out;
	unsigned long long 		ull_tmp;
	int 					count;

	out = NULL;
	count = 0;
	ull_tmp = ull;
	if (ull == 0)
		return (ft_strdup("0"));
	while (ull != 0)
	{
		ull /= base;
		count++;
	}
	if (!(out = malloc(sizeof(char) * (count + 1))))
		return (0);
	out[count] = '\0';
	out = process_base(ull_tmp, base, out, count);
	return (out);
}

int 						process_pointer(unsigned long long ull, t_flags flags)
{
	char 					*ptr;
	int 					count;

	count = 0;
	if (ull == 0 && flags.dot == 0)
	{
		count += put_str_adjusted("0x", 2);
		return (count += process_width(flags.width, 0, 1));
	}
	ptr = ull_base(ull, 16);
	ptr = ft_str_tolower(ptr);
	if ((size_t)flags.dot < ft_strlen(ptr))
		flags.dot = ft_strlen(ptr);
	if (flags.minus == 1)
		count += adjust_part_ptr(ptr, flags);
}
