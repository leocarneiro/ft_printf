/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lramos-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/09 15:00:45 by lramos-r          #+#    #+#             */
/*   Updated: 2020/03/13 16:25:25 by lramos-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static	char	*precision_d(char *src, t_fields *f)
{
	char	*p;
	int		len;

	len = (int)ft_strlen(src);
	if (f->precision < len)
		p = ft_strdup(src);
	else
	{
		p = ft_strnew(f->precision);
		if (src[0] == '-')
		{
			p[0] = '-';
			ft_memset(&p[1], '0', f->precision - len + 1);
			ft_memmove(&p[f->precision - len + 2], &src[1], len);
		}
		else
		{
			ft_memset(p, '0', f->precision - len);
			ft_memmove(&p[f->precision - len], src, len);
		}
	}
	return (p);
}

static	int		aux_width_d(t_fields *f, int len, char *src, char *w)
{
	if (f->flag == '-')
	{
		ft_memmove(w, src, len);
		ft_memset(&w[len], ' ', f->width - len);
	}
	else if (f->flag == '0' && f->precision < 0)
	{
		if (src[0] == '-')
		{
			w[0] = '-';
			ft_memset(&w[1], '0', f->width - len + 1);
			ft_memmove(&w[f->width - len + 1], &src[1], len);
		}
		else
		{
			ft_memset(w, '0', f->width - len);
			ft_memmove(&w[f->width - len], src, len);
		}
	}
	else
	{
		ft_memset(w, ' ', f->width - len);
		ft_memmove(&w[f->width - len], src, len);
	}
	return (0);
}

static	char	*width_d(char *src, t_fields *f)
{
	char	*w;
	int		len;

	len = (int)ft_strlen(src);
	if (f->width <= len && f->width >= 0)
		w = ft_strdup(src);
	else
	{
		w = ft_strnew(f->width);
		aux_width_d(f, len, src, w);
	}
	return (w);
}

int				type_d(t_fields *f, int arg)
{
	char	*d;
	char	*w;
	char	*p;
	int		len;

	if (f->precision == 0 && arg == 0)
		d = ft_strdup("");
	else
		d = ft_itoa_base(arg, 10);
	if (f->width < 0)
	{
		f->width = f->width * (-1);
		f->flag = '-';
	}
	p = precision_d(d, f);
	w = width_d(p, f);
	len = (int)ft_strlen(w);
	ft_putstr(w);
	free(d);
	free(p);
	free(w);
	return (len);
}
