#include "ft_printf.h"

int	main()
{
	printf("[fake] : %% \n");
	printf("%d\n", ft_printf("%%"));
	printf("[original] : \n");
	printf("%d\n", printf("%%"));
	printf("\n");

	printf("[fake] : s \n");
	printf("%d\n", ft_printf("[%-*.*s]", 2, 3, "0"));
	printf("[original] : \n");
	printf("%d\n", printf("[%-*.*s]", 2, 3, "0"));
	printf("\n");

	printf("[fake] : x \n");
	printf("%d\n", ft_printf("[%-10x]", 12345));
	printf("[original] : \n");
	printf("%d\n", printf("[%-10x]", 12345));
	printf("\n");

	printf("[fake] : d \n");
	printf("%d\n", ft_printf("[%-10d]", 12345));
	printf("[original] : \n");
	printf("%d\n", printf("[%-10d]", 12345));
	printf("\n");

	printf("[fake] : -d \n");
	printf("%d\n", ft_printf("[%-10d]", -12345));
	printf("[original] : \n");
	printf("%d\n", printf("[%-10d]", -12345));
	printf("\n");

	printf("[fake] : c \n");
	printf("%d\n", ft_printf("[%-10c]", 'v'));
	printf("[original] : \n");
	printf("%d\n", printf("[%-10c]", 'v'));
	printf("\n");

	printf("[fake] : u \n");
	printf("%d\n", ft_printf("[%010u]", 5678));
	printf("[original] : \n");
	printf("%d\n", printf("[%010u]", 5678));
	printf("\n");

	printf("[fake] : p \n");
	printf("%d\n", ft_printf("[%-10p]", (void *)12345));
	printf("[original] : \n");
	printf("%d\n", printf("[%-10p]", (void *)12345));
	printf("\n");

//	printf("[%-.*d]\n", 10, 5, 123);
//	printf("[%0*.*d]\n", 10, 5, 123);
//	printf("[%0-*.*d]\n", 10, 5, 123);
//
//	printf("[%-*.*x]\n", 10, 8, 1996);
//	printf("[%.*x]\n", 8, 1996);
//	printf("[%x]\n\n", 1996);
//
//	printf("[%*X]\n", 8, 1996);
//	printf("[%.*X]\n", 8, 1996);
//	printf("[%X]\n\n", 1996);
//
//	printf("[%0*u]\n", 8, 222);
//	printf("[%0*.*u]\n", 10, 8, -222);
//	printf("[%u]\n\n", 222);
//
//	printf("1 [%s]\n", "abc");
//	printf("2 [%-s]\n", "abc");
//	printf("3 [%*s]\n", -4, "abc");
//	printf("4 [%.*s]\n", 2, "abc");
//	printf("5 [%-*s]\n", 4, "abc");
//	printf("%-3.s", NULL);
//
//	printf("7 [%-*.*s]\n", 10, 3, "abcde");
//	printf("8 [%*.*s]\n", 10, 3, "abcde");
//	printf("9 [%-*.*s]\n", 1, 7, "abcde");
//	printf("0 [%*.*s]\n", 1, 7, "abcde");
//
//
//	int i = 4;
//	int *pi = &i;
//	unsigned int d = 47;
//	unsigned int *pd = &d;
//
//	printf("[%p]\n", &pi);
//	printf("[%p]\n\n", &pd);

	return (0);
}
