/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lramos-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 13:51:36 by lramos-r          #+#    #+#             */
/*   Updated: 2020/03/06 18:37:37 by lramos-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

size_t		ft_strlen(const char *t)
{
	int i;

	i = 0;
	while (t[i] != '\0')
		i++;
	return (i);
}
