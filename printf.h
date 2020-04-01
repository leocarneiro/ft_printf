/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lramos-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 20:37:00 by lramos-r          #+#    #+#             */
/*   Updated: 2020/03/13 17:29:18 by lramos-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>
#include <unistd.h>

typedef struct s_fields
{
	char	flag;
	char	type;
	int		width;
	int		precision;
}	t_fields;

t_fields	*calc_fields(const char *format, va_list arg);
char		field_flags(const char *format);
int		field_precision(const char *format, va_list arg);
char	field_types(const char *format);
int		field_width(const char *format, va_list arg);
char	*ft_itoa_base(long long i, int base);
void	*ft_memset(void *str, int c, size_t len);
void	*ft_memmove(void *dest, const void *src, size_t len);
int		ft_printf(const char *format, ...);
void	ft_putchar(char c);
void	ft_putstr(char *s);
char	*ft_strchr(const char *str, int ch);
char	*ft_strdup(const char *s);
size_t		ft_strlen(const char *t);
char	*ft_strnew(int len);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_isnumber(char c);
char	*ft_strupcase(char *s);
int		nullterm(t_fields *f, int arg);
int   ft_strcmp(char *s1, char *s2);
int		type_c(t_fields *f, int arg);
int		type_s(t_fields *f, char *arg);
int		type_d(t_fields *f, int arg);
int		type_u(t_fields *f, unsigned int arg);
int		type_x(t_fields *f, unsigned int arg);
int		type_p(t_fields *f, unsigned int arg);


#endif
