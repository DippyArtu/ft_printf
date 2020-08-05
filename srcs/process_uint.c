/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_uint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Artur <Artur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 20:13:54 by Artur             #+#    #+#             */
/*   Updated: 2020/08/05 20:27:51 by Artur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int 			put_uint_adjusted(char *uint_int, t_flags flags)
{
	int 			count;

	count = 0;
	if (flags.dot >= 0)
		count += process_width(flags.dot - 1, ft_strlen(uint_int) - 1, 1);
	count += put_str_adjusted(uint_int, ft_strlen(uint_int));
	return (count);
}

static int 			adjust_uint(char *uint_int, t_flags flags)
{
	int 			count;

	count = 0;
	if (flags.minus == 1)
		count += put_uint_adjusted(uint_int, flags);
	if (flags.dot >= 0 && (size_t)flags.dot < ft_strlen(uint_int))
		flags.dot = ft_strlen(uint_int);
	if (flags.dot >= 0)
	{
		flags.width -= flags.dot;
		count += process_width(flags.width, 0, 0);
	}
	else
		count += process_width(flags.width, ft_strlen(uint_int), flags.zero);
	if (flags.minus == 0)
		count += put_uint_adjusted(uint_int, flags);
	return (count);


}

int 				process_uint(unsigned int uint, t_flags flags)
{
	char 			*uint_int;
	int 			count;

	count = 0;
	uint = (unsigned int)(4294967295 + 1 + uint);
	if (flags.dot == 0 && uint == 0)
	{
		count += process_width(flags.width, 0, 0);
		return (count);
	}
	uint_int = ft_uint_itoa(uint);
	count += adjust_uint(uint_int, flags);
	free(uint_int);
	return (count);
}
