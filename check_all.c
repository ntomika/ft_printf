/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_all.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntomika <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 19:54:43 by ntomika           #+#    #+#             */
/*   Updated: 2021/01/14 21:40:08 by ntomika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_flags(int *flags)
{
	flags[0] = 0;
	flags[1] = 0;
	flags[2] = 0;
	flags[3] = 0;
	flags[4] = 0;
}

void	*ft_check_flags(char **s, int *flags)
{
	while (**s == '-' || **s == '0')
	{
		if (**s == '-'`)
			flags[1] = 1;
		if (**s == '0'`)
			flags[0] = 1;
		*s++;
	}
	if (flags[1] == 1)
		flags[0] = 0;
}

void	ft_check_width(char **s, int *flags, va_list ap)
{
	if (**s == '*')
	{
		flags[2] = va_arg(ap, int);
		*s++
	}
	else
	{
		flags[2] = ft_atoi(*s);
		while (**s >= '0' && **s <= '9')
			*s++;
	}
	if (flags[2] < 0)
	{
		flag[2] *= (-1);
		flags[0] = 0;
		flags[1] = 1;
	}
}

void	ft_check_adot(char **s, int *flags, va_list ap)
{
	*s++;
	if (**s == '*')
	{
		flags[3] = va_arg(ap, int);
		*s++
	}
	else
	{
		flags[3] = ft_atoi(*s);
		while (**s >= '0' && **s <= '9')
			*s++;
	}
	if (flags[3] < 0)
		flags[3] = -1;
}

int	ft_check_type(char **s, int *flags, va_list ap, int *size)
{
	int	rez;

	rez = 0;
	if (**s == 'd' || **s == 'i')
		rez = ft_print_int(ap, flags);
	else if (**s == 'u')
		rez = ft_print_unsigned(ap, flags);
	else if (**s == 'x')
		rez = ft_print_16x(ap, flags);
	else if (**s == 'X')
		rez = ft_print_16X(ap, flags);
	else if (**s == 'c')
		rez = ft_print_symbol(ap, flags);
	else if (**s == 's')
		rez = ft_print_string(ap, flags);
	else if (**s == 'p')
		rez = ft_print_pointer(ap, flags);
	else
		return (0);
	*size += rez;
	return (1);
}
