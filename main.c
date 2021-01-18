#include <stdio.h>
#include "ft_printf.h"

int	main()
{

	printf("LOL\n\n\n\n");
	printf("[fake] : \n");
	printf("%d\n", ft_printf("write [%-*d] int\n", 5, -123));
	printf("\n");
	printf("[original] : \n");
	printf("%d\n", printf("write [%-*d] int\n", 5, -123));
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
*/
	printf("[%0*u]\n", 8, 222);
	printf("[%0*.*u]\n", 10, 8, -222);
	printf("[%u]\n\n", 222);
/*
	printf("[%*s]\n", 4, "abcdefg");
	printf("[%.*s]\n", 1, "abcdefg");
	printf("[%s]\n", "abcdefg");
	printf("[%*.*s]\n\n", -8, 2, "abcdefg");
	
	printf("[%-*.*c]\n", 4, 3, 'v');
	printf("[%-c]\n", 'v');
	printf("[%*c]\n\n", 4, 'v');
*/
//	printf("[%-*p]\n", 20, "123");

//	printf("%d", printf("%-d", 123));

//	printf( "%d", printf("%%d\n"));
	return (0);
}
