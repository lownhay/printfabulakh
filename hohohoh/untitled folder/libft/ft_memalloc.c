/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abulakh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 17:32:19 by abulakh           #+#    #+#             */
/*   Updated: 2017/10/30 17:32:20 by abulakh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*ch;

	ch = NULL;
	ch = malloc(size);
	if (!ch)
		return (NULL);
	ch = ft_memset(ch, 0, size);
	return (ch);
}
