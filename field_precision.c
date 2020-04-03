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
	char	*aux;
	char	type;

	precision = -1;
	aux = (char *)format;
	type = field_types(format);
	while (*aux && *aux != type)
	{
		if (!(ft_strchr(format, '.')))
			break ;
		else if (*aux == '.')
		{
			aux++;
			if (*aux == '*')
			{
				precision = va_arg(arg, int);
				break ;
			}
			precision = ft_printnbr(aux);
			break ;
		}
		aux++;
	}
	return (precision);
}
