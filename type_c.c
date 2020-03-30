/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_c.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lramos-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 20:17:42 by lramos-r          #+#    #+#             */
/*   Updated: 2020/03/12 17:34:41 by lramos-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		type_c(t_fields *f, int arg)
{
	char			*w;

	if (arg == '\0')
		return (nullterm(f, arg));
  if (f->width < 0)
  {
    f->width *= -1;
    f->flag = '-';
  }
  w = ft_strnew(1);
	if (f->width > 1)
	{
		w = ft_strnew(f->width);
		if (f->flag == '-')
		{
			w[0] = (unsigned char)arg;
			ft_memset(&w[1], ' ', f->width - 1);
		}
		else if (f->flag == '0')
		{
			ft_memset(w, '0', f->width - 1);
			w[f->width - 1] = (unsigned char)arg;
		}
		else
		{
			ft_memset(w, ' ', f->width - 1);
			w[f->width - 1] = (unsigned char)arg;
		}
	}
	else
		w[0] = (unsigned char)arg;
	ft_putstr(w);
	return ((int)ft_strlen(w));
}
