/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lramos-r <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 10:55:38 by lramos-r          #+#    #+#             */
/*   Updated: 2020/03/06 18:39:35 by lramos-r         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*sub;
	unsigned int	i;
	unsigned int	j;

	if (s == NULL)
		return (NULL);
	sub = (char *)malloc((len + 1) * (sizeof(char)));
	if (!sub)
		return (NULL);
	i = 0;
	while (i < start && s[i])
		i++;
	j = 0;
	while (j < len && s[i])
	{
		sub[j] = s[i];
		j++;
		i++;
	}
	sub[j] = '\0';
	return (sub);
}
