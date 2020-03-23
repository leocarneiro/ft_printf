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

int		field_width(const char *format, va_list arg)
{
	int		width;
	int		i;

	i = 0;
	width = 0;
	while (format[i])
	{
    if (format[i] == '%')
    {
      i++;
		  if (format[i] == '.' || format[i] == '%')
			  break ;
		  while (format[i] == '-' || format[i] == '0')
        i++;
		  if (format[i] == '*')
		  {
			  width = va_arg(arg, int);
			  break;
	  	}
      else if (format[i] > '0' && format[i] <= '9')
		  {
			  while (format[i] >= '0' && format[i] <= '9')
			  {
				  width = width * 10 + format[i] - 48;
				  i++;
			  }
			  break;
		  }
      break ;
    }
    i++;
	}
	return (width);
}
