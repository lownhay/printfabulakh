/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_listsize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abulakh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 18:10:04 by abulakh           #+#    #+#             */
/*   Updated: 2017/11/14 18:10:04 by abulakh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_listsize(t_list *klist)
{
	t_list	*m;
	int		i;

	if (!klist)
		return (0);
	i = 1;
	m = klist;
	while (m->next != NULL)
	{
		i++;
		m = m->next;
	}
	return (i);
}
