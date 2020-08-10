/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Artur <Artur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/10 17:57:27 by Artur             #+#    #+#             */
/*   Updated: 2020/08/10 17:57:27 by Artur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 1

# include "libft.h"
# include <fcntl.h>

typedef struct					s_gnl_list
{
	int							fd;
	char						*remainder;
	struct s_gnl_list			*next;
}								t_gnl;

int								get_next_line(const int fd, char **line);

#endif
