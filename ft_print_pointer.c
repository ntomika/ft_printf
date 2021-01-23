/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntomika <ntomika@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 19:50:43 by ntomika           #+#    #+#             */
/*   Updated: 2021/01/23 18:02:16 by ntomika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_get_len(unsigned long int arg)
{
	int	l;

	l = 0;
	while ((arg /= 16) > 0)
		l++;
	return (l);
}

char	*ft_modif2(unsigned long int arg, int l, int *flag)
{
	char	*bs;
	char	*cp;

	if (arg == 0 && flag[3] == -2 && flag[6] == 0 && flag[2] > 0)
		return (ft_strdup(""));
	else if (arg == 0 && flag[3] == -2 && flag[6] == 0 && flag[2] <= 0)
		return (NULL);
	bs = "0123456789abcdef";
	if (!(cp = malloc(sizeof(char) * (l + 1))))
		return (NULL);
	cp[l] = '\0';
	if (arg == 0)
		cp[--l] = ((char)arg) + 48;
	while (arg)
	{
		cp[--l] = bs[arg % 16];
		arg /= 16;
	}
	return (cp);
}

void	print_0x_cp(char *cp, int *r)
{
	*r += ft_putstr("0x");
	*r += ft_putstr(cp);
}

void	check_pointerflags(int *flag, int *r, char *cp, int l)
{
	if (flag[1] == 1 && flag[2] > 1)
	{
		print_0x_cp(cp, r);
		while (*r < (flag[2]))
			*r += write(1, " ", 1);
	}
	else if (flag[1] == 0 && flag[2] > 0 && flag[6] == 0)
	{
		while (*r < (flag[2] - (l - 2)))
			*r += write(1, " ", 1);
		print_0x_cp(cp, r);
	}
	else if (flag[1] == 0 && flag[2] > 0 && flag[6] == -1)
	{
		while (*r <= (flag[2] - l))
			*r += write(1, " ", 1);
		print_0x_cp(cp, r);
	}
	else
		print_0x_cp(cp, r);
}

int		ft_print_pointer(va_list ap, int *flag)
{
	int					r;
	int					l;
	unsigned long int	arg;
	char				*cp;

	r = 0;
	arg = va_arg(ap, unsigned long int);
	l = ft_get_len(arg) + 1;
	if (!(cp = ft_modif2(arg, l, flag)))
	{
		r += ft_putstr("0x");
		return (r);
	}
	l += 3;
	check_pointerflags(flag, &r, cp, l);
	free(cp);
	return (r);
}
