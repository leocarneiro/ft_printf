/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type_p.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lramos-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/10 13:25:33 by lramos-r          #+#    #+#             */
/*   Updated: 2020/03/10 15:12:37 by lramos-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*precision_p(char *src, t_fields *f)
{
	char	*prec;
	int		len;

	len = (int)ft_strlen(src);
	if (f->precision <= len)
	{
		prec = ft_strnew(len + 2);
		ft_memmove(prec, "0x", 2);
		ft_memmove(&prec[2], src, len);
	}
	else
	{
		prec = ft_strnew(f->precision + 2);
		ft_memmove(prec, "0x", 2);
		ft_memset(&prec[2], '0', f->precision - len);
		ft_memmove(&prec[2 + f->precision - len], src, len);
	}
	return (prec);
}

char	*width_p(char *src, t_fields *f)
{
	char	*wid;
	int		len;

	len = (int)ft_strlen(src);
	if (f->width <= len)
		wid = ft_strdup(src);
	else
	{
		wid = ft_strnew(f->width);
		if (f->flag == '-')
		{
			ft_memmove(wid, src, len);
			ft_memset(&wid[len], ' ', f->width - len);
		}
		else if (f->flag == '0')
		{
			ft_memmove(wid, src, len);
			ft_memset(&wid[len], '0', f->width - len);
		}
		else
		{
			ft_memset(wid, ' ', f->width - len);
			ft_memmove(&wid[f->width - len], src, len);
		}
	}
	return (wid);
}

int		type_p(t_fields *f, unsigned long long int arg)
{
	char	*p;
	char	*prec;
	char	*wid;

  if (f->precision > -1 && arg == '\0')
    p = ft_strdup("");
  else if (arg == '\0')
    p = ft_itoa_base(0, 16);
  else
    p = ft_itoa_base(arg, 16);
	prec = precision_p(p, f);
	wid = width_p(prec, f);
	ft_putstr(wid);
	return ((int)ft_strlen(wid));
}
