/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abulakh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/03 18:48:59 by abulakh           #+#    #+#             */
/*   Updated: 2017/11/03 18:49:01 by abulakh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t n)
{
	char	*k;
	size_t	i;
	size_t	j;
	size_t	sum;

	j = 0;
	i = 0;
	k = (char *)src;
	if (ft_strlen(dst) > n)
		sum = n + ft_strlen(src);
	else
		sum = ft_strlen(dst) + ft_strlen(src);
	while (dst[i])
		i++;
	if (n == 0)
		return (sum);
	while (k[j] && i < (n - 1))
	{
		dst[i] = k[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (sum);
}
