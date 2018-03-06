/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abulakh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/04 18:54:56 by abulakh           #+#    #+#             */
/*   Updated: 2017/11/04 18:54:57 by abulakh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*a;
	char	*b;
	size_t	i[2];
	size_t	j;

	if (!s)
		return (0);
	b = (char *)s;
	i[0] = 0;
	i[1] = 0;
	j = ft_strlen(b);
	while ((b[i[0]] == ' ' || b[i[0]] == '\n' || b[i[0]] == '\t') && i[0] < j)
		i[0]++;
	if (i[0] == j)
		i[0] = 0;
	while ((b[j - 1] == ' ' || b[j - 1] == '\n' || b[j - 1] == '\t') && j > 0)
		j--;
	a = ft_strnew(j - i[0]);
	if (!a)
		return (0);
	while (i[0] < j)
		a[i[1]++] = s[i[0]++];
	a[i[1]] = '\0';
	return (a);
}
