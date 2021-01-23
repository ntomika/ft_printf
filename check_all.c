/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_all.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntomika <ntomika@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 14:16:52 by ntomika           #+#    #+#             */
/*   Updated: 2021/01/22 22:42:04 by ntomika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_check_flag3(int *flag)
{
	if (flag[3] == 0)
	{
		flag[3] = -2;
		flag[6] = 0;
	}
	else if (flag[3] < 0)
		flag[3] = 0;
}

void	ft_check_flags(const char **s, int *flag)
{
	while (**s == '-' || **s == '0')
	{
		if (**s == '-')
			flag[1] = 1;
		if (**s == '0')
			flag[0] = 1;
		*s += 1;
	}
	if (flag[1] == 1)
		flag[0] = 0;
}

void	ft_check_width(const char **s, int *flag, va_list ap)
{
	if (**s == '*')
	{
		flag[2] = va_arg(ap, int);
		*s += 1;
	}
	else if (**s >= '0' && **s <= '9')
	{
		flag[2] = ft_atoi(*s);
		while (**s >= '0' && **s <= '9')
			*s += 1;
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
		*s += 1;
		ft_check_flag3(flag);
	}
	else if (**s >= '0' && **s <= '9')
	{
		flag[3] = ft_atoi(*s);
		while (**s >= '0' && **s <= '9')
			*s += 1;
		if (flag[3] < 0)
			flag[3] = 0;
	}
	else if (**s == 'd' || **s == 'i' || **s == 's' || **s == 'c' \
				|| **s == 'x' || **s == 'X' || **s == 'u' || **s == 'p')
	{
		flag[6] = 0;
		flag[3] = -2;
	}
}

int		ft_check_type(const char **s, int *flag, va_list ap, int *size)
{
	int rez;

	rez = 0;
	if (**s == 'd' || **s == 'i')
		rez = ft_print_int(ap, flag);
	else if (**s == 'u')
		rez = ft_print_unsigned(ap, flag);
	else if (**s == 'x')
		rez = ft_print_16x(ap, flag, 'x');
	else if (**s == 'X')
		rez = ft_print_16x(ap, flag, 'X');
	else if (**s == 'c')
		rez = ft_print_symbol(ap, flag);
	else if (**s == 's')
		rez = ft_print_string(ap, flag);
	else if (**s == 'p')
		rez = ft_print_pointer(ap, flag);
	else if (**s == '%')
		rez = ft_print_void(flag);
	*size += rez;
	return (1);
}
