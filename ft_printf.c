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

int		ft_printf(const char *format, ...)
{
	va_list		arg;
	t_fields	*f;
	t_count		*c;

	va_start(arg, format);
	c = init_counters();
	while (*format)
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
        if (ft_strcmp((char *)format, "%") == 0)
        {
          c->k = -1;
          c->i = -1;
          break ;
        }
        else
        {
          ft_putstr((char *)format);
          c->k = ft_strlen(format);
				  break ;
        }
      }
      else if (f->type == 's')
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
				format++;
			}
			while (*format != f->type)
				format++;
			c->k = c->k + c->i;
		}
		format++;
	}
	va_end(arg);
	//return ((int)f->width);
	//return ((int)f->precision);
	//return ((int)f->flag);
  	return (c->k + c->j);
}
