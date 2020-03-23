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
	int			i;
	int			j;
	int			soma;

	va_start(arg, format);
	i = 0;
	soma = 0;
	j = 0;
	while (*format)
	{
		if (*format != '%')
		{
			ft_putchar(*format);
			j++;
		}
		else
		{
			f = calc_fields(format, arg);
			if (f->type == -1)
      {
        if (ft_strcmp((char *)format, "%") == 0)
        {
          soma = -1;
          i = -1;
          break ;
        }
        else
        {
          ft_putstr((char *)format);
          soma = ft_strlen(format);
				  break ;
        }
      }
      else if (f->type == 's')
				i = type_s(f, va_arg(arg, char *));
			else if (f->type == 'c')
				i = type_c(f, va_arg(arg, int));
			else if (f->type == 'd' || f->type == 'i')
				i = type_d(f, va_arg(arg, int));
			else if (f->type == 'u')
        i = type_u(f, va_arg(arg, unsigned int));
			else if (f->type == 'x' || f->type == 'X')
				i = type_x(f, va_arg(arg, unsigned int));
			else if (f->type == 'p')
				i = type_p(f, va_arg(arg, unsigned int));
			else if (f->type == '%')
			{
				i = type_c(f, '%');
				format++;
			}
			while (*format != f->type)
				format++;
			soma = soma + i;
		}
		format++;
	}
	va_end(arg);
	//return ((int)f->width);
	//return ((int)f->precision);
	//return ((int)f->flag);
  return (soma + j);
}
