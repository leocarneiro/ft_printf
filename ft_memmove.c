/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lramos-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 17:20:49 by lramos-r          #+#    #+#             */
/*   Updated: 2020/03/09 15:44:56 by lramos-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	size_t				i;
	unsigned char		*d;
	const unsigned char	*s;

	i = 1;
	d = dest;
	s = src;
	if ((dest == NULL && src == NULL) || len == 0)
		return (dest);
	if (s < d)
		while (i <= len)
		{
			d[len - i] = s[len - i];
			i++;
		}
	else
		while (len > 0)
		{
			*d++ = *s++;
			len--;
		}
	return (dest);
}
