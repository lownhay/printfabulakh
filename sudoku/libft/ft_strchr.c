/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abulakh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 17:07:04 by abulakh           #+#    #+#             */
/*   Updated: 2017/10/26 17:07:04 by abulakh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*a;
	size_t	i;
	size_t	m;

	i = 0;
	a = (char *)s;
	m = ft_strlen(a);
	if (m == 0)
		return (NULL);
	while (i < m)
	{
		if (a[i] == c)
			break ;
		i++;
		if (a[i] == '\0' && c != '\0')
			return (NULL);
	}
	return (&a[i]);
}
