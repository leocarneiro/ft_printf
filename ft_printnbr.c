/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lramos-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 19:55:42 by lramos-r          #+#    #+#             */
/*   Updated: 2020/03/13 12:22:58 by lramos-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

int	ft_printnbr(const char *aux)
{
	int	n;

	n = 0;
	while (ft_isnumber(*aux) == 1)
	{
		n = n * 10 + *aux - 48;
		aux++;
	}
	return (n);
}
