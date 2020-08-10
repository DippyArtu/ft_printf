/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skennith <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 13:43:38 by skennith          #+#    #+#             */
/*   Updated: 2020/08/10 17:54:51 by Artur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dst, const char *ap)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (!dst && !ap)
		return (NULL);
	while (dst[i])
		i++;
	while (ap[j])
		dst[i++] = ap[j++];
	dst[i] = '\0';
	return (dst);
}
