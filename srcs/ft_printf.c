/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Artur <Artur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 18:50:27 by Artur             #+#    #+#             */
/*   Updated: 2020/08/05 10:45:15 by Artur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "ft_printf.h"

t_flags				init_flags(void)
{
	t_flags			flags;

	flags.dot = -1;
	flags.minus = 0;
	flags.star = 0;
	flags.type = 0;
	flags.width = 0;
	flags.zero = 0;
	return(flags);
}

int 				parse_flags(const char *str, int i, t_flags *flags, va_list args)
{
	while (str[i])
	{
		if (!ft_isdigit(str[i]) && !is_in_type_list(str[i])
			&& !is_in_flags_list(str[i]))
				break ;
		else if (str[i] == '0' && flags->width == 0 && flags->minus == 0)
			flags->zero = 1;
		else if (str[i] == '.')
			i = flag_dot(str, i,flags, args);
		else if (str[i] == '-')
			*flags = flag_minus(*flags);
		else if (str[i] == '*')
			*flags = flag_width(args, *flags);
		else if (ft_isdigit(str[i]))
			*flags = flag_number(str[i], *flags);
		if (is_in_type_list(str[i]))
		{
			flags->type = str[i];
			break ;
		}
		i++;
	}
	return (i);
}

int 				proccess_format(const char *str, va_list args)
{
	int 			i;
	t_flags			flags;
	int 			c;

	i = 0;
	c = 0;
	while(1)
	{
		flags = init_flags();
		if (!str)
			break ;
		else if (str[i] == '%' && str[i + 1])
		{
			i = parse_flags(str, ++i, &flags, args);
			if (is_in_type_list(str[i]))
				ft_putchar('!');
				//c += process_str((char)flags.type, flags, args);

		}
	}
	return (0);
}

int 				ft_printf(const char *format, ...)
{
	const char 		*tmp;
	va_list			args;
	int 			c;

	tmp = ft_strdup(format);
	c = 0;
	va_start(args, format);
	c += proccess_format(tmp, args);
	va_end(args);
	free((char *)tmp);
	return (c);
}
