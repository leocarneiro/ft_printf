/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   field_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lramos-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 19:23:03 by lramos-r          #+#    #+#             */
/*   Updated: 2020/03/13 15:27:04 by lramos-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	field_flags(const char *format)
{
	char	flag;
	char	type;
	int		i;

	type = field_types(format);
	flag = 0;
	i = 1;
	if (format[1] == '0' && format[0] == '%')
		flag = '0';
	while (format[i] != type)
	{
		if (format[i] == '-')
			flag = '-';
		i++;
	}
	return (flag);
}
