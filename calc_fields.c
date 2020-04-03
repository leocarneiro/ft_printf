/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_fields.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lramos-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 20:11:23 by lramos-r          #+#    #+#             */
/*   Updated: 2020/03/06 20:15:49 by lramos-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

t_fields	*calc_fields(const char *format, va_list arg)
{
	t_fields	*f;

	if (!(f = (t_fields *)malloc(sizeof(t_fields))))
		return (NULL);
	f->flag = field_flags(format);
	f->width = field_width(format, arg);
	f->precision = field_precision(format, arg);
	f->type = field_types(format);
	return (f);
}
