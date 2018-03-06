/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abulakh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 17:38:09 by abulakh           #+#    #+#             */
/*   Updated: 2017/11/08 17:38:10 by abulakh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_helper(int m, long long int  i, unsigned long long int  k)
{
	char	a;

	if (i < 0)
	{
		ft_putchar('-');
		i = -i;
	}
	k /= 10;
	while (m > 0)
	{
		a = (i / k) + '0';
		i = i % k;
		k /= 10;
		m--;
		ft_putchar(a);
	}
}

void		ft_putnbr(long long int n)
{
	long long int 	i;
	unsigned long long int 	k;
	int 	m;

	k = 1;
	i = n;
	m = 0;
	if (i == 0)
		ft_putchar('0');
	while (i != 0)
	{
		i /= 10;
		k *= 10;
		m++;
	}
	ft_helper(m, n, k);
}
