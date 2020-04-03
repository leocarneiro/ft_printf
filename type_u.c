/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_u.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lramos-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 18:27:06 by lramos-r          #+#    #+#             */
/*   Updated: 2020/03/13 16:28:59 by lramos-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static	char	*precision_u(char *src, t_fields *f)
{
	char	*p;
	int		len;

	len = (int)ft_strlen(src);
	if (f->precision <= len)
		p = ft_strdup(src);
	else
	{
		p = ft_strnew(f->precision);
		ft_memset(p, '0', f->precision - len);
		ft_memmove(&p[f->precision - len], src, len);
	}
	return (p);
}

static	int		aux_width_u(t_fields *f, int len, char *src, char *w)
{
	if (f->flag == '-')
	{
		ft_memmove(w, src, len);
		ft_memset(&w[len], ' ', f->width - len);
	}
	else if (f->flag == '0' && f->precision < 0)
	{
		ft_memset(w, '0', f->width - len);
		ft_memmove(&w[f->width - len], src, len);
	}
	else
	{
		ft_memset(w, ' ', f->width - len);
		ft_memmove(&w[f->width - len], src, len);
	}
	return (0);
}

static	char	*width_u(char *src, t_fields *f)
{
	char	*w;
	int		len;

	len = (int)ft_strlen(src);
	if (f->width < 0)
		f->width = f->width * (-1);
	if (f->width <= len)
		w = ft_strdup(src);
	else
	{
		w = ft_strnew(f->width);
		aux_width_u(f, len, src, w);
	}
	return (w);
}

int				type_u(t_fields *f, unsigned int arg)
{
	char	*u;
	char	*p;
	char	*w;

	if (f->precision == 0 && arg == 0)
		u = ft_strdup("");
	else
		u = ft_itoa_base(arg, 10);
	p = precision_u(u, f);
	w = width_u(p, f);
	ft_putstr(w);
	return ((int)ft_strlen(w));
}
