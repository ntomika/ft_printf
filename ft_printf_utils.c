/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntomika <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 17:42:52 by ntomika           #+#    #+#             */
/*   Updated: 2021/01/22 22:47:54 by ntomika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_strlen(const char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int		ft_len_int(int i)
{
	int len;

	len = 0;
	if (i == 0)
	{
		len++;
		return (len);
	}
	if (i < 0)
		i *= (-1);
	while (i != 0)
	{
		len++;
		i /= 10;
	}
	return (len);
}

int		ft_putstr(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

int		ft_atoi(const char *str)
{
	int				i;
	unsigned long	r;
	int				z;

	i = 0;
	r = 0;
	z = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			z = -1;
		i++;
	}
	while (str[i] >= 48 && str[i] <= 57)
	{
		r = r * 10 + (str[i] - '0');
		i++;
	}
	if (r >= 9223372036854775807UL)
		return (z == 1 ? -1 : 0);
	return (r * z);
}
