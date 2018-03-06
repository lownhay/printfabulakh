/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abulakh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 18:10:33 by abulakh           #+#    #+#             */
/*   Updated: 2017/10/26 18:10:33 by abulakh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	char	*a;
	char	*b;
	int		i;
	size_t	j;

	i = 0;
	j = 0;
	a = (char *)haystack;
	b = (char *)needle;
	if (ft_strlen(a) == 0 && ft_strlen(b) == 0)
		return (a);
	while (a[i])
	{
		while (a[i + j] == b[j] && a[i + j] && b[j])
			j++;
		if (j == ft_strlen(b))
			return (&a[i]);
		else
			j = 0;
		i++;
	}
	return (NULL);
}
