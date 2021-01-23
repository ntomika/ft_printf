/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_string.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntomika <ntomika@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 16:41:31 by ntomika           #+#    #+#             */
/*   Updated: 2021/01/23 17:06:15 by ntomika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putstr_l(char *s, int l)
{
	int	i;

	i = 0;
	while (i < l)
		i += write(1, &s[i], 1);
	return (i);
}

int		string(char *str, int *flag, int l, int n)
{
	int	r;

	r = 0;
	if (flag[3] == -2)
		return (r);
	if (n == 1)
	{
		if (flag[3] < l)
			r += ft_putstr_l(str, flag[3]);
		else
			r += ft_putstr_l(str, l);
	}
	if (n == 2)
	{
		if (flag[3] < l)
			while (r < (flag[2] - flag[3]))
				r += write(1, " ", 1);
		else
			while (r < (flag[2] - l))
				r += write(1, " ", 1);
	}
	if (n == 3)
		while (r < (flag[2] - l))
			r += write(1, " ", 1);
	return (r);
}

int		ft_str_23(int *flag, char *str, int l)
{
	int	r;
	int	i;

	r = 0;
	i = 0;
	if (flag[2] < flag[3])
	{
		if (flag[1] == 1)
		{
			r += string(str, flag, l, 1);
			while (i < (flag[2] - l))
				i += write(1, " ", 1);
		}
		else
		{
			while (i < (flag[2] - l))
				i += write(1, " ", 1);
			r += string(str, flag, l, 1);
		}
	}
	else
		r += ft_dop_string(str, flag, l);
	return (r + i);
}

int		ft_strflag2(int *flag, char *str, int l)
{
	int	r;

	r = 0;
	if (flag[1] == 1)
	{
		r += ft_putstr(str);
		r += string(str, flag, l, 3);
	}
	else if (flag[0] == 1)
	{
		while (r < (flag[2] - l))
			r += write(1, "0", 1);
		r += ft_putstr(str);
	}
	else if (flag[1] == 0 && flag[3] >= 0)
	{
		while (r < (flag[2] - l))
			r += write(1, " ", 1);
		r += ft_putstr(str);
	}
	else if (flag[3] == -2)
		while (r < flag[2])
			r += write(1, " ", 1);
	return (r);
}

int		ft_print_string(va_list ap, int *flag)
{
	int		r;
	int		l;
	char	*str;

	r = 0;
	str = va_arg(ap, char *);
	if (!str)
		str = "(null)";
	if (flag[3] == -2 && flag[6] == 0)
		str = " ";
	l = ft_strlen(str);
	if (flag[3] == -2)
	{
		while (r < flag[2])
			r += write(1, " ", 1);
		return (r);
	}
	r += check_strflags(flag, l, str);
	return (r);
}
