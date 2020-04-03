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

static	int		calc_width(const char *format, va_list arg, int width)
{
	while (*format)
	{
		if (*format == '*')
		{
			width = va_arg(arg, int);
			break ;
		}
		else if (*format > '0' && *format <= '9')
		{
			width = ft_printnbr((char *)format);
			break ;
		}
		format++;
	}
	return (width);
}

int				field_width(const char *format, va_list arg)
{
	int		width;

	width = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			while (*format == '-' || *format == '0')
				format++;
			if (*format == '.' || *format == '%')
				break ;
			width = calc_width(format, arg, width);
			break ;
		}
		format++;
	}
	return (width);
}
