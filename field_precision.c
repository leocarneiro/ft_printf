/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   field_precision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lramos-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 19:55:42 by lramos-r          #+#    #+#             */
/*   Updated: 2020/03/13 12:22:58 by lramos-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		field_precision(const char *format, va_list arg)
{
	int		precision;
	int		i;
	char	type;

	type = field_types(format);
	precision = -1;
	i = 0;
	while (format[i] && format[i] != type)
	{
		if (!(ft_strchr(format, '.')))
			break ;
		else if (format[i] == '.')
		{
			i++;
			if (format[i] == '*')
			{
				precision = va_arg(arg, int);
				break ;
			}
			precision = 0;
			while (format[i] >= '0' && format[i] <= '9')
			{
				precision = precision * 10 + format[i] - 48;
				i++;
			}
			break ;
		}
		i++;
	}
	return (precision);
}
