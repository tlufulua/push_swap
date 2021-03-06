/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlufulua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 18:15:59 by tlufulua          #+#    #+#             */
/*   Updated: 2021/05/09 15:50:17 by tlufulua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

int	ft_atoi(const char *str)
{
	int		n;
	int		x;

	n = 0;
	x = 1;
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str++ == '-')
			x = -1;
	}
	while (*str >= '0' && *str <= '9')
		n = (n * 10) + (*str++ - '0');
	return (x * n);
}
