/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lramos-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/17 17:09:13 by lramos-r          #+#    #+#             */
/*   Updated: 2020/03/13 18:27:05 by lramos-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static	int			cases(const char *format)
{
	char	*cases;
	int		i;
	int		res;

	cases = "0123456789-$";
	i = 0;
	res = 1;
	while (format[i])
	{
		i++;
		if (ft_strchr(cases, format[i]) == NULL)
			res = 0;
	}
	return (res);
}

static	int			aux_function(const char *s, t_count *c)
{
	if (ft_strcmp((char *)s, "%") == 0)
	{
		c->k = -1;
		c->i = -1;
	}
	else if (cases(s) == 0)
	{
		ft_putstr((char *)s);
		c->k = ft_strlen(s);
	}
	else
	{
		ft_putstr("\0");
		c->k = -1;
		c->i = -1;
	}
	return (0);
}

static	int			conv(const char *s, t_count *c, t_fields *f, va_list arg)
{
	if (f->type == 's')
		c->i = type_s(f, va_arg(arg, char *));
	else if (f->type == 'c')
		c->i = type_c(f, va_arg(arg, int));
	else if (f->type == 'd' || f->type == 'i')
		c->i = type_d(f, va_arg(arg, int));
	else if (f->type == 'u')
		c->i = type_u(f, va_arg(arg, unsigned int));
	else if (f->type == 'x' || f->type == 'X')
		c->i = type_x(f, va_arg(arg, unsigned int));
	else if (f->type == 'p')
		c->i = type_p(f, va_arg(arg, unsigned long long int));
	else if (f->type == '%')
	{
		c->i = type_c(f, '%');
		s++;
	}
	return (0);
}

static	void		aux_printf(const char *format, t_count *c, va_list arg)
{
	t_fields	*f;

	while (*format && c->n != -1)
	{
		if (*format != '%')
		{
			ft_putchar(*format);
			c->j++;
		}
		else
		{
			f = calc_fields(format, arg);
			if (f->type == -1)
			{
				aux_function(format, c);
				c->n = -1;
			}
			else
				conv(format, c, f, arg);
			while (*format != f->type)
				format++;
			c->k = c->k + c->i;
		}
		format++;
	}
}

int					ft_printf(const char *format, ...)
{
	va_list		arg;
	t_count		*counter;

	va_start(arg, format);
	counter = init_counters();
	aux_printf(format, counter, arg);
	va_end(arg);
	return (counter->k + counter->j);
}
