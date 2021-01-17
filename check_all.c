/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_all.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntomika <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/14 19:54:43 by ntomika           #+#    #+#             */
/*   Updated: 2021/01/17 09:11:35 by ntomika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_check_flags(const char **s, int *flag)
{
	while (**s == '-' || **s == '0')
	{
		if (**s == '-')
			flag[1] = 1;
		if (**s == '0')
			flag[0] = 1;
		s++;
	}
	if (flag[1] == 1)
		flag[0] = 0;
}

void	ft_check_width(const char **s, int *flag, va_list ap)
{
	if (**s == '*')
	{
		flag[2] = va_arg(ap, int);
		s++;
	}
	else if (**s >= '0' && **s <= '9')
	{
		flag[2] = ft_atoi(*s);
		while (**s >= '0' && **s <= '9')
			s++;
	}
	if (flag[2] < 0)
	{
		flag[2] *= (-1);
		flag[0] = 0;
		flag[1] = 1;
	}
}

void	ft_check_adot(const char **s, int *flag, va_list ap)
{
	if (**s == '*')
	{
		flag[3] = va_arg(ap, int);
		s++;
	}
	else if (**s >= '0' && **s <= '9')
	{
		flag[3] = ft_atoi(*s);
		while (**s >= '0' && **s <= '9')
			s++;
	}
	if (flag[3] < 0)
		flag[3] = -1;
}

int	ft_check_type(const char **s, int *flag, va_list ap, int *size)
{
	int	rez;

	rez = 0;
	if (**s == 'd' || **s == 'i')
		rez = ft_print_int(ap, flag);
//	else if (**s == 'u')
//		rez = ft_print_unsigned(ap, flag);
//	else if (**s == 'x')
//		rez = ft_print_16x(ap, flag);
//	else if (**s == 'X')
//		rez = ft_print_16X(ap, flag);
	else if (**s == 'c')
		rez = ft_print_symbol(ap, flag);
//	else if (**s == 's')
//		rez = ft_print_string(ap, flag);
//	else if (**s == 'p')
//		rez = ft_print_pointer(ap, flag);
	else if (**s == '%')
		rez += write(1, "%", 1);
	*size += rez;
	return (1);
}

