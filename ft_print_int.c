/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntomika <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 15:27:37 by ntomika           #+#    #+#             */
/*   Updated: 2021/01/18 22:16:05 by ntomika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int while_print(int *flag, char *cp, int l, int n)
{
	int r;

	r = 0;

	if (n == 1)
		while (r < (flag[3] - l))
			r += write(1, "0", 1);
	else if (n == 2)
		while (r < (flag[2] - l))
			r += write(1, "0", 1);
	else if (n == 3)
		while (r < (flag[2] - l))
			r += write(1, " ", 1);
	else if (n == 4)
	{
		while (r < l)
			r += write(1, " ", 1);
		return (r);
	}
	r += ft_putstr(cp);
	return (r);
}

int if_flags_w(int *flag, char *cp, int l)
{
	int r;
	int i;

	r = 0;
	i = 0;
	if (flag[0] == 1)
		r += while_print(flag, cp, l, 2);
	else if (flag[1] == 1)
	{
		r += ft_putstr(cp);
		while (i < (flag[2] - l))
			i += write(1, " ", 1);
		r += i;
	}
	else
		r += while_print(flag, cp, l, 3);
	return (r);
}

int if_flags23(int *flag, char *cp, int l)
{
	int r;
	int i;

	r = 0;
	i = 0;
	if (flag[2] < flag[3])
		r += while_print(flag, cp, l, 1);
	else
	{
		if (flag[1] == 1)
		{
			r += while_print(flag, cp, l, 1);
			while (i < (flag[2] - flag[3]))
				i += write(1, " ", 1);
			r += i;
		}
		else
		{
			if (flag[3] <= l)
				r += while_print(flag, cp, l, 3);
			else
			{
				r += while_print(flag, cp, flag[2] - flag[3], 4);
				r += while_print(flag, cp, l, 1);
			}
		}
	}
	return (r);
}

int ft_print_int(va_list ap, int *flag)
{
	int arg;
	int l;
	int r;
	char *cp;

	r = 0;
	arg = va_arg(ap, int);
	l = ft_len_int(arg);
	cp = ft_itoa(arg);
	if (flag[2] > 0 && flag[3] > 0)
		r += if_flags23(flag, cp, l);
	else if (flag[2] > 0)
		r += if_flags_w(flag, cp, l);
	else if (flag[3] > 0)
		r += while_print(flag, cp, l, 1);
	else
		r += ft_putstr(cp);
	return (r);
}
