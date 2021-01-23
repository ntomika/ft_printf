/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntomika <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 15:27:37 by ntomika           #+#    #+#             */
/*   Updated: 2021/01/23 00:02:31 by ntomika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		while_print(int *flag, int l, int n, int c)
{
	int	r;

	r = 0;
	if (flag[3] == -2 && flag[6] == 0)
		c = ' ';
	if (n == 1)
	{
		if (flag[3] < l)
			return (r);
		while (r < (flag[3] - l))
			r += write(1, &c, 1);
	}
	else if (n == 2)
		while (r < (flag[2] - l))
			r += write(1, &c, 1);
	else if (n == 4)
		while (r < l)
			r += write(1, &c, 1);
	return (r);
}

int		if_flags_w(int *flag, char *cp, int l, int r)
{
	if (flag[0] == 1)
	{
		if (flag[5] < 0)
			r += write(1, "-", 1);
		(flag[5] < 0) ? (r += while_print(flag, l + 1, 2, '0')) :
			(r += while_print(flag, l, 2, '0'));
		r += ft_putstr(cp);
	}
	else if (flag[1] == 1)
	{
		if (flag[5] < 0)
			r += write(1, "-", 1);
		r += ft_putstr(cp);
		(flag[5] < 0) ? (r += while_print(flag, flag[2] - l - 1, 4, ' ')) :
				(r += while_print(flag, l, 2, ' '));
	}
	else
	{
		(flag[5] < 0) ? (r += while_print(flag, flag[2] - l - 1, 4, ' ')) :
				(r += while_print(flag, l, 2, ' '));
		if (flag[5] < 0)
			r += write(1, "-", 1);
		r += ft_putstr(cp);
	}
	return (r);
}

int		if_flags23(int *flag, char *cp, int l)
{
	int	r;

	r = 0;
	if (flag[2] < flag[3])
	{
		if (flag[5] < 0)
			r += write(1, "-", 1);
		r += while_print(flag, l, 1, '0');
		r += ft_putstr(cp);
	}
	else
		ft_flags_123(flag, l, &r, cp);
	return (r);
}

int		ft_print_int(va_list ap, int *flag)
{
	long int	arg;
	int			l;
	int			r;
	char		*cp;

	r = 0;
	arg = va_arg(ap, int);
	l = ft_len_int(arg);
	if (arg < 0)
	{
		if (!(cp = ft_itoa((arg * (-1)), flag)))
			return (0);
		flag[5] = -1;
	}
	else
	{
		if (!(cp = ft_itoa(arg, flag)))
			return (0);
	}
	r += ft_int_check(flag, cp, l);
	free(cp);
	return (r);
}
