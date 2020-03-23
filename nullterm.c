/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nullterm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lramos-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/12 17:22:57 by lramos-r          #+#    #+#             */
/*   Updated: 2020/03/12 17:42:39 by lramos-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int		nullterm(t_fields *f, int arg)
{
	int		i;

	i = 1;
  if (f->width < 0)
  {
    f->width = f->width * (-1);
    f->flag = '-';
  }
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
		while (i < f->width)
		{
			ft_putchar(' ');
			i++;
		}
		ft_putchar(arg);
	}
	return (i);
}
