/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntomika <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 17:25:43 by ntomika           #+#    #+#             */
/*   Updated: 2021/01/15 17:54:35 by ntomika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int					ft_printf(const char *s, ...);
int					ft_strlen(const char *str);
int					ft_atoi(const char *str);
int					ft_print_int(va_list ap, int *flags);
int					ft_print_unsigned();
int					ft_print_16x();
int					ft_print_16X();
int					ft_print_symbol();
int					ft_print_string();
int					ft_print_pointer();
void				ft_putstr(char *s);
void				ft_flags(int *flags);
void				ft_check_flags(const char **s, int *flags);
void				ft_check_width(const char **s, int *flags, va_list ap);
void				ft_check_adot(const char **s, int *flags, va_list ap);
void				ft_check_type(const char **s, int *flags, va_list ap, int *size);
char				*ft_strchr(const char *s, int c);

#endif
