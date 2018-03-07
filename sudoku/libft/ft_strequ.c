/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abulakh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 18:19:18 by abulakh           #+#    #+#             */
/*   Updated: 2017/11/04 18:19:19 by abulakh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strequ(char const *s1, char const *s2)
{
	char		*a;
	char		*b;
	size_t		i;

	i = 0;
	if (!s1 || !s2)
		return (0);
	a = (char *)s1;
	b = (char *)s2;
	while (a[i] == b[i] && b[i] && a[i])
		i++;
	if (i == ft_strlen(a) && i == ft_strlen(b))
		return (1);
	else
		return (0);
}
