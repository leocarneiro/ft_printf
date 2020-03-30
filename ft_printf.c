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

static int	cases(const char *format)
{
	char	*cases;
	int	i;
	int	res;

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

t_counters	*init_counters(void)
{
	t_counters	*counter;

	if (!(counter = (t_counters *)malloc(sizeof(t_counters *))))
		return (NULL);
	counter->i = 0;
	counter->k = 0;
	counter->j = 0;
	return (counter);
}

int		ft_printf(const char *format, ...)
{
	va_list		arg;
	t_fields	*f;
	t_counters	*counter;

	va_start(arg, format);
	counter = init_counters();
	while (*format)
	{
		if (*format != '%')
		{
			ft_putchar(*format);
			counter->j++;
		}
		else
		{
			f = calc_fields(format, arg);
			if (f->type == -1)
			{
				if (ft_strcmp((char *)format, "%") == 0)
				{
					counter->k = -1;
					counter->i = -1;
					break ;
				}
				else if (cases(format) == 0)
				{
					ft_putstr((char *)format);
					counter->k = ft_strlen(format);
					break ;
				}
				else
				{
					ft_putstr("\0");
					counter->k = -1;
					counter->i = -1;
					break ;
				}
			}
			else if (f->type == 's')
				counter->i = type_s(f, va_arg(arg, char *));
			else if (f->type == 'c')
				counter->i = type_c(f, va_arg(arg, int));
			else if (f->type == 'd' || f->type == 'i')
				counter->i = type_d(f, va_arg(arg, int));
			else if (f->type == 'u')
				counter->i = type_u(f, va_arg(arg, unsigned int));
			else if (f->type == 'x' || f->type == 'X')
				counter->i = type_x(f, va_arg(arg, unsigned int));
			else if (f->type == 'p')
				counter->i = type_p(f, va_arg(arg, unsigned long long int));
			else if (f->type == '%')
			{
				counter->i = type_c(f, '%');
				format++;
			}
			while (*format != f->type)
				format++;
			counter->k = counter->k + counter->i;
		}
		format++;
	}
	va_end(arg);
	return (counter->k + counter->j);
}
