/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skennith <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 18:01:13 by skennith          #+#    #+#             */
/*   Updated: 2020/08/10 17:54:51 by Artur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*res;
	char	*a;
	int		i;

	if (!s || !f || ft_strlen((char *)s) > (ft_strlen((char *)s) + 1))
		return (NULL);
	res = (char *)malloc(ft_strlen((char *)s) + 1);
	a = (char *)s;
	if (!res)
		return (NULL);
	i = 0;
	while (a[i])
	{
		res[i] = f(a[i]);
		i++;
	}
	res[i] = '\0';
	return (res);
}
