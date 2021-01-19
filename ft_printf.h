/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntomika <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 17:25:43 by ntomika           #+#    #+#             */
/*   Updated: 2021/01/19 17:31:59 by ntomika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>

int ft_printf(const char *s, ...);
int ft_strlen(const char *str);
int ft_atoi(const char *str);

int ft_print_int(va_list ap, int *flag);
int ft_len_int(int i);
int	ft_flags_123(int *flag, int l, int *r, char *cp);
int if_flags23(int *flag, char *cp, int l);
int if_flags_w(int *flag, char *cp, int l, int r);
int while_print(int *flag, int l, int n, int c);

int	ft_print_unsigned(va_list ap, int *flag);
int ft_len_unint(unsigned int i);
int flags23(int *flag, char *cp, int l);
int flags_w(int *flag, char *cp, int l);
int print_0s(int *flag, char *cp, int l, int n);

//int					ft_print_16x();

//int					ft_print_16X();

int ft_print_symbol(va_list ap, int *flag);
int ft_int_check(int *flag, char *cp, int l);

int	ft_print_string(va_list ap, int *flag);
int ft_str_23(int *flag, char *str, int l);
int ft_putstr_l(char *s, int l);
int string(char *str, int *flag, int l, int n);
int	ft_strflag2(int *flag, char *str, int l);

//int					ft_print_pointer();
int ft_check_type(const char **s, int *flag, va_list ap, int *size);
int ft_putstr(char *s);
void ft_flags(int *flag);
void ft_check_flags(const char **s, int *flag);
void ft_check_width(const char **s, int *flag, va_list ap);
void ft_check_adot(const char **s, int *flag, va_list ap);
char *ft_strchr(const char *s, int c);
char *ft_itoa(int n);

#endif
