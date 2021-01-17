/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntomika <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 16:30:33 by ntomika           #+#    #+#             */
/*   Updated: 2021/01/17 23:22:01 by ntomika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

void ft_flags(int *flag)
{
	flag[0] = 0;
	flag[1] = 0;
	flag[2] = 0;
	flag[3] = 0;
	flag[4] = 0;
}

int ft_check_format(const char **s, va_list ap, int *size)
{
	int flags[5];

	ft_flags(flags);
	ft_check_flags(s, flags);
	ft_check_width(s, flags, ap);
	if (**s == '.')
	{
		s++;
		ft_check_adot(s, flags, ap);
	}
	return (ft_check_type(s, flags, ap, size));
}

int ft_printf(const char *s, ...)
{
	va_list ap;
	int size;

	size = 0;
	va_start(ap, s);
	if (!s)
		return (-1);
	if (!(ft_strchr(s, '%')))
	{
		ft_putstr((char *)s);
		return (ft_strlen(s));
	}
	while (*s)
	{
		if (*s == '%')
		{
			s++;
			if (!(ft_check_format(&s, ap, &size)))
				return (-1);
			s++;
		}
		else
			size += write(1, s++, 1);
	}
	va_end(ap);
	return (size);
}

int main(void)
{
	//	char *s = "erfgerhglrj";

	printf("[fake] : \n");
	printf("%d\n", ft_printf("write [%0*-d] symbol\n", 10, 123));
	printf("\n");
	printf("[original] : \n");
	printf("%d\n", printf("write [%0*-d] symbol\n", 10, 123));
	printf("\n");
	return (0);
}