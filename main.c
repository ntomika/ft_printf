#include "ft_printf.h"

int	main()
{

	printf("[fake] : \n");
	printf("%d\n", ft_printf("%8.5d", 34));
	printf("\n");
	printf("[original] : \n");
	printf("%d\n", printf("%8.5d", 34));
	printf("\n");

/*
	printf("[%-.*d]\n", 10, 5, 123);
	printf("[%0*.*d]\n", 10, 5, 123);
	printf("[%0-*.*d]\n", 10, 5, 123);

	printf("[%-*.*x]\n", 10, 8, 1996);
	printf("[%.*x]\n", 8, 1996);
	printf("[%x]\n\n", 1996);

	printf("[%*X]\n", 8, 1996);
	printf("[%.*X]\n", 8, 1996);
	printf("[%X]\n\n", 1996);

	printf("[%0*u]\n", 8, 222);
	printf("[%0*.*u]\n", 10, 8, -222);
	printf("[%u]\n\n", 222);

	printf("1 [%s]\n", "abc");
	printf("2 [%-s]\n", "abc");
	printf("3 [%*s]\n", 4, "abc");
	printf("4 [%.*s]\n", 2, "abc");
	printf("5 [%-*s]\n", 4, "abc");
	printf("6 [%-.*s]\n", 2, "abc");

	printf("7 [%-*.*s]\n", 10, 3, "abcde");
	printf("8 [%*.*s]\n", 10, 3, "abcde");
	printf("9 [%-*.*s]\n", 1, 7, "abcde");
	printf("0 [%*.*s]\n", 1, 7, "abcde");


	printf("[%-*.*c]\n", 4, 3, 'v');
	printf("[%-c]\n", 'v');
	printf("[%*c]\n\n", 4, 'v');
*/
//	printf("[%-*p]\n", 20, "123");

//	printf("%d", printf("%-d", 123));

//	printf( "%d", printf("%%d\n"));
	return (0);
}
