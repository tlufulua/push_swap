/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlufulua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/22 13:38:58 by tlufulua          #+#    #+#             */
/*   Updated: 2021/02/26 20:51:38 by tlufulua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	int		x;

	x = 0;
	if (dst < src)
	{
		while (n--)
		{
			*(char *)(dst + x) = *(char *)(src + x);
			x++;
		}
		return (dst);
	}
	return (ft_memcpy(dst, src, n));
}
