/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags_123.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntomika <ntomika@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 13:48:41 by ntomika           #+#    #+#             */
/*   Updated: 2021/01/22 23:48:51 by ntomika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_check_123(int *flag, int l, char *cp)
{
	int	r;

	r = 0;
	if (flag[3] <= l)
	{
		if (flag[5] < 0)
			r += write(1, "-", 1);
		r += ft_putstr(cp);
		(flag[5] < 0) ? (r += while_print(flag, flag[2] - l - 1, 4, ' ')) :
		(r += while_print(flag, flag[2] - l, 4, ' '));
	}
	else
	{
		if (flag[5] < 0)
			r += write(1, "-", 1);
		r += while_print(flag, l, 1, '0');
		r += ft_putstr(cp);
		if (flag[5] < 0)
			r += while_print(flag, flag[2] - flag[3] - 1, 4, ' ');
		else
			r += while_print(flag, flag[2] - flag[3], 4, ' ');
	}
	return (r);
}

int		ft_flags_123(int *flag, int l, int *r, char *cp)
{
	if (flag[1] == 1)
		*r += ft_check_123(flag, l, cp);
	else
	{
		if (flag[3] <= l)
		{
			(flag[5] < 0) ? (*r += while_print(flag, flag[2] - l - 1, 4, ' ')) :
			(*r += while_print(flag, flag[2] - l, 4, ' '));
			if (flag[5] < 0)
				*r += write(1, "-", 1);
		}
		else
		{
			if (flag[5] < 0)
				*r += while_print(flag, flag[2] - flag[3] - 1, 4, ' ');
			else
				*r += while_print(flag, flag[2] - flag[3], 4, ' ');
			(flag[5] < 0) ? (*r += write(1, "-", 1)) : (*r += 0);
			*r += while_print(flag, l, 1, '0');
		}
		*r += ft_putstr(cp);
	}
	return (*r);
}
