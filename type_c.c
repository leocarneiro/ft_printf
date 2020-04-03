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

static	int		nullterm(t_fields *f, int arg)
{
	int		i;

	i = 1;
	if (f->flag == '-')
	{
		ft_putchar(arg);
		while (i < f->width)
		{
			ft_putchar(' ');
			i++;
		}
	}
	else
	{
		while (i++ < f->width)
			ft_putchar(' ');
		ft_putchar(arg);
	}
	return (i);
}

static	char	*width_c(t_fields *f, unsigned char arg)
{
	char	*w;

	w = ft_strnew(1);
	if (f->width > 1)
	{
		w = ft_strnew(f->width);
		if (f->flag == '-')
		{
			w[0] = arg;
			ft_memset(&w[1], ' ', f->width - 1);
		}
		else if (f->flag == '0')
		{
			ft_memset(w, '0', f->width - 1);
			w[f->width - 1] = arg;
		}
		else
		{
			ft_memset(w, ' ', f->width - 1);
			w[f->width - 1] = arg;
		}
	}
	else
		w[0] = arg;
	return (w);
}

int				type_c(t_fields *f, int arg)
{
	char	*w;
	char	c;

	if (f->width < 0)
	{
		f->width = f->width * (-1);
		f->flag = '-';
	}
	if (arg == '\0')
		return (nullterm(f, arg));
	c = (unsigned char)arg;
	w = width_c(f, c);
	ft_putstr(w);
	return ((int)ft_strlen(w));
}
