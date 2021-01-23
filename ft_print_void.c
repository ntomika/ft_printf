/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_void.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntomika <ntomika@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 20:12:11 by ntomika           #+#    #+#             */
/*   Updated: 2021/01/23 17:10:24 by ntomika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_print_void(int *flag)
{
	int r;
	int i;

	r = 0;
	i = 0;
	if (flag[2] > 0)
	{
		if (flag[0] > 0)
			check_voidflag0(flag, &r);
		else if (flag[1] > 0)
		{
			r += write(1, "%", 1);
			while (i < (flag[2] - 1))
				i += write(1, " ", 1);
		}
		else
		{
			while (r < (flag[2] - 1))
				r += write(1, " ", 1);
			r += write(1, "%", 1);
		}
	}
	else
		r += write(1, "%", 1);
	return (r + i);
}

void	check_voidflag0(int *flag, int *r)
{
	while (*r < (flag[2] - 1))
		*r += write(1, "0", 1);
	*r += write(1, "%", 1);
}
