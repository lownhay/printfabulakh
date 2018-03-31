/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_start.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abulakh <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 19:41:58 by abulakh           #+#    #+#             */
/*   Updated: 2018/02/24 19:41:59 by abulakh          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
int g_p;
int g_k;

int ft_print_1(char *format, int i)
{
	int k;

	k = 0;
	while (format[i + k] && format[i + k] != '%')
	{
		ft_putchar(format[i + k]);
		k++;
	}
	return (k);
}

void ft_val_fordi_zero(f_fordi *val, f_print mybaby)
{
	int i;

	i = 0;
	while (i < 7)
	{
		val->mas[i] = 0;
		i++;
	}
	if (mybaby.hhhllljz[0] == 1)
		val->mas[0] = 1;
	else if (mybaby.hhhllljz[1] == 1)
		val->mas[1] = 1;
	else if (mybaby.hhhllljz[2] == 1)
		val->mas[2] = 1;
	else if (mybaby.hhhllljz[3] == 1)
		val->mas[3] = 1;
	else if (mybaby.hhhllljz[4] == 1)
		val->mas[4] = 1;
	else if (mybaby.hhhllljz[5] == 1)
		val->mas[5] = 1;
	else
		val->mas[6] = 1;
}

void ft_m_plus(int *m, char c)
{
	ft_putchar(c);
	(*m)++;
}

void ft_m_minus(int *m, char c)
{
	ft_putchar(c);
	(*m)--;
}

void ft_put_di_m(int m, intmax_t val, f_print mybaby)
{
	if (mybaby.first[0] == 1 && val >= 0)
	{
		g_p++;
		ft_putchar('+');
	}
	if (mybaby.first[0] == 0 && mybaby.first[3] == 1 && val > 0)
	{
		g_p++;
		ft_putchar(' ');
	}
	if (val < 0)
	{
		g_p++;
		ft_putchar('-');
		val *= -1;
	}
	while (mybaby.width[1] == 1 && m < mybaby.width[2])
	{
		g_p++;
		ft_putchar('0');
		m++;
	}
	if (!(mybaby.width[1] == 1 && mybaby.width[2] == 0 && val == 0))
		g_p = g_p + ft_putnbr(val);
}


void ft_put_ouxX_m(int m, char *a, f_print mybaby, int base)
{
	if (mybaby.first[1] == 1 && base == 8)
	{
		g_p++;
		m++;
		ft_putchar('0');
	}
	else if (mybaby.first[1] == 1 && a[0] != '0' && base == 16)
	{
		g_p += 2;
		m += 2;
		ft_putchar('0');
		ft_putchar('x');
	}
	else if (mybaby.first[1] == 1 && a[0] != '0' && base == 17)
	{
		g_p += 2;
		m += 2;
		ft_putchar('0');
		ft_putchar('X');
	}
	while (mybaby.width[1] == 1 && m < mybaby.width[2])
	{
		g_p++;
		ft_putchar('0');
		m++;
	}
	if (!((mybaby.width[2] == 0 && a[0] == '0') || (mybaby.first[1] == 1 && a[0] == '0' && base == 8)))
	{
		//ft_putstr("\ncheck((\n");
		g_p = g_p + ft_strlen(a);
		ft_putstr(a);
	}
}

void ft_put_ouxX_wd2(int m, char *a, f_print mybaby, int base)
{
	while (mybaby.width[0] > (m + mybaby.first[1]) && ((base != 16 && base != 17 && mybaby.width[0] > (mybaby.width[2] + mybaby.first[1])) || ((mybaby.width[0] > (mybaby.width[2] + mybaby.first[1] + mybaby.first[1]) && (base == 16 || base == 17)))) && (mybaby.first[2] == 0 || mybaby.width[1] == 1))
	{
		g_p++;
		ft_putchar(' ');
		mybaby.width[0]--;
		if ((mybaby.first[1] == 1 && mybaby.width[0] == (mybaby.width[2] - 1)) || (mybaby.width[0] == (m + 2) && base == 16 && mybaby.first[1] == 1))
			break ;
	}
	if (mybaby.first[2] == 1 && mybaby.width[1] == 0 && mybaby.width[0] > mybaby.width[2])
		mybaby.width[2] = mybaby.width[0];
	if (mybaby.first[1] == 1 && a[0] != '0' && base == 8)
	{
		g_p++;
		ft_m_minus(&(mybaby.width[0]), '0');
	}
	else if (mybaby.first[1] == 1 && a[0] != '0' && base == 16)
	{
		g_p += 2;
		m += 2;
		mybaby.width[2] += 2;
		if (mybaby.first[2] == 1)
			mybaby.width[2] -= 2;
		ft_m_minus(&(mybaby.width[0]), '0');
		ft_m_minus(&(mybaby.width[0]), 'x');
	}
	else if (mybaby.first[1] == 1 && a[0] != '0' && base == 17)
	{
		g_p += 2;
		m += 2;
		mybaby.width[2] += 2;
		if (mybaby.first[2] == 1)
			mybaby.width[2] -= 2;
		ft_m_minus(&(mybaby.width[0]), '0');
		ft_m_minus(&(mybaby.width[0]), 'X');
	}
	while ((mybaby.width[1] == 1 && m < mybaby.width[2]) || (mybaby.first[2] == 1 && mybaby.width[1] == 0 && m < mybaby.width[2]))
	{
		g_p++;
		ft_m_plus(&m, '0');
	}
	if (!(mybaby.width[1] == 1 && mybaby.width[2] == 0 && a[0] == '0'))
	{
		g_p = g_p + ft_strlen(a);
		ft_putstr(a);
	}
	else if (mybaby.width[1] == 1 && mybaby.width[2] == 0 && mybaby.width[0] > 0 && a[0] == '0')
	{
		g_p += 1;
		ft_putchar(' ');
	}
}

void ft_put_ouxX_wd(int m, char *a, f_print mybaby, int base)
{
	int d;

	if (mybaby.first[4] == 1)
	{
		if (mybaby.first[1] == 1 && base == 8)
		{
			g_p++;
			ft_m_plus(&m, '0');
		}
		else if (mybaby.first[1] == 1 && base == 16)
		{
			g_p += 2;
			ft_m_plus(&m, '0');
			ft_m_plus(&m, 'x');
		}
		else if (mybaby.first[1] == 1 && base == 17)
		{
			g_p += 2;
			ft_m_plus(&m, '0');
			ft_m_plus(&m, 'X');
		}
		while (mybaby.width[1] == 1 && m < mybaby.width[2])
		{
			g_p++;
			ft_m_plus(&m, '0');
		}
		d = ft_strlen(a);
		g_p = g_p + d;
		ft_putstr(a);
		while (m < mybaby.width[0])
		{
			g_p++;
			ft_m_plus(&m, ' ');
		}
	}
	else 
		ft_put_ouxX_wd2(m, a, mybaby, base);
}

void ft_put_di_wd2(int m, intmax_t val, f_print mybaby)
{
	while (mybaby.width[0] > m && mybaby.width[0] > mybaby.width[2] && (mybaby.first[2] == 0 || mybaby.width[1] == 1))
	{
		g_p++;
		ft_putchar(' ');
		mybaby.width[0]--;
		if ((mybaby.first[0] == 1 || mybaby.first[3] == 1) && mybaby.width[0] == (mybaby.width[2] - 1))
			break ;
	}
	if (mybaby.first[2] == 1 && mybaby.width[1] == 0 && mybaby.width[0] > mybaby.width[2])
		mybaby.width[2] = mybaby.width[0];
	if (mybaby.first[0] == 1 && val >= 0)
	{
		g_p++;
		ft_m_minus(&(mybaby.width[0]), '+');
	}
	if (mybaby.first[0] == 0 && mybaby.first[3] == 1 && val >= 0)
	{
		g_p++;
		ft_m_minus(&(mybaby.width[0]), ' ');
	}
	if (val < 0)
	{
		g_p++;
		val *= -1;
		ft_m_minus(&(mybaby.width[0]), '-');
	}
	while ((mybaby.width[1] == 1 && m < mybaby.width[2]) || (mybaby.first[2] == 1 && mybaby.width[1] == 0 && m < mybaby.width[2]))
	{
		g_p++;
		ft_m_plus(&m, '0');
	}
	if (!(mybaby.width[2] == 0 && mybaby.width[1] == 1 && val == 0))
		g_p = g_p + ft_putnbr(val);
	else
	{
		g_p++;
		ft_putchar(' ');
	}
}

void ft_put_di_wd(int m, intmax_t val, f_print mybaby)
{
	int d;

	if (mybaby.first[0] == 1 || val < 0 || mybaby.first[3] == 1)
	{
		mybaby.width[2]++;
		m++;
	}
	if (mybaby.first[4] == 1)
	{
		if (mybaby.first[0] == 1 && val > 0)
		{
			g_p++;
			ft_putchar('+');
		}
		if (mybaby.first[0] == 0 && mybaby.first[3] == 1 && val > 0)
		{
			g_p++;
			ft_putchar(' ');
		}
		if (val < 0)
		{
			g_p++;
			mybaby.first[0] = 1;
			ft_putchar('-');
			val *= -1;
		}
		while (mybaby.width[1] == 1 && m < mybaby.width[2])
		{
			g_p++;
			ft_m_plus(&m, '0');
		}
		d = ft_putnbr(val);
		g_p = g_p + d;
		while (m < mybaby.width[0])
		{
			g_p++;
			ft_m_plus(&m, ' ');
		}
	}
	else 
		ft_put_di_wd2(m, val, mybaby);
}

void ft_put_di2(intmax_t val, f_print mybaby)
{
	int m;
	intmax_t i;

	m = 0;
	i = val < 0 ? -val : val;
	while (i != 0)
	{
		i /= 10;
		m++;
	}
	if (val == 0)
		m = 1;
	if (m >= mybaby.width[0])
		ft_put_di_m(m, val, mybaby);
	else if (m < mybaby.width[0])
		ft_put_di_wd(m, val, mybaby);
}

void ft_put_di(f_print mybaby, va_list ap, char **format)
{
	intmax_t val;

	(*format)++;
	if (mybaby.hhhllljz[0] == 1)
		val = (signed char)va_arg(ap, int);
	else if (mybaby.hhhllljz[1] == 1)
		val = (short int)va_arg(ap, int);
	else if (mybaby.hhhllljz[2] == 1)
		val = (long int)va_arg(ap, long int);
	else if (mybaby.hhhllljz[3] == 1)
		val = (long long int)va_arg(ap, long long int);
	else if (mybaby.hhhllljz[4] == 1)
		val = (intmax_t)va_arg(ap, intmax_t);
	else if (mybaby.hhhllljz[5] == 1)
		val = (size_t)va_arg(ap, size_t);
	else
		val = (int)va_arg(ap, int);
	ft_put_di2(val, mybaby);
}

void ft_put_ouxX2(uintmax_t val, f_print mybaby, int base)
{
	int m;
	char *a;

	m = 0;
	if (base != 17)
		a = ft_itoa_base(val, base, 0);
	else 
		a = ft_itoa_base(val, base - 1, 1);
	m = ft_strlen(a);
	if (m >= mybaby.width[0])
		ft_put_ouxX_m(m, a, mybaby, base);
	else if (m < mybaby.width[0])
		ft_put_ouxX_wd(m, a, mybaby, base);
}

void ft_put_DU(f_print mybaby, va_list ap, char **format)
{
	intmax_t val;
	uintmax_t val2;
	int m;
	intmax_t i;

	m = 0;
	val2 = 0;
	val = 0;
	if (**format == 'D')
	{
		val = (long int)va_arg(ap, long int);
		i = val < 0 ? -val : val;
		while (i != 0)
		{
			i /= 10;
			m++;
		}
		if (val == 0)
			m = 1;
		(*format)++;
		if (m >= mybaby.width[0])
			ft_put_di_m(m, val, mybaby);
		else if (m < mybaby.width[0])
			ft_put_di_wd(m, val, mybaby);
	}
	else 
	{
		(*format)++;
		val2 = (unsigned long int)va_arg(ap, unsigned long int);
		ft_put_ouxX2(val2, mybaby, 10);
	}
}

void ft_put_ouxX(f_print mybaby, va_list ap, char **format)
{
	uintmax_t val;

	if (mybaby.hhhllljz[0] == 1)
		val = (unsigned char)va_arg(ap, int);
	else if (mybaby.hhhllljz[1] == 1)
		val = (unsigned short int)va_arg(ap, int);
	else if (mybaby.hhhllljz[2] == 1)
		val = (unsigned long int)va_arg(ap, unsigned long int);
	else if (mybaby.hhhllljz[3] == 1)
		val = (unsigned long long int)va_arg(ap, unsigned long long int);
	else if (mybaby.hhhllljz[4] == 1)
		val = (uintmax_t)va_arg(ap, uintmax_t);
	else if (mybaby.hhhllljz[5] == 1)
		val = (size_t)va_arg(ap, size_t);
	else
		val = (unsigned int)va_arg(ap, unsigned int);
	if (**format == 'o')
		ft_put_ouxX2(val, mybaby, 8);
	else if (**format == 'x')
		ft_put_ouxX2(val, mybaby, 16);
	else if (**format == 'X')
		ft_put_ouxX2(val, mybaby, 17);
	else if (**format == 'u')
		ft_put_ouxX2(val, mybaby, 10);
	(*format)++;
}

void ft_put_Oblya(f_print mybaby, va_list ap, char **format)
{
	long int val;
	char *a;
	int m;
	int base;

	base = 8;
	val = (long int)va_arg(ap, long int);
	(*format)++;
	a = ft_itoa_base(val, base, 0);
	m = ft_strlen(a);
	if (m >= mybaby.width[0])
		ft_put_ouxX_m(m, a, mybaby, base);
	else if (m < mybaby.width[0])
		ft_put_ouxX_wd(m, a, mybaby, base);
}

void ft_put_c2wc(wchar_t a, f_print mybaby) /// КАКАЯ-ТО ДИЧЬ ХЗ ЧТО С НЕЙ ДЕЛАТЬ, ИСПРАВЛЮ ПОТОМ
{
	if (mybaby.first[4] == 0)
	{
		while (mybaby.width[0] > 1)
		{
			ft_m_minus(&(mybaby.width[0]), ' ');
			g_p++;
		}
		write(1, &a, 1);
		//ft_putwchar(a);
		g_p++;
	}
	else 
	{
		write(1, &a, 1);
		//ft_putwchar(a);
		g_p++;
		while (mybaby.width[0] > 1)
		{
			ft_m_minus(&(mybaby.width[0]), ' ');
			g_p++;
		}
	}
}

void ft_put_c2ch(char a, f_print mybaby)
{
	char ag;

	ag = ' ';
	if (mybaby.first[2] == 1)
		ag = '0';
	if (mybaby.first[4] == 0)
	{
		while (mybaby.width[0] > 1)
		{
			ft_m_minus(&(mybaby.width[0]), ag);
			g_p++;
		}
		ft_putchar(a);
		g_p++;
	}
	else 
	{
		ft_putchar(a);
		g_p++;
		while (mybaby.width[0] > 1)
		{
			ft_m_minus(&(mybaby.width[0]), ag);
			g_p++;
		}
	}
}

void ft_put_c(f_print mybaby, va_list ap, char **format)
{
	wchar_t a;
	char a2;

	a2 = 0;
	a = 0;
	if (mybaby.hhhllljz[0] == 1 || mybaby.hhhllljz[1] == 1 || mybaby.hhhllljz[2] == 1 || mybaby.hhhllljz[3] == 1 ||
	mybaby.hhhllljz[4] == 1 || mybaby.hhhllljz[5] == 1)
	{
		a = (wchar_t)va_arg(ap, wint_t);
		(*format)++;
		ft_put_c2wc(a, mybaby);
	}
	else
	{
		a2 = (char)va_arg(ap, unsigned int);
		(*format)++;
		ft_put_c2ch(a2, mybaby);
	}
}

void ft_put_C(f_print mybaby, va_list ap, char **format) /// ТОЖЕ КАКАЯ-ТО ХРЕНЬ НЕ ПОЙМУ КАК ДЕЛАТЬ
{
	wchar_t a;

	a = (wchar_t)va_arg(ap, wint_t);
	(*format)++;
	ft_put_c2wc(a, mybaby);
}

void ft_put_s2ch(char *a, f_print mybaby)
{
	char ag;
	int m;

	if (a == NULL)
	{
		a = ft_strdup("(null)");
		m = 6;
	}
	else
		m = ft_strlen(a);
	ag = ' ';
	if (mybaby.first[2] == 1)
		ag = '0';
	if (mybaby.first[4] == 0)
	{
		while (mybaby.width[0] > m || (mybaby.width[1] == 1 && mybaby.width[0] > mybaby.width[2]))
		{
			ft_m_minus(&(mybaby.width[0]), ag);
			g_p++;
		}
		if (mybaby.width[1] == 0)
		{
			if (a != NULL)
			{
				ft_putstr(a);
				g_p += m;
				mybaby.width[0] -= m;
			}
		}
		while (mybaby.width[1] == 1 && mybaby.width[2] > 0 && a != NULL && *a != '\0')
		{
			ft_putchar(*a);
			(mybaby.width[2])--;
			a++;
			g_p++;
		}
	}
	else 
	{
		while (mybaby.width[1] == 1 && mybaby.width[2] > 0 && a != NULL && *a != '\0')
		{
			ft_putchar(*a);
			(mybaby.width[2])--;
			(mybaby.width[0])--;
			a++;
			g_p++;
		}
		if (mybaby.width[1] == 0)
		{
			if (a != NULL)
			{
				ft_putstr(a);
				g_p += m;
				mybaby.width[0] -= m;
			}
		}
		while (mybaby.width[0] > 0)
		{
			ft_m_minus(&(mybaby.width[0]), ag);
			g_p++;
		}
	}
}

void ft_put_s(f_print mybaby, va_list ap, char **format)
{
	wchar_t *a;
	char *a2;

	a2 = NULL;
	a = NULL;
	if (mybaby.hhhllljz[0] == 1 || mybaby.hhhllljz[1] == 1 || mybaby.hhhllljz[2] == 1 || mybaby.hhhllljz[3] == 1 ||
	mybaby.hhhllljz[4] == 1 || mybaby.hhhllljz[5] == 1)
	{
		a = (wchar_t *)va_arg(ap, wchar_t *);
		(*format)++;
		//ft_put_s2wc(a, mybaby);
	}
	else
	{
		a2 = (char *)va_arg(ap, char *);
		(*format)++;
		ft_put_s2ch(a2, mybaby);
	}
}

void ft_put_p2(char *a, f_print mybaby)
{
	char ag;
	int m;

	if (a == NULL)
	{
		a = ft_strdup("(null)");
		m = 6;
	}
	else
		m = ft_strlen(a);
	ag = ' ';
	if (mybaby.first[2] == 1)
		ag = '0';
	if (mybaby.first[4] == 0)
	{
		while (mybaby.width[0] > m || (mybaby.width[1] == 1 && mybaby.width[0] > mybaby.width[2]))
		{
			ft_m_minus(&(mybaby.width[0]), ag);
			g_p++;
		}
		if (mybaby.width[1] == 0)
		{
			if (a != NULL)
			{
				ft_putstr(a);
				g_p += m;
				mybaby.width[0] -= m;
			}
		}
		while (mybaby.width[1] == 1 && mybaby.width[2] > 0 && a != NULL && *a != '\0')
		{
			ft_putchar(*a);
			(mybaby.width[2])--;
			a++;
			g_p++;
		}
	}
	else 
	{
		while (mybaby.width[1] == 1 && mybaby.width[2] > 0 && a != NULL && *a != '\0')
		{
			ft_putchar(*a);
			(mybaby.width[2])--;
			(mybaby.width[0])--;
			a++;
			g_p++;
		}
		if (mybaby.width[1] == 0)
		{
			if (a != NULL)
			{
				ft_putstr(a);
				g_p += m;
				mybaby.width[0] -= m;
			}
		}
		while (mybaby.width[0] > 0)
		{
			ft_m_minus(&(mybaby.width[0]), ag);
			g_p++;
		}
	}
}

void ft_put_p(f_print mybaby, va_list ap, char **format)
{
	void *a;
	void **jk;
	int i;
	unsigned char *k;
	char *str;

	i = 0;
	a = (void *)va_arg(ap, void *);
	mybaby.first[1] = 0;
	(*format)++;
	jk = &a;
	k = (unsigned char *)(a);
	write(1, "0x", 2);
	while (i < 1)
	{
		str = ft_itoa_base((*k), 16, 0);
		//ft_putstr("check1\n");
		ft_putstr(str);
		//k++;
		i++;
	}
}

void ft_baby_zero(f_print *mybaby)
{
	mybaby->first[0] = 0;
	mybaby->first[1] = 0;
	mybaby->first[2] = 0;
	mybaby->first[3] = 0;
	mybaby->first[4] = 0;
	mybaby->width[0] = -1;
	mybaby->width[1] = 0;
	mybaby->width[2] = -1;
	mybaby->hhhllljz[0] = 0;
	mybaby->hhhllljz[1] = 0;
	mybaby->hhhllljz[2] = 0;
	mybaby->hhhllljz[3] = 0;
	mybaby->hhhllljz[4] = 0;
	mybaby->hhhllljz[5] = 0;
}

void ft_type_field(f_print mybaby, va_list ap, char **format)
{

	if (ft_strchr("di", **format))
		ft_put_di(mybaby, ap, format);
	else if (ft_strchr("DU", **format))
		ft_put_DU(mybaby, ap, format);
	else if (ft_strchr("oxuX", **format))
		ft_put_ouxX(mybaby, ap, format);
	else if (ft_strchr("O", **format))
		ft_put_Oblya(mybaby, ap, format);
	else if (ft_strchr("c", **format))
		ft_put_c(mybaby, ap, format);
	else if (ft_strchr("C", **format))
		ft_put_C(mybaby, ap, format);
	else if (ft_strchr("s", **format))
		ft_put_s(mybaby, ap, format);
	// else if (ft_strchr("S", **format))
	// 	ft_put_S(mybaby, ap);
	else if (ft_strchr("p", **format))
		ft_put_p(mybaby, ap, format);
}

void ft_length_mod(f_print mybaby, va_list ap, char **format)
{
	
	if (**format == 'h' && *(*format + 1) == 'h')
		mybaby.hhhllljz[0] = 1;
	else if (**format == 'h' && *(*format + 1) != 'h')
		mybaby.hhhllljz[1] = 1;
	else if (**format == 'l' && *(*format + 1) != 'l')
		mybaby.hhhllljz[2] = 1;
	else if (**format == 'l' && *(*format + 1) == 'l')
		mybaby.hhhllljz[3] = 1;
	else if (**format == 'j')
		mybaby.hhhllljz[4] = 1;
	else if (**format == 'z')
		mybaby.hhhllljz[5] = 1;
	if (mybaby.hhhllljz[0] == 1 || mybaby.hhhllljz[3] == 1)
		*format += 2;
	else if (mybaby.hhhllljz[1] == 1  || mybaby.hhhllljz[2] == 1 || mybaby.hhhllljz[4] == 1 || mybaby.hhhllljz[5] == 1)
		(*format)++;
	ft_type_field(mybaby, ap, format);
}

void ft_width_func(f_print mybaby, va_list ap, char **format)
{
	// mybaby.width[0] = -1;
	// mybaby.width[1] = 0;
	// mybaby.width[2] = -1;
	if (**format >= '0' && **format <= '9')
		mybaby.width[0] = ft_atoi(*format);
	else if (**format == '*')
		mybaby.width[0] = va_arg(ap, int);
	else 
		mybaby.width[0] = 0;
	while ((**format >= '0' && **format <= '9') || **format == '*')
		(*format)++;
	if (**format == '.')
	{
		mybaby.width[1] = 1;
		(*format)++;
	}
	if (**format >= '0' && **format <= '9')
		mybaby.width[2] = ft_atoi(*format);
	else if (**format == '*')
		mybaby.width[2] = va_arg(ap, int);
	else if (mybaby.width[1] == 1)
		mybaby.width[2] = 0;
	while ((**format >= '0' && **format <= '9') || **format == '*')
		(*format)++;
	ft_length_mod(mybaby, ap, format);
}

void ft_start_va(char **format, va_list ap)
{
	f_print mybaby;
	
	ft_baby_zero(&mybaby);
	// mybaby.first[0] = 0;
	// mybaby.first[1] = 0;
	// mybaby.first[2] = 0;
	// mybaby.first[3] = 0;
	// mybaby.first[4] = 0;
	while(ft_strchr("+#0 -", **format))
	{
		if (**format == '+')
			mybaby.first[0] = 1;
		if (**format == '#')
			mybaby.first[1] = 1;
		if (**format == '0')
			mybaby.first[2] = 1;
		if (**format == ' ')
			mybaby.first[3] = 1;
		if (**format == '-')
			mybaby.first[4] = 1;
		(*format)++;
	}
	ft_width_func(mybaby, ap, &(*format));
}

int ft_printf(const char *format, ...)
{
	char *str;

	g_p = 0;
	str = (char *)format;
	va_list ap;
	va_start(ap, format);
	while (*str)
	{
		while (*str && *str != '%')
		{
			g_p++;
			ft_putchar(*str);
			str++;
		}
		if (*str == '%' && *(str + 1) != '%')
		{
			str++;
			ft_start_va(&str, ap);
		}
		else if (*str == '%' && *(str + 1) == '%')
		{
			g_p++;
			ft_putchar('%');
			str += 2;
		}
	}
	va_end(ap);
	return (g_p);
}
