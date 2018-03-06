/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abulakh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 14:26:17 by abulakh           #+#    #+#             */
/*   Updated: 2017/10/30 14:26:18 by abulakh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long int	atoi_helper(char **n, int *k1, int i)
{
	char			*num;
	long int		m;

	m = 0;
	num = *n;
	while (num[i] >= '0' && num[i] <= '9')
	{
		m = (m + num[i++] - '0') * 10;
		*k1 += 1;
	}
	return (m);
}

static int		checker_longa(long long int m, int *k, int i, char *num)
{
	char			*mas;

	mas = "9223372036854775807";
	if (k[1] > 19 && k[0] != 1)
		return (-1);
	else if (k[1] > 19 && k[0] == 1)
		return (0);
	if (k[1] == 19)
	{
		if (k[0] != 1 && ft_strcmp(mas, (&num[i])) < 0)
			return (-1);
		else if (k[0] == 1 && ft_strcmp(mas, (&num[i])) < 0)
			return (0);
	}
	m /= 10;
	if (k[0] == 1)
		m = -m;
	return (m);
}

int				ft_atoi(const char *str)
{
	int				k[2];
	long int		m;
	char			*num;
	int				i;

	k[0] = 0;
	i = 0;
	k[1] = 0;
	m = 0;
	num = (char *)str;
	while (num[i] == '\t' || num[i] == '\v' || num[i] == ' '
		|| num[i] == '\r' || num[i] == '\n' || num[i] == '\f')
		i++;
	if (num[i] == '-')
		k[0] = 1;
	if (num[i] == '-' || num[i] == '+')
		i++;
	m = atoi_helper(&num, &k[1], i);
	return (checker_longa(m, k, i, num));
}
