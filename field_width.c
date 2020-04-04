/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   field_width.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lramos-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 19:50:46 by lramos-r          #+#    #+#             */
/*   Updated: 2020/03/13 11:56:15 by lramos-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static	int		calc_width(const char *format, va_list arg)
{
	int		width;
	char	type;

	width = 0;
	type = field_types(format);
	while (*format && *format != type)
	{
		if (*format == '*')
		{
			width = va_arg(arg, int);
			break ;
		}
		width = ft_printnbr(format);
		break ;
		format++;
	}
	return (width);
}

int				field_width(const char *format, va_list arg)
{
	int		width;

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			while (*format == '-' || *format == '0')
				format++;
			if (*format == '.' || *format == '%')
				break ;
			width = calc_width(format, arg);
			break ;
		}
		format++;
	}
	return (width);
}
