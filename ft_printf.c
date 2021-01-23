/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntomika <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 16:30:33 by ntomika           #+#    #+#             */
/*   Updated: 2021/01/22 22:46:14 by ntomika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_flags(int *flag)
{
	flag[0] = 0;
	flag[1] = 0;
	flag[2] = 0;
	flag[3] = 0;
	flag[4] = 0;
	flag[5] = 0;
	flag[6] = -1;
}

int		ft_check_format(const char **s, va_list ap, int *size)
{
	int flags[7];

	*s += 1;
	ft_flags(flags);
	ft_check_flags(s, flags);
	ft_check_width(s, flags, ap);
	if (**s == '.')
	{
		*s += 1;
		while (**s == '0')
			*s += 1;
		ft_check_adot(s, flags, ap);
	}
	return (ft_check_type(s, flags, ap, size));
}

int		ft_printf(const char *s, ...)
{
	va_list	ap;
	int		size;

	size = 0;
	va_start(ap, s);
	if (!s)
		return (-1);
	while (*s)
	{
		if (*s == '%')
		{
			if (!(ft_check_format(&s, ap, &size)))
				return (-1);
			if (*s == '\0')
			{
				write(1, "", 1);
				return (size);
			}
			s++;
		}
		else
			size += write(1, s++, 1);
	}
	va_end(ap);
	return (size);
}
