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

char	*precision_s(char *src, t_fields *f) 
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

char	*width_s(char *src, t_fields *f)
{
	char	*w;
	int		len;

	len = (int)ft_strlen(src);
  if (f->width < 0)
  {
    f->width = f->width*(-1);
    f->flag = '-';
  }
	if (f->width <= len)
		w = ft_strdup(src);
	else
	{
		w = ft_strnew(f->width);
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
	}
	return (w);
}

int		type_s(t_fields *f, char *arg)
{
	char	*p;
	char	*w;

	if (arg == NULL && f->precision >= ft_strlen("(null)"))
		arg = "(null)";
  else if (arg == NULL)
    arg = ft_strdup("");
	p = precision_s(arg, f);
	w = width_s(p, f);
	ft_putstr(w);
	return ((int)ft_strlen(w));
}
