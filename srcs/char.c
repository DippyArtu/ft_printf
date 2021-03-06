/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Artur <Artur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 17:57:47 by Artur             #+#    #+#             */
/*   Updated: 2020/08/10 17:57:47 by Artur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void				print_percent(t_pfstruct *data)
{
	int			width;

	if (data->fs.wid && !data->fs.flag.minus)
	{
		width = data->fs.wid - 1;
		if (data->fs.flag.zero)
			data->pfreturn += write_chars(width, '0');
		else
			data->pfreturn += write_chars(width, ' ');
		data->pfreturn += write(1, "%", 1);
	}
	else if (data->fs.wid && data->fs.flag.minus)
	{
		data->pfreturn += write(1, "%", 1);
		width = data->fs.wid - 1;
		data->pfreturn += write_chars(width, ' ');
	}
	else
		data->pfreturn += write(1, "%", 1);
}

void				print_char(t_pfstruct *data)
{
	int				width;
	unsigned char	ch;

	ch = (unsigned char)va_arg(data->args, int);
	if (data->fs.wid && !data->fs.flag.minus)
	{
		width = data->fs.wid - 1;
		if (data->fs.flag.zero)
			data->pfreturn += write_chars(width, '0');
		else
			data->pfreturn += write_chars(width, ' ');
		data->pfreturn += write(1, &ch, 1);
	}
	else if (data->fs.wid && data->fs.flag.minus)
	{
		data->pfreturn += write(1, &ch, 1);
		width = data->fs.wid - 1;
		data->pfreturn += write_chars(width, ' ');
	}
	else
		data->pfreturn += write(1, &ch, 1);
}
