/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Artur <Artur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/21 18:48:43 by Artur             #+#    #+#             */
/*   Updated: 2020/08/05 13:33:25 by Artur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft.h"
# include <stdarg.h>

typedef struct 		s_flags
{
	int 			print_done;
	int 			type;
	int				width;
	int 			minus;
	int 			zero;
	int 			dot;
	int 			star;
}					t_flags;

int 				ft_printf(const char *format, ...);
int 				proccess_format(const char *str, va_list args);
t_flags				init_flags(void);
int 				parse_flags(const char *str, int i, t_flags *flags, va_list args);
int 				is_in_type_list(int c);
int 				is_in_flags_list(int c);
int 				flag_dot(const char *str, int start, t_flags *flags, va_list args);
t_flags 			flag_minus(t_flags flags);
t_flags 			flag_width(va_list args, t_flags flags);
t_flags 			flag_number(char c, t_flags flags);
int 				process_str(int c, t_flags flags, va_list args);
int 				process_width(int width, int minus, int zero);
int 				process_char(char c, t_flags flags);
int 				put_str_adjusted(char *str, int step);
int 				adjust_part(char *str, t_flags flags);
int 				process_string(char *str, t_flags flags);
char 				*ull_base(unsigned long long ull, int base);
int 				process_pointer(unsigned long long ull, t_flags flags);

#endif
