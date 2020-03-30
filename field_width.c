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

static	int		calc_width(char *aux, va_list arg, int width)
{
	while (*aux)
	{
		if (*aux == '*')
		{
			width = va_arg(arg, int);
			break;
		}
		else if (*aux > '0' && *aux <= '9')
		{
			width = ft_printnbr(aux);
			break;
		}
		aux++;
	}
	return (width);
}

int		field_width(const char *format, va_list arg)
{
	int	width;
	char	*aux;

	width = 0;
	aux = (char *)format;
	while (*aux)
	{
		if (*aux == '%')
		{
			aux++;
			if (*aux == '.' || *aux == '%')
				break ;
			while (*aux == '-' || *aux == '0')
				aux++;
			width = calc_width(aux, arg, width);
			break ;
		}
		aux++;
	}
	return (width);
}
