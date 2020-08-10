/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skennith <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 14:16:16 by skennith          #+#    #+#             */
/*   Updated: 2020/08/10 17:54:51 by Artur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dst, const char *ap, size_t n)
{
	int		i;
	size_t	j;

	i = 0;
	j = 0;
	if (!dst && !ap)
		return (NULL);
	while (dst[i])
		i++;
	while (ap[j] && j < n)
		dst[i++] = ap[j++];
	dst[i] = '\0';
	return (dst);
}
