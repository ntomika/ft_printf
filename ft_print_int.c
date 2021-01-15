/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntomika <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 15:27:37 by ntomika           #+#    #+#             */
/*   Updated: 2021/01/15 17:54:24 by ntomika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_int(va_list ap, int *flags)
{
	int	p;
	int	l;
	int	r;

	p = va_arg(ap, int);
	l = ft_len_int(p);
	if (flags[4] > 0)
		flags[0] = 0;
	if((flags[2] > 0 && len < flags[2]) ||
			(flags[3] > 0 && len < flags[3]))		//если есть '-' -- 
													//выравнивание по левому краю
													//если нет -- по правому, 
													//длину вывода дополнить 
													//пробелами/нулями 
													//(в зависимости от значения 
													//ширины)
		ft_edit_width();
	if(flags[3] == 0 && p == 0)
		len = 0;
	if(flags[2] > flags[3])
		ft_wp();
	else if(flags[2] < flags[3])
		ft_p();

	return (r);
}
