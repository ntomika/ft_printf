/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntomika <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 17:25:43 by ntomika           #+#    #+#             */
/*   Updated: 2021/01/14 21:41:03 by ntomika          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

int					ft_printf(const char *s, ...);
int					ft_strlen(const char *str);
int					ft_strlen_proc(char *str);
int					ft_strlen_format(char *str);
void				ft_putchar(char c);
void				ft_putstr(char *s);
void				ft_flags(int *flags);
void				ft_check_flags(char **s, int *flags);
void				ft_check_width(char **s, int *flags, va_list ap);
void				ft_check_adot(char **s, int *flags, va_list ap);
void				ft_check_type(char **s, int *flags, va_list ap, int *size);
char				*ft_strdup_proc(char *src);
char				*ft_strdup_format(char *src);
char				*ft_strchr(const char *s, int c);

#endif
