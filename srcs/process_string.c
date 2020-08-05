/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_string.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Artur <Artur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 11:37:30 by Artur             #+#    #+#             */
/*   Updated: 2020/08/05 11:54:04 by Artur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int 				put_str_adjusted(char *str, int step)
{
	int 			count;

	count = 0;
	while (str[count] && count < step)
		ft_putchar(str[count++]);
	return (count);
}

int 				adjust_part(char *str, t_flags flags)
{
	int 			count;

	count = 0;
	if (flags.dot >= 0)
	{
		count += process_width(flags.dot, ft_strlen(str), 0);
		count += put_str_adjusted(str, flags.dot);
	}
	else
		count += put_str_adjusted(str, ft_strlen(str));
	return (count);
}

int 				process_string(char *str, t_flags flags)
{
	int 			count;

	count = 0;
	if (!str)
		str = "(null)";
	if (flags.dot >= 0 && (size_t)flags.dot > ft_strlen(str))
		flags.dot = ft_strlen(str);
	if (flags.minus == 1)
		count += adjust_part(str, flags);
	if (flags.dot >= 0)
		count += process_width(flags.width, flags.dot, 0);
	else
		count += process_width(flags.width, ft_strlen(str), 0);
	if (flags.minus == 0)
		count += adjust_part(str, flags);
	return (count);

}
