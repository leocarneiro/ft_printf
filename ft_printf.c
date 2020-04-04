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

static	int		no_type(t_fields *f, t_count *c, const char *format)
{
	if (f->type == -1)
	{
		if (ft_strcmp((char *)format, "%") == 0)
		{
			c->k = -1;
			c->i = -1;
			return (1);
		}
		else
		{
			ft_putstr((char *)format);
			c->k = ft_strlen(format);
			return (1);
		}
	}
	return (0);
}

static	int		def_type(va_list arg, t_fields *f, t_count *c)
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
		c->i = type_c(f, '%');
	return (c->i);
}

static	int		aux_printf(const char *ft, va_list arg, t_fields *f, t_count *c)
{
	while (*ft)
	{
		if (*ft != '%')
		{
			ft_putchar(*ft);
			c->j++;
		}
		else
		{
			if (no_type(f, c, ft) == 1)
				break ;
			else if (f->type == '%')
			{
				c->i = def_type(arg, f, c);
				ft++;
			}
			else
				c->i = def_type(arg, f, c);
			while (*ft != f->type)
				ft++;
			c->k = c->k + c->i;
		}
		ft++;
	}
	return (c->k + c->j);
}

int				ft_printf(const char *format, ...)
{
	va_list		arg;
	int			ret;
	t_fields	*f;
	t_count		*c;

	va_start(arg, format);
	f = calc_fields(format, arg);
	c = init_counters();
	ret = aux_printf(format, arg, f, c);
	va_end(arg);
	return (ret);
}
