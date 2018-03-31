#include <stdio.h>
#include "ft_printf.h"
#include <limits.h>

int main(void)
{
	char a;

	a = '&';
	//unsigned long int k = ULONG_MAX;
	// ft_printf("%o\n", 0);
	// printf("%o\n", 0);
	//int i = ft_printf("{%-15Z}\n", 123);
	//int j = printf("{%-15Z}\n", 123);
	//ft_printf("i %d j %d\n", i, j);
	// printf("{%010c}\n", 'A');
	// ft_printf("{%010c}\n", 'A');
	// printf("%lc, %lc\n", L'ÊM-^ZM-^V', L'ÿ≠');
	// ft_printf("%lc, %lc\n", L'ÊM-^ZM-^V', L'ÿ≠');
	// ft_printf("{%-10s}\n", NULL);
	// printf("{%-10s}\n", NULL);
	// printf("%lc\n", 'c');
	// ft_printf("%lc\n", 'c');
	//printf("%hhC, %hhC\n", 0, L'Á±≥');
	printf("{%p}\n", &a);
	ft_printf("{%p}\n", &a);
	printf("{%p}\n", NULL);
	// printf("{%#20.5x}\n", 49872);
	// ft_printf("{%#20.5x}\n", 49872);
	// printf("{%#20.5X}\n", 49872);
	// ft_printf("{%#20.5X}\n", 49872);
	// printf("{%#20.2x}\n", 49872);
	// ft_printf("{%#20.2x}\n", 49872);
	// printf("{%#20.7x}\n", 49872);
	// ft_printf("{%#20.7x}\n", 49872);
	// printf("{%15.4x}\n", 42);
	// ft_printf("{%15.4x}\n", 42);
	return (0);
}