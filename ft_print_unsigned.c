/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unsigned.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntomika <ntomika@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 14:36:38 by ntomika           #+#    #+#             */
/*   Updated: 2021/01/22 23:59:23 by ntomika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_len_unint(unsigned long i)
{
	unsigned long	len;

	len = 0;
	if (i == 0)
		return (1);
	while (i != 0)
	{
		len++;
		i /= 10;
	}
	return (len);
}

int		print_0s(int *flag, char *cp, int l, int n)
{
	int	r;

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

int		ft_print_unsigned(va_list ap, int *flag)
{
	unsigned int	arg;
	unsigned int	l;
	int				r;
	char			*cp;

	r = 0;
	arg = va_arg(ap, unsigned int);
	l = ft_len_unint(arg);
	if (!(cp = ft_itoa(arg, flag)))
		return (0);
	if (flag[2] > 0 && flag[3] > 0)
		r += if_flags23(flag, cp, l);
	else if (flag[2] > 0)
		r += if_flags_w(flag, cp, l, r);
	else if (flag[3] > 0)
		r += print_0s(flag, cp, l, 1);
	else
		r += ft_putstr(cp);
	free(cp);
	return (r);
}
