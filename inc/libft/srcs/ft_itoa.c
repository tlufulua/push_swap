/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlufulua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 14:27:44 by tlufulua          #+#    #+#             */
/*   Updated: 2021/08/07 21:14:12 by tlufulua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	bytes_str(unsigned int len)
{
	size_t	bytes;

	bytes = (len == 0);
	while (len > 0)
	{
		len = len / 10;
		bytes++;
	}
	return (bytes);
}

char	*ft_itoa(long int n)
{
	size_t				str_size;
	char				*nb;
	unsigned int		x;

	x = n;
	if (n < 0)
		x = n * -1;
	str_size = (n < 0) + bytes_str(x);
	nb = (char *)ft_calloc(sizeof(char), (str_size-- + 1));
	if (nb && x == 0)
		nb[str_size] = 0 + '0';
	while (nb && x > 0)
	{
		nb[str_size--] = (x % 10) + '0';
		x = x / 10;
	}
	if (n < 0)
		nb[0] = '-';
	return (nb);
}
