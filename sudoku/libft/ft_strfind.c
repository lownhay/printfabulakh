/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strfind.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abulakh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 17:36:22 by abulakh           #+#    #+#             */
/*   Updated: 2017/11/17 17:36:23 by abulakh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	*ft_strfind(char **k, char *str)
{
	int		*pos;
	int		i;

	i = 0;
	if (!k || !str)
		return (0);
	pos = (int *)malloc(sizeof(int) * 2);
	if (!pos)
		return (0);
	while (k[i])
	{
		if (ft_strstr(k[i], str) != 0)
		{
			pos[0] = i;
			pos[1] = ft_strlen(k[i]) - ft_strlen(ft_strstr(k[i], str));
			return (pos);
		}
		i++;
	}
	return (0);
}
