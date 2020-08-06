/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_percent.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Artur <Artur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/06 11:01:03 by Artur             #+#    #+#             */
/*   Updated: 2020/08/06 11:01:22 by Artur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int 				process_percent(t_flags flags)
{
	int 			count;

	count = 0;
	if (flags.minus == 1)
		count += put_str_adjusted("%", 1);
	count += process_width(flags.width, 1, flags.zero);
	if (flags.minus == 0)
		count += put_str_adjusted("%", 1);
	return (count);
}
