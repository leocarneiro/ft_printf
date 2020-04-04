/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_s.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lramos-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 20:23:42 by lramos-r          #+#    #+#             */
/*   Updated: 2020/03/13 12:42:09 by lramos-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static	char	*precision_s(char *src, t_fields *f)
{
	char	*p;
	int		len;

	if (ft_strcmp(src, "(nil)") == 0)
		f->precision = -1;
	len = (int)ft_strlen(src);
	if (f->precision == 0)
		p = ft_strdup("");
	else if (f->precision >= len || f->precision < 0)
		p = ft_strdup(src);
	else
	{
		p = ft_strnew(f->precision);
		ft_memmove(p, src, f->precision);
	}
	return (p);
}

static	int		aux_width_s(t_fields *f, int len, char *src, char *w)
{
	if (f->flag == '-')
	{
		ft_memmove(w, src, len);
		ft_memset(&w[len], ' ', f->width - len);
	}
	else if (f->flag == '0')
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

static	char	*width_s(char *src, t_fields *f)
{
	char	*w;
	int		len;

	len = (int)ft_strlen(src);
	if (f->width <= len)
		w = ft_strdup(src);
	else
	{
		w = ft_strnew(f->width);
		aux_width_s(f, len, src, w);
	}
	return (w);
}

int				type_s(t_fields *f, char *arg)
{
	char	*s;
	char	*p;
	char	*w;
	int		len;

	if (arg == NULL)
		arg = "(null)";
	s = ft_strdup(arg);
	if (f->width < 0)
	{
		f->width = f->width * (-1);
		f->flag = '-';
	}
	p = precision_s(s, f);
	w = width_s(p, f);
	len = (int)ft_strlen(w);
	ft_putstr(w);
	free(s);
	free(p);
	free(w);
	return (len);
}
