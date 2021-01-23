/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntomika <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 17:25:43 by ntomika           #+#    #+#             */
/*   Updated: 2021/01/23 19:01:18 by ntomika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>

int		ft_printf(const char *s, ...);
int		ft_strlen(const char *str);
int		ft_atoi(const char *str);
char	*ft_itoa(unsigned int n, int *flag);
char	*ft_strdup(char *src);

int		ft_print_int(va_list ap, int *flag);
int		ft_len_int(int i);
int		ft_flags_123(int *flag, int l, int *r, char *cp);
int		ft_check_123(int *flag, int l, char *cp);
int		if_flags23(int *flag, char *cp, int l);
int		if_flags_w(int *flag, char *cp, int l, int r);
int		while_print(int *flag, int l, int n, int c);

int		ft_print_unsigned(va_list ap, int *flag);
int		ft_len_unint(unsigned long i);
int		print_0s(int *flag, char *cp, int l, int n);

int		ft_print_16x(va_list ap, int *flag, char c);
char	*ft_modif(unsigned long int arg, int reg, int l, int *flag);
void	while_arg(unsigned long int arg, char *cp, int reg, int l);

int		ft_print_symbol(va_list ap, int *flag);
int		ft_int_check(int *flag, char *cp, int l);
void	ft_intcheckdop(int *flag);

int		ft_print_string(va_list ap, int *flag);
int		ft_str_23(int *flag, char *str, int l);
int		ft_putstr_l(char *s, int l);
int		string(char *str, int *flag, int l, int n);
int		ft_strflag2(int *flag, char *str, int l);
int		ft_dop_string(char *str, int *flag, int l);
int		check_strflags(int *flag, int l, char *str);

int		ft_print_pointer(va_list ap, int *flag);
int		ft_get_len(unsigned long int arg);
char	*ft_modif2(unsigned long int arg, int l, int *flag);
void	check_pointerflags(int *flag, int *r, char *cp, int l);
void	print_0x_cp(char *cp, int *r);

int		ft_check_type(const char **s, int *flag, va_list ap, int *size);
int		ft_putstr(char *s);
void	ft_flags(int *flag);
void	ft_check_flags(const char **s, int *flag);
void	ft_check_width(const char **s, int *flag, va_list ap);
void	ft_check_adot(const char **s, int *flag, va_list ap);
void	ft_check_flag3(int *flag);

int		ft_print_void(int *flag);
void	check_voidflag0(int *flag, int *r);

#endif
