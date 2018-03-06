/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abulakh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 18:19:11 by abulakh           #+#    #+#             */
/*   Updated: 2017/10/30 18:19:11 by abulakh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**func1(char *l, char **k, char c)
{
	int		i;
	int		p;

	i = 0;
	p = 0;
	while (l[i])
	{
		while (l[i] == c && l[i] != '\0')
			i++;
		if (l[i] != c && l[i] != '\0')
			p++;
		while (l[i] != c && l[i] != '\0')
			i++;
	}
	k = (char **)malloc(sizeof(char *) * (p + 1));
	if (!k)
		return (0);
	k[p] = 0;
	return (k);
}

static char	**func2(char *l, char **k, char c, int i)
{
	int		p;
	int		t;

	t = 0;
	while (l[i])
	{
		p = 0;
		while (l[i] == c && l[i] != '\0')
			i++;
		while (l[i] != c && l[i] != '\0')
		{
			p++;
			i++;
		}
		if (p > 0)
		{
			k[t] = (char *)malloc(sizeof(char **) * (p + 1));
			if (!k[t])
				return (0);
			k[t][p] = 0;
			t++;
		}
	}
	return (k);
}

static char	**func3(char *l, char **k, char c)
{
	int		i;
	int		p;
	int		t;

	i = 0;
	p = 0;
	t = 0;
	while (l[i])
	{
		while (l[i] == c && l[i] != '\0')
			i++;
		while (l[i] != c && l[i] != '\0')
		{
			k[t][p] = l[i];
			p++;
			i++;
		}
		t++;
		p = 0;
	}
	return (k);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**k;
	char	*l;

	if (!s)
		return (NULL);
	l = (char *)s;
	k = NULL;
	k = func1(l, k, c);
	if (!k)
		return (0);
	k = func2(l, k, c, 0);
	if (!k)
	{
		ft_free_split(k);
		return (0);
	}
	k = func3(l, k, c);
	if (!k)
		return (0);
	return (k);
}
