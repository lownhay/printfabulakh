/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abulakh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 21:56:11 by abulakh           #+#    #+#             */
/*   Updated: 2017/10/25 21:56:11 by abulakh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*a;
	unsigned char	*b;
	size_t			i;

	i = 0;
	a = (unsigned char *)dst;
	b = (unsigned char *)src;
	len--;
	while ((int)len >= 0 && (a > b))
	{
		a[len] = b[len];
		len--;
	}
	len++;
	while (i < len && (a < b))
	{
		a[i] = b[i];
		i++;
	}
	return (a);
}
