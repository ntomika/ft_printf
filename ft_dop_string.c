/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dop_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntomika <ntomika@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/23 16:42:08 by ntomika           #+#    #+#             */
/*   Updated: 2021/01/23 17:06:15 by ntomika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_dop_string(char *str, int *flag, int l)
{
	int	r;

	r = 0;
	if (flag[1] == 1)
	{
		r += string(str, flag, l, 1);
		r += string(str, flag, l, 2);
	}
	else
	{
		r += string(str, flag, l, 2);
		r += string(str, flag, l, 1);
	}
	return (r);
}

int		check_strflags(int *flag, int l, char *str)
{
	int	r;

	r = 0;
	if (flag[2] > 0 && flag[3] > 0)
		r += ft_str_23(flag, str, l);
	else if (flag[2] > 0)
		r += ft_strflag2(flag, str, l);
	else if (flag[3] > 0)
		r += string(str, flag, l, 1);
	else
		r += ft_putstr(str);
	return (r);
}
