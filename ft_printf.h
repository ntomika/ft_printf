/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntomika <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 17:25:43 by ntomika           #+#    #+#             */
/*   Updated: 2021/01/18 22:13:30 by ntomika          ###   ########.fr       */
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
int if_flags23(int *flag, char *cp, int l);
int if_flags_w(int *flag, char *cp, int l);
int while_print(int *flag, char *cp, int l, int n);

int	ft_print_unsigned(va_list ap, int *flag);
int ft_len_unint(unsigned int i);
int flags23(int *flag, char *cp, int l);
int flags_w(int *flag, char *cp, int l);
int print_0s(int *flag, char *cp, int l, int n);

//int					ft_print_16x();
//int					ft_print_16X();
int ft_print_symbol(va_list ap, int *flag);
//int					ft_print_string();
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
