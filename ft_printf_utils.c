/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntomika <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 17:42:52 by ntomika           #+#    #+#             */
/*   Updated: 2021/01/14 21:48:33 by ntomika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen(const char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

void	ft_putstr(char *s)
{
	int i;

	i = 0;
	if (!s)
		return ;
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	*ni;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
			ni = (char *)&s[i];
			return (ni);
		}
		i++;
	}
	if (s[i] == c)
	{
		ni = (char *)&s[i];
		return (ni);
	}
	return (NULL);
}

int	ft_strlen_proc(char *str)
{
	int i;

	i = 0;
	while (str[i] != '%')
		i++;
	if (str[i] == '%' && str[i + 1] == '%')
		i++;
	return (i);
}

char	*ft_strdup_proc(char *src)
{
	int		i;
	int		l;
	char	*src2;

	l = ft_strlen_proc(src);
	src2 = (char *)malloc(sizeof(char) * (l + 1));
	if (src2 == NULL)
		return (NULL);
	i = 0;
	while (src[i] != '%')
	{
		src2[i] = src[i];
		i++;
	}
	if (src[i] == '%' && src[i + 1] == '%')
	{
		src2[i] = '%';
		i++;
	}
	src2[i] = '\0';
	return (src2);
}


