/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uint_itoa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Artur <Artur@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/05 20:20:15 by Artur             #+#    #+#             */
/*   Updated: 2020/08/05 20:27:51 by Artur            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int 			estimate(long n)
{
	size_t			estm;
	int 			isneg;

	estm = 0;
	isneg = 0;
	if (n < 0)
	{
		estm++;
		isneg++;
		n = -n;
	}
	while (n >= 1)
	{
		estm++;
		n /= 10;
	}
	return (estm);
}

static char 		*convert(char *out, long nbr, int len, int isneg)
{
	if (nbr != 0)
		out = malloc(sizeof(char) * (len + 1));
	else
		return (out = ft_strdup("0"));
	if (!out)
		return (0);
	isneg = 0;
	if (nbr < 0)
	{
		isneg++;
		nbr = -nbr;
	}
	out[len] = '\0';
	while (--len)
	{
		out[len] = (nbr % 10) + '0';
		nbr /= 10;
	}
	if (isneg == 1)
		out[0] = '-';
	else
		out[0] = (nbr % 10) + '0';
	return (out);
}

char 				*ft_uint_itoa(unsigned int n)
{
	int 			len;
	char 			*out;
	long 			nbr;
	int 			isneg;

	nbr = n;
	len = estimate(nbr);
	out = 0;
	isneg = 0;
	if (!(out = convert(out, nbr, len, isneg)))
		return (0);
	return (out);
}
