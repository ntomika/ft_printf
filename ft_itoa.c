/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntomika <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/13 21:34:41 by ntomika           #+#    #+#             */
/*   Updated: 2021/01/22 22:49:06 by ntomika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_nlen(unsigned int s)
{
	int		j;

	j = 0;
	if (s == 0)
		return (1);
	while (s != 0)
	{
		j++;
		s = s / 10;
	}
	return (j);
}

static int	ft_znak(unsigned int num)
{
	if (num < 0)
		return (2);
	else
		return (1);
}

char		*ft_itoa(unsigned int n, int *flag)
{
	char			*c;
	int				l;
	unsigned int	nl;

	if (n == 0 && flag[3] == -2 && flag[6] == 0 && flag[2] > 0)
		return (ft_strdup(" "));
	else if (n == 0 && flag[3] == -2 && flag[6] == 0 && flag[2] <= 0)
		return (NULL);
	nl = n;
	l = ft_nlen(nl) + ft_znak(nl);
	c = (char *)malloc(l);
	if (!c)
		return (NULL);
	if (nl == 0)
		c[0] = '0';
	while (nl != 0)
	{
		l--;
		c[l - 1] = (nl % 10) + '0';
		nl = nl / 10;
	}
	l = ft_nlen(n) + ft_znak(n);
	c[l - 1] = '\0';
	return (c);
}
