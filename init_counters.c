/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_counters.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lramos-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/06 20:11:23 by lramos-r          #+#    #+#             */
/*   Updated: 2020/03/06 20:15:49 by lramos-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

t_count	*init_counters(void)
{
	t_count	*counter;

	if (!(counter = (t_count *)malloc(sizeof(t_count *))))
		return (NULL);
	counter->i = 0;
	counter->j = 0;
	counter->k = 0;
	counter->n = 0;
	return (counter);
}
