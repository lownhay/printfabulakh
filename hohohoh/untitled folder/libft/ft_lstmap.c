/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abulakh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 16:46:35 by abulakh           #+#    #+#             */
/*   Updated: 2017/11/11 16:46:36 by abulakh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*end;
	t_list		*begin;
	t_list		*beg1;

	begin = ft_lstnew((f(lst))->content, (f(lst))->content_size);
	beg1 = begin;
	end = lst->next;
	while (end != NULL)
	{
		lst = lst->next;
		begin->next = ft_lstnew((f(lst))->content, (f(lst))->content_size);
		end = lst->next;
		begin = begin->next;
	}
	return (beg1);
}
