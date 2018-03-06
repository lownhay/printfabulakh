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

void ft_put_di_m(int m, intmax_t val, f_print mybaby)
{
	if (mybaby.first[0] == 1 && val > 0)
		ft_putchar('+');
	if (mybaby.first[0] == 0 && mybaby.first[3] == 1 && val > 0)
		ft_putchar(' ');
	while (mybaby.width[1] == 1 && m < mybaby.width[2])
	{
		ft_putchar('0');
		m++;
	}
	ft_putnbr(val);
}

void ft_put_DUO_m(int m, intmax_t val, f_print mybaby)
{
	if (mybaby.first[0] == 1 && val > 0)
		ft_putchar('+');
	if (mybaby.first[0] == 0 && mybaby.first[3] == 1 && val > 0)
		ft_putchar(' ');
	while (mybaby.width[1] == 1 && m < mybaby.width[2])
	{
		ft_putchar('0');
		m++;
	}
	ft_putnbr(val);
}

void ft_m_plus(int *m, char c)
{
	ft_putchar(c);
	(*m)++;
}

void ft_put_di_wd2(int m, intmax_t val, f_print mybaby)
{
	while (mybaby.width[0] > m && mybaby.width[0] > mybaby.width[2] && (mybaby.first[2] == 0 || mybaby.width[1] == 1))
	{
		ft_putchar(' ');
		mybaby.width[0]--;
	}
	if (mybaby.first[2] == 1 && mybaby.width[1] == 0 && mybaby.width[0] > mybaby.width[2])
		mybaby.width[2] = mybaby.width[0];
	if (mybaby.first[0] == 1 && val > 0)
		ft_putchar('+');
	if (mybaby.first[0] == 0 && mybaby.first[3] == 1 && val > 0)
		ft_putchar(' ');
	if (val < 0)
	{
		mybaby.first[0] = 1;
		ft_putchar('-');
		val *= -1;
	}
	while ((mybaby.width[1] == 1 && m < mybaby.width[2]) || (mybaby.first[2] == 1 && mybaby.width[1] == 0 && m < mybaby.width[2]))
		ft_m_plus(&m, '0');
	ft_putnbr(val);
}

void ft_put_di_wd(int m, intmax_t val, f_print mybaby)
{
	if (mybaby.first[0] == 1 || val < 0 || mybaby.first[3] == 1)
	{
		mybaby.width[2]++;
		m++;
	}
	if (mybaby.first[4] == 1)
	{
		if (mybaby.first[0] == 1 && val > 0)
			ft_putchar('+');
		if (mybaby.first[0] == 0 && mybaby.first[3] == 1 && val > 0)
			ft_putchar(' ');
		if (val < 0)
		{
			mybaby.first[0] = 1;
			ft_putchar('-');
			val *= -1;
		}
		while (mybaby.width[1] == 1 && m < mybaby.width[2])
			ft_m_plus(&m, '0');
		ft_putnbr(val);
		while (m < mybaby.width[0])
			ft_m_plus(&m, ' ');
	}
	else 
		ft_put_di_wd2(m, val, mybaby);
}

void ft_put_DUO_wd2(int m, intmax_t val, f_print mybaby)
{
	while (mybaby.width[0] > m && mybaby.width[0] > mybaby.width[2] && (mybaby.first[2] == 0 || mybaby.width[1] == 1))
	{
		ft_putchar(' ');
		mybaby.width[0]--;
	}
	if (mybaby.first[2] == 1 && mybaby.width[1] == 0 && mybaby.width[0] > mybaby.width[2])
		mybaby.width[2] = mybaby.width[0];
	if (mybaby.first[0] == 1 && val > 0)
		ft_putchar('+');
	if (mybaby.first[0] == 0 && mybaby.first[3] == 1 && val > 0)
		ft_putchar(' ');
	if (val < 0)
	{
		mybaby.first[0] = 1;
		ft_putchar('-');
		val *= -1;
	}
	while ((mybaby.width[1] == 1 && m < mybaby.width[2]) || (mybaby.first[2] == 1 && mybaby.width[1] == 0 && m < mybaby.width[2]))
		ft_m_plus(&m, '0');
	ft_putnbr(val);
}

void ft_put_DUO_wd(int m, intmax_t val, f_print mybaby)
{
	if (mybaby.first[0] == 1 || val < 0 || mybaby.first[3] == 1)
	{
		mybaby.width[2]++;
		m++;
	}
	if (mybaby.first[4] == 1)
	{
		if (mybaby.first[0] == 1 && val > 0)
			ft_putchar('+');
		if (mybaby.first[0] == 0 && mybaby.first[3] == 1 && val > 0)
			ft_putchar(' ');
		if (val < 0)
		{
			mybaby.first[0] = 1;
			ft_putchar('-');
			val *= -1;
		}
		while (mybaby.width[1] == 1 && m < mybaby.width[2])
			ft_m_plus(&m, '0');
		ft_putnbr(val);
		while (m < mybaby.width[0])
			ft_m_plus(&m, ' ');
	}
	else 
		ft_put_DUO_wd2(m, val, mybaby);
}

void ft_put_di2(intmax_t val, f_print mybaby)
{
	int m;
	intmax_t i;

	// printf("First\n+ = %d\n# = %d\n0 = %d\n' ' = %d\n - = %d\n", mybaby.first[0], mybaby.first[1], mybaby.first[2], mybaby.first[3], mybaby.first[4]);
	// printf("Width\nW = %d\nTch = %d\nlen = %d\n", mybaby.width[0], mybaby.width[1], mybaby.width[2]);
	// printf("Length\nhh = %d\nh = %d\nl = %d\nll = %d\nj = %d\nz = %d\n", mybaby.hhhllljz[0], mybaby.hhhllljz[1], mybaby.hhhllljz[2], mybaby.hhhllljz[3], mybaby.hhhllljz[4], mybaby.hhhllljz[5]);
	m = 0;
	i = val < 0 ? -val : val;
	while (i != 0)
	{
		i /= 10;
		m++;
	}
	if (m > mybaby.width[0])
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

void ft_put_DOU(f_print mybaby, va_list ap, char **format)
{
	intmax_t val;
	int m;
	intmax_t i;

	(*format)++;
	val = (long int)va_arg(ap, long int);
	m = 0;
	i = val < 0 ? -val : val;
	while (i != 0)
	{
		i /= 10;
		m++;
	}
	if (m > mybaby.width[0])
		ft_put_DUO_m(m, val, mybaby);
	else if (m < mybaby.width[0])
		ft_put_DUO_wd(m, val, mybaby);
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
	else if (ft_strchr("DOU", **format))
		ft_put_DOU(mybaby, ap, format);
	// else if (ft_strchr("ouxX", **format))
	// 	ft_put_ouxX(mybaby, ap);
	// else if (ft_strchr("c", **format))
	// 	ft_put_c(mybaby, ap);
	// else if (ft_strchr("C", **format))
	// 	ft_put_C(mybaby, ap);
	// else if (ft_strchr("s", **format))
	// 	ft_put_s(mybaby, ap);
	// else if (ft_strchr("S", **format))
	// 	ft_put_S(mybaby, ap);
	// else if (ft_strchr("p", **format))
	// 	ft_put_p(mybaby, ap);
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
	// printf("+ = %d\n# = %d\n0 = %d\n' ' = %d\n - = %d\nc = %c\n", mybaby.first[0], mybaby.first[1], mybaby.first[2], mybaby.first[3], mybaby.first[4], **format);
	// exit(1);
}

int ft_printf(const char *format, ...)
{
	char *str;

	str = (char *)format;
	va_list ap;
	va_start(ap, format);
	while (*str)
	{
		while (*str && *str != '%')
		{
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
			ft_putchar('%');
			str += 2;
		}
	}
	va_end(ap);
	return (1);
}
