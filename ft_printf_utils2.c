/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntomika <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 20:42:51 by ntomika           #+#    #+#             */
/*   Updated: 2021/01/14 21:48:36 by ntomika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen_format(char *str)
{
	int i;

	i = 0;
	while (str[i] != 'd' || str[i] != 'i' || str[i] != 'x' ||
			str[i] != 'X' || str[i] != 'u' || str[i] != 's' ||
			str[i] != 'c' || str[i] != 'p' || str[i] != '\0')
		i++;
	if (str[i] == 'd' || str[i] == 'i' || str[i] == 'x' ||
			str[i] == 'X' || str[i] == 'u' || str[i] == 's' ||
			str[i] == 'c' || str[i] == 'p')
		i++;
	return (i);
}
char	*ft_strdup_format(char *src)
{
	int		i;
	int		l;
	char	*src2;

	l = ft_strlen_format(src);
	src2 = (char *)malloc(sizeof(char) * (l + 1));
	if (src2 == NULL)
		return (NULL);
	i = 0;
	while (src[i] != 'd' || src[i] != 'i' || src[i] != 'x' ||
			src[i] != 'X' || src[i] != 'u' || src[i] != 's' ||
			src[i] != 'c' || src[i] != 'p' || src[i] != '\0')
	{
		src2[i] = src[i];
		i++;
	}
	if (src[i] == 'd' || src[i] == 'i' || src[i] == 'x' ||
			src[i] == 'X' || src[i] == 'u' || src[i] == 's' ||
			src[i] == 'c' || src[i] == 'p')
	{
		src2[i] = src[i];
		i++;
	}
	src2[i] = '\0';
	return (src2);
}
