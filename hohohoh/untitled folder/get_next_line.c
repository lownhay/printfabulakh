/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abulakh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 18:26:36 by abulakh           #+#    #+#             */
/*   Updated: 2018/02/07 18:26:37 by abulakh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	func1(t_line **lup2, int fd, char **line, char ***str)
{
	int		ret;
	t_line	*lup;

	lup = *lup2;
	if (!line || BUFF_SIZE <= 0 || fd < 0 || (ret = read(fd, (*str)[0], 0)) < 0)
	{
		free((*str)[0]);
		free(*str);
		return (-1);
	}
	ret = 0;
	*line = NULL;
	while (lup != NULL && lup->next != NULL && lup->content_size != fd
		&& (lup->next)->content_size != fd)
		lup = lup->next;
	if (lup != NULL && lup->next != NULL && (lup->next)->content_size == fd)
		lup = lup->next;
	if (lup == NULL || (lup != NULL && lup->next == NULL
		&& lup->content_size != fd) || (lup != NULL &&
		lup->content_size == fd && !(ft_strchr(lup->content, '\n'))))
		ret = read(fd, (*str)[0], BUFF_SIZE);
	((*str)[0])[ret] = '\0';
	*lup2 = lup;
	return (ret);
}

static void	func2(t_line **lup, char ***str, int ret[2], t_line **begin)
{
	if (ret[0] > 0)
	{
		if (*lup == NULL)
		{
			*lup = (t_line *)malloc(sizeof(t_line));
			*begin = *lup;
		}
		else if ((*lup)->next == NULL && (*lup)->content_size != ret[1])
		{
			(*lup)->next = (t_line *)malloc(sizeof(t_line));
			(*lup) = (*lup)->next;
		}
		else
		{
			(*str)[1] = ft_strjoin((*lup)->content, (*str)[0]);
			free((*lup)->freesh);
			(*lup)->content = (*str)[1];
			(*lup)->freesh = (*lup)->content;
			return ;
		}
		(*lup)->content = ft_strdup((*str)[0]);
		(*lup)->content_size = ret[1];
		(*lup)->freesh = (*lup)->content;
		(*lup)->next = NULL;
	}
}

static int	func3(int ret, t_line **lup2, char ***str)
{
	t_line *lup;

	lup = *lup2;
	if (ret <= 0 && lup != NULL && lup->freesh == NULL)
	{
		free((*str)[0]);
		free(*str);
		return (0);
	}
	if (ret <= 0 && (lup == NULL || *((lup->content) - 1) == '\0'
		|| ft_strlen((lup->content)) == 0))
	{
		if (lup != NULL && lup->freesh != NULL)
		{
			free(lup->freesh);
			lup->freesh = NULL;
		}
		free((*str)[0]);
		free(*str);
		return (0);
	}
	*lup2 = lup;
	return (1);
}

static void	func4(t_line **lup2, int fd, char *str, char **line)
{
	char	*str2;
	int		m[2];
	t_line	*lup;

	lup = *lup2;
	if (!ft_strchr(lup->content, '\n'))
		while ((m[0] = read(fd, str, BUFF_SIZE)))
		{
			m[1] = 0;
			str[m[0]] = '\0';
			str2 = ft_strjoin((lup->content), str);
			free(lup->freesh);
			lup->content = str2;
			lup->freesh = lup->content;
			while ((lup->content)[m[1]] && (lup->content)[m[1]] != '\n')
				m[1]++;
			if ((lup->content)[m[1]] == '\n')
				break ;
			ft_strclr(str);
		}
	ft_strclr(str);
	m[1] = 0;
	while (((lup->content))[m[1]] != '\n' && ((lup->content))[m[1]] != '\0')
		m[1]++;
	*line = ft_strsub((lup->content), 0, m[1]);
}

int			get_next_line(const int fd, char **line)
{
	static t_line	*lup;
	t_line			*begin;
	char			**str;
	int				ret[2];

	begin = lup;
	ret[1] = fd;
	str = (char **)malloc(sizeof(char *) * 2);
	str[0] = (char *)malloc(sizeof(char) * (BUFF_SIZE + 1));
	str[1] = NULL;
	ret[0] = func1(&lup, ret[1], line, &str);
	if (ret[0] == -1)
		return (-1);
	func2(&lup, &str, ret, &begin);
	ft_strclr(str[0]);
	if (func3(ret[0], &lup, &str) == 0)
		return (0);
	func4(&lup, fd, str[0], line);
	while (*((lup->content)) != '\n' && *((lup->content)) != '\0')
		(lup->content)++;
	(lup->content)++;
	free(str[0]);
	lup = begin;
	free(str);
	return (1);
}
