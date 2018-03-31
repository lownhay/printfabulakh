/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abulakh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 19:43:26 by abulakh           #+#    #+#             */
/*   Updated: 2018/02/24 19:43:26 by abulakh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H

# include "gnltry2/libft/libft.h"
# include <stdarg.h>
# include <wchar.h>

typedef struct	s_print
{
	int first[5];  // + # 0 ' ' -
	int width[3];
	int hhhllljz[6];
}				f_print;

typedef struct	s_fordi
{
	int mas[7];
	intmax_t no;
	signed char hh;
	short int	h;
	long int l;
	long long int ll;
	intmax_t j;
	size_t z;
}				f_fordi;

typedef struct	s_forouxX
{
	int mas[7];
	uintmax_t no;
	unsigned char hh;
	unsigned short int h;
	unsigned long int l;
	unsigned long long int ll;
	uintmax_t j;
	size_t z;
}				f_forouxX;

int ft_printf(const char *format, ...);

#endif