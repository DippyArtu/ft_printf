/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Artur <Artur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 19:27:22 by Artur             #+#    #+#             */
/*   Updated: 2020/08/05 19:49:54 by Artur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int			put_int_adjusted(char *d_i, int tmp, t_flags flags)
{
	int 			count;

	count = 0;
	if (tmp < 0 && flags.dot >= 0)
		ft_putchar('-');
	if (flags.dot >= 0)
		count += process_width(flags.dot - 1, ft_strlen(d_i) - 1, 1);
	count += put_str_adjusted(d_i, ft_strlen(d_i));
	return (count);
}

static int 			adjust_int(char *d_i, int tmp, t_flags flags)
{
	int 			count;

	count = 0;
	if (flags.minus == 1)
		count += put_int_adjusted(d_i, tmp, flags);
	if (flags.dot >= 0 && (size_t)flags.dot < ft_strlen(d_i))
		flags.dot = ft_strlen(d_i);
	if (flags.dot >= 0)
	{
		flags.width -= flags.dot;
		count += process_width(flags.width, 0, 0);
	}
	else
		count += process_width(flags.width, ft_strlen(d_i), flags.zero);
	if (flags.minus == 0)
		count += put_int_adjusted(d_i, tmp, flags);
	return (count);
}

int 				process_int(int i, t_flags flags)
{
	char 			*d_i;
	int 			tmp;
	int 			count;

	tmp = i;
	count = 0;
	if (flags.dot == 0 && i == 0)
	{
		count += process_width(flags.width, 0, 0);
		return (count);
	}
	if (i < 0 && (flags.dot >= 0 || flags.zero == 1))
	{
		if (flags.zero == 1 && flags.dot == -1)
			put_str_adjusted("-", 1);
		i *= -1;
		flags.zero = 1;
		flags.width--;
		count++;
	}
	d_i = ft_itoa(i);
	count += adjust_int(d_i, tmp, flags);
	free(d_i);
	return (count);
}
