/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_symbol.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntomika <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/17 08:13:43 by ntomika           #+#    #+#             */
/*   Updated: 2021/01/17 09:11:38 by ntomika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_symbol(va_list ap, int *flag)
{
	int	r;
	int	c;

	r = 0;
	c = (char)va_arg(ap, int);
	if(flag[1] == 1 && (flag[2] > 1 || flag[2] == 0))
	{
		r += write(1, &c, 1);
		while (r < (flag[2] - 1))
			r += write(1, " ", 1);
		return (r);
	}
	if(flag[1] == 0 && (flag[2] > 1 || flag[2] == 0))
	{
		while (r < (flag[2] - 1))
			r += write(1, " ", 1);
		r += write(1, &c, 1);
		return (r);
	}
	else
		r += write(1, &c, 1);
	return (1);
}
