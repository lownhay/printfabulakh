/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abulakh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 18:56:12 by abulakh           #+#    #+#             */
/*   Updated: 2017/10/26 18:56:13 by abulakh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <string.h>

char	*ft_strnstr(const char *hs, const char *nl, size_t len)
{
	char	*a;
	char	*b;
	size_t	i;
	size_t	j;

	i = 0;
	a = (char *)hs;
	b = (char *)nl;
	while (i < len && i <= ft_strlen(a))
	{
		j = 0;
		while (a[i] == b[j] && i < len && a[i] && b[j])
		{
			i++;
			j++;
		}
		if (j == ft_strlen(b))
			return (&a[i] - j);
		else
			i = i - j;
		i++;
	}
	return (NULL);
}
