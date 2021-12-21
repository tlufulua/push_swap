/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdiff.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlufulua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 04:24:35 by tlufulua          #+#    #+#             */
/*   Updated: 2021/12/21 04:32:54 by tlufulua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

/*
 * Comprueba si hay algún caractér distinto a 'c' en la cadena s. Si lo hay, devuelve 0.
 */
int	ft_isdiff(const char *s, int c)
{
	while (*s)
	{
		if (*s != c)
			return (1);
		s++;
	}
	return (0);
}
