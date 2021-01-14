/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntomika <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 16:30:33 by ntomika           #+#    #+#             */
/*   Updated: 2021/01/14 21:36:29 by ntomika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"

char	*ft_output(char *s)
{
	int i;

	i = 0;
	while (s[i] != '%' && s[i] != '\0')
	{
		write(1, &s[i], 1);
		i++;
	}
	return((char *)&s[i]);
}

int	ft_check_format(char **s, va_list ap, int *size)
{
	int		flags[5];

	ft_flags(flags);
	if (*s == '%' && ++*s == '%')
	{
		*s += 2;
		return (1);
	}
	if (*s == '%' && ++*s == '\0')
		return (-1);
	if (*s == '%' && ++*s != '\0')
	{
		ft_check_flags(s, flags);
		ft_check_width(s, flags, ap);
		if (*s == '.')
			ft_check_adot(s, flags, ap);
		return (ft_chech_type(s, flags, ap, size);
	}
	return (-1);
}

int	ft_printf(const char *s, ...)
{
	va_list	ap;
	int	size;
	
	size = 0;
	if (!s)
		return (-1);
	va_start(ap, s);
	while (*s)
	{
		if (!(ft_strchr(s, '%')))
		{
			ft_putstr((char *)s);
			return (ft_strlen(s));
		}
		else if (*s == '%')
			if (!(ft_check_format(&s, ap, &size)))
				return (-1);
		s++;
	}
	va_end(ap);
	return (size);
}

int	main(void)
{
//	char *s = "erfgerhglrj";

	printf("[fake] : \n");
	printf("%d\n", ft_printf("write %d int\n", 10));
	printf("\n");
	printf("[original] : \n");
	printf("%d\n", ft_printf("write %d int\n", 10));
	printf("\n");
	return (0);
}
