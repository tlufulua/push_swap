/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlufulua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 15:52:26 by tlufulua          #+#    #+#             */
/*   Updated: 2021/04/03 16:42:24 by tlufulua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dst_size)
{
	size_t	dstlen;
	size_t	srclen;
	size_t	n;

	dstlen = 0;
	if (dst_size > 0)
		dstlen = ft_strlen(dst);
	srclen = ft_strlen(src);
	n = dstlen;
	if (dstlen < dst_size)
	{
		while (*src && n + 1 < dst_size)
			dst[n++] = *(char *)src++;
		dst[n] = '\0';
		return (dstlen + srclen);
	}
	return (dst_size + srclen);
}
