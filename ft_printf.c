/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntomika <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 16:30:33 by ntomika           #+#    #+#             */
/*   Updated: 2021/01/13 19:22:16 by ntomika          ###   ########.fr       */
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

char	*ft_check_format(char *p_procent, va_list ap)
{
	int	i;
//	char	*p_str;
	char	*vrem2;
	
	vrem2 = p_procent;
	while (vrem2[0] != '\0')
	{
		i = 0;
		if (vrem2[i] == '%' && vrem2[i + 1] == '%')
		{
			ft_putchar('%');
			i = i + 2;
		}
		if (vrem2[i] != '%' && vrem2[i] != '\0')
		{
			vrem2 = ft_output(&vrem2[i]);
		}
//		if (*p_procent[i] == '%' && p_procent[i + 1] != '\0')
//		{
//			p_str = ft_check_flag(p_procent, ap);
//		}
		else if (vrem2[i] == '%' && vrem2[i + 1] == '\0')
			return (NULL);
	}
	return (&*vrem2);
}

int	ft_printf(const char *s, ...)
{
	va_list	ap;
	int	size;
	int	i;
	char	*p_procent;
	char	*vrem;

	
	vrem = (char *)s;
	i = 0;
	size = 0;
	if (!s)
		return (-1);
	va_start(ap, s);
	p_procent = ft_output(vrem);
//	printf("\n\n%s\n", p_procent);
	if (!(ft_check_format(p_procent, ap)))
			return (-1);

	va_end(ap);
	return (size);
}

int	main()
{
//	char *s = "erfgerhglrj";

	printf("[fake] : \n");
	ft_printf("iuehiueh34ueuhfke%%12345678%%eiufjs\\euhvdahvda;%%dnvsfjnbv");
	printf("\n");
	printf("[original] : \n");
	printf("iuehiueh34ueuhfke%%12345678%%eiufjs\\euhvdahvda;%%dnvsfjnbv");
	printf("\n");
	return (0);
}
