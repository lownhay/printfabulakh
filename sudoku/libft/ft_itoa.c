/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abulakh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 20:02:16 by abulakh           #+#    #+#             */
/*   Updated: 2017/11/04 20:02:17 by abulakh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*itoa_helper(char **a, long *f, long *k, int *n)
{
	int		i;
	char	*b;

	b = *a;
	i = 0;
	*k = *n;
	*f /= 10;
	if (*k < 0)
	{
		*k = -(*k);
		b[i] = '-';
		i++;
	}
	while (*f != 0)
	{
		b[i] = *k / *f + '0';
		*k %= *f;
		*f /= 10;
		i++;
	}
	b[i] = '\0';
	return (b);
}

char		*ft_itoa(int n)
{
	long	k;
	long	f;
	int		i;
	char	*a;

	k = n;
	f = 1;
	i = 0;
	if (k == 0)
	{
		a = ft_strnew(1);
		if (!a)
			return (0);
		a[0] = '0';
		return (a);
	}
	while (k != 0)
	{
		f *= 10;
		i++;
		k /= 10;
	}
	if ((a = ft_strnew(i + 1)) != NULL)
		a = itoa_helper(&a, &f, &k, &n);
	return (a ? a : NULL);
}
