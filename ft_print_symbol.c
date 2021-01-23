/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_symbol.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntomika <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 08:13:43 by ntomika           #+#    #+#             */
/*   Updated: 2021/01/23 16:33:54 by ntomika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_print_symbol(va_list ap, int *flag)
{
	int	r;
	int	c;

	r = 0;
	c = (char)va_arg(ap, int);
	if (flag[1] == 1 && flag[2] > 1)
	{
		r += write(1, &c, 1);
		while (r <= (flag[2] - 1))
			r += write(1, " ", 1);
	}
	else if (flag[1] == 0 && flag[2] > 1)
	{
		while (r < (flag[2] - 1))
			r += write(1, " ", 1);
		r += write(1, &c, 1);
	}
	else
		r += write(1, &c, 1);
	return (r);
}

void	ft_intcheckdop(int *flag)
{
	if (flag[3] == -2 && flag[6] == 0)
	{
		flag[3] = 0;
		flag[0] = 0;
	}
}

int		ft_int_check(int *flag, char *cp, int l)
{
	int	r;

	r = 0;
	ft_intcheckdop(flag);
	if (flag[2] > 0 && flag[3] > 0)
		r += if_flags23(flag, cp, l);
	else if (flag[2] > 0 || (flag[2] > 0 && flag[3] == 0))
		r += if_flags_w(flag, cp, l, r);
	else if (flag[3] > 0)
	{
		if (flag[5] < 0)
			r += write(1, "-", 1);
		r += while_print(flag, l, 1, '0');
		r += ft_putstr(cp);
	}
	else
	{
		if (flag[5] < 0)
			r += write(1, "-", 1);
		r += ft_putstr(cp);
	}
	return (r);
}
