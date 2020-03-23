/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   field_types.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lramos-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 19:09:44 by lramos-r          #+#    #+#             */
/*   Updated: 2020/03/13 18:48:09 by lramos-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	field_types(const char *format)
{
	char	*conv;
	char	type;

	conv = "cspdiuxX%";
	type = -1;
	format++;
	while (*format)
	{
		if (ft_strchr(conv, *format))
		{
			type = *format;
			break;
		}
		format++;
	}
	return (type);
}
