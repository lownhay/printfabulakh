/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abulakh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 21:05:31 by abulakh           #+#    #+#             */
/*   Updated: 2017/11/10 21:05:32 by abulakh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	t_list *k;
	t_list *m;

	if (!lst)
		return ;
	m = lst;
	k = lst->next;
	while (k != NULL)
	{
		k = lst->next;
		f(lst);
		lst = k;
	}
	lst = m;
}
