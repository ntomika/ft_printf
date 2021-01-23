/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_16x.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntomika <ntomika@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 12:38:03 by ntomika           #+#    #+#             */
/*   Updated: 2021/01/23 19:05:51 by ntomika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	while_arg(unsigned long int arg, char *cp, int reg, int l)
{
	unsigned int	n_arg;

	while (arg)
	{
		n_arg = arg % 16;
		arg /= 16;
		if ((n_arg >= 10 && n_arg <= 15) && (reg == 0))
			cp[l--] = ((char)n_arg) + 87;
		else if ((n_arg >= 10 && n_arg <= 15) && (reg == 1))
			cp[l--] = ((char)n_arg) + 55;
		else if (n_arg <= 9)
			cp[l--] = ((char)n_arg) + 48;
	}
}

char	*ft_modif(unsigned long int arg, int reg, int l, int *flag)
{
	char			*cp;
	int				len;

	len = l + 1;
	if (arg == 0 && flag[3] == -2 && flag[6] == 0 && flag[2] > 0)
		return (ft_strdup(" "));
	else if (arg == 0 && flag[3] == -2 && flag[6] == 0 && flag[2] <= 0)
		return (NULL);
	if (!(cp = (char *)malloc(sizeof(char) * (len))))
		return (NULL);
	if (arg == 0)
	{
		cp[0] = ((char)arg) + 48;
		cp[1] = '\0';
		return (cp);
	}
	while_arg(arg, cp, reg, l);
	cp[len] = '\0';
	return (cp);
}

int		ft_print_16x(va_list ap, int *flag, char c)
{
	unsigned int	arg;
	char			*cp;
	int				r;
	int				l;
	int				reg;

	reg = 0;
	r = 0;
	arg = va_arg(ap, unsigned int);
	if (c == 'X')
		reg = 1;
	l = ft_get_len(arg);
	if (!(cp = ft_modif(arg, reg, l, flag)))
		return (0);
	l += 1;
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
