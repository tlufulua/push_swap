/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlufulua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 12:13:47 by tlufulua          #+#    #+#             */
/*   Updated: 2021/02/28 14:06:33 by tlufulua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *str, int c, size_t n)
{
	while (n--)
	{
		*(char *)dst++ = *(char *)str;
		if (*(unsigned char *)str++ == (unsigned char)c)
			return (dst);
	}
	return (0);
}
