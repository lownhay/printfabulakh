/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abulakh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 20:00:07 by abulakh           #+#    #+#             */
/*   Updated: 2017/11/08 20:00:08 by abulakh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_helper_fd(int m, long i, long k, int fd)
{
	char	a;

	if (i < 0)
	{
		ft_putchar_fd('-', fd);
		i = -i;
	}
	k /= 10;
	while (m > 0)
	{
		a = (i / k) + '0';
		i = i % k;
		k /= 10;
		m--;
		ft_putchar_fd(a, fd);
	}
}

void		ft_putnbr_fd(int n, int fd)
{
	long	i;
	long	k;
	int		m;

	k = 1;
	i = n;
	m = 0;
	if (i == 0)
		ft_putchar_fd('0', fd);
	while (i != 0)
	{
		i /= 10;
		k *= 10;
		m++;
	}
	ft_helper_fd(m, n, k, fd);
}
