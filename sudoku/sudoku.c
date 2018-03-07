/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoku.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abulakh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/07 13:48:01 by abulakh           #+#    #+#             */
/*   Updated: 2018/03/07 13:48:02 by abulakh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

int g_k;

int ft_set_point(char ***table1, int x, int y, char c)
{
	int m;
	char **table;
	int k;

	m = 0;
	table = *table1;
	if (c == '.')
	{
		table[x][y] = c;
		return (1);
	}
	while (table[x][m])
	{
		if (table[x][m] == c)
			return (0);
		m++;
	}
	m = 0;
	while (m < 10)
	{
		if (table[m][y] == c)
			return (0);
		m++;
	}
	m = (x / 3) * 3;
	while (m < ((x / 3) * 3 + 3))
	{
		k = (y / 3) * 3;
		while (k < ((y / 3) * 3 + 3))
		{
			if (table[m][k] == c)
				return  (0);
			k++;
		}
		m++;
	}
	table[x][y] = c;
	return (1);
}

int ft_start_sudoku(char **table)
{
	int x;
	int y;
	int i;
	char num;
	char str[10];

	x = 0;
	i = 0;
	y = 0;
	g_k++;
	num = '1';
	// ft_putchar('\n');
	// while (table[i] && i < 9)
	// {
	// 	ft_putstr(table[i]);
	// 	ft_putchar('\n');
	// 	i++;
	// }
	//ft_putstr("check0\n");
	//ft_putchar('\n');
	// if (g_k == 20)
	// 	exit(1);
	while (x < 9 && table[x])
	{
		y = 0;
		while (y < 9 && table[x][y])
		{
			if (table[x][y] == '.')
			{
				while (num <= '9' && ft_set_point(&table, x, y, num) == 0)
					num++;
				//ft_putstr("check1\n");
				//ft_putnbr(g_k);
				//ft_putchar('\n');
				if (num > '9')
					return (0);
			//	ft_putstr("check2\n");
				if(ft_start_sudoku(table))
					return (1);
				else 
				{
					//ft_putstr("check4\n");
					ft_set_point(&table, x, y, '.');
					y--;
					num++;
					if (num > '9')
						return (0);
				}
				// if (g_k == 20)
				// 	exit(1);
			}
			y++;
		}
		x++;
	}
	return (1);
}

int main(int ac, char **av)
{
	char **table;
	int i;
	int m;
	i = 1;
	g_k = 0;
	if (ac != 10)
	{
		ft_putstr("Error1\n");
		return (0);
	}
	table = (char **)malloc(sizeof(char *) * 10);
	table[9] = "\0";
	while (i < ac)
	{
		if (ft_strlen(av[i]) != 9)
		{
			ft_putstr("Error2\n");
			return (0);
		}
		table[i - 1] = (char *)malloc(sizeof(char) * 10);
		table[i - 1] = ft_strcpy(table[i - 1], av[i]);
		i++;
	}
	i = 0;
	if (ft_start_sudoku(table))
	{
		while (i < 9 && table[i])
		{
			m = 0;
			while (table[i][m])
			{
				ft_putchar(table[i][m]);
				ft_putchar(' ');
				m++;
			}
			// ft_putstr(table[i]);
			ft_putchar('\n');
			i++;
		}
	}
	else
		ft_putstr("Error3\n");
	return(1);
}
//".6....7.." "8.9.6.5.." "245.1.8.." "...5....4" ".54...69." "3....6..." "..7.5.126" "..2.7.4.5" "..1....7."
// "........." "........." "........." "........." "........." "........." "........." "........." "........."
//"9...7...." "2...9..53" ".6..124.." "84...1.9." "5.....8.." ".31..4..." "..37..68." ".9..5.741" "47......." 