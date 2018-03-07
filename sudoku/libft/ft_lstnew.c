/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abulakh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 18:15:56 by abulakh           #+#    #+#             */
/*   Updated: 2017/11/10 18:15:56 by abulakh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	del_list(t_list **putlist)
{
	t_list	*klist;

	klist = *putlist;
	free(klist->content);
	klist->content = NULL;
	klist->content_size = 0;
	free(klist);
	klist = NULL;
}

t_list		*ft_lstnew(void const *content, size_t content_size)
{
	t_list *klist;

	klist = (t_list *)malloc(sizeof(t_list));
	if (!klist)
		return (NULL);
	if (!content)
	{
		klist->content = NULL;
		klist->content_size = 0;
	}
	else
	{
		klist->content = malloc(content_size);
		if (!klist->content)
		{
			del_list(&klist);
			return (NULL);
		}
		ft_memcpy(klist->content, content, content_size);
		klist->content_size = content_size;
	}
	klist->next = NULL;
	return (klist);
}
