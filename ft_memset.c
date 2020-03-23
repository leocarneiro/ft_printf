/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lramos-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 12:52:14 by lramos-r          #+#    #+#             */
/*   Updated: 2020/03/06 18:41:59 by lramos-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	*ft_memset(void *str, int c, size_t len)
{
	size_t	i;
	char	*s;

	s = str;
	i = 0;
	while (i < len)
	{
		s[i] = c;
		i++;
	}
	return (s);
}
