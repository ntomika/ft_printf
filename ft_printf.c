/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntomika <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/12 15:46:53 by ntomika           #+#    #+#             */
/*   Updated: 2021/01/12 15:46:55 by ntomika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>



void	ft_putchar(char c)
{
	write(1, &c, 1);
}

char	ft_output(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '%' && s[i] != '\0')
	{
		write(1, &s[i], 1);
		i++;
	}
	if (s[i] == '%' && s[i + 1] == '%')
		ft_putchar('%');
//	if (*s[i] == '%' && *s[i] != '\0')
//		ft_check_format(&s);
	return (*(char *)&s[i]);

}

int	ft_printf(const char *s, ...)
{
	int	size;
	
	size = 0;
	ft_output(s);

	return (size);
}

int	main()
{
/*	printf("[FAKE] :\n");
	ft_printf("f98u3fnvpquf[euwf%%");
	printf("\n");

	printf("[ORIGINAL] :\n");
	printf("f98u3fnvpquf[euwf%%");
*/	printf("\n");


	printf("%08d\n", 123);
	return (0);
}
