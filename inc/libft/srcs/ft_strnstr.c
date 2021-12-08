/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlufulua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 18:48:00 by tlufulua          #+#    #+#             */
/*   Updated: 2021/03/01 18:44:03 by tlufulua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t		n;
	size_t		i;

	i = 0;
	if (!(*needle))
		return ((char *)haystack);
	while (i < len && haystack[i])
	{
		n = 0;
		while (haystack[n + i] == needle[n] && (i + n) < len)
		{
			if (!(needle[n + 1]))
				return ((char *)haystack + i);
			n++;
		}
		i++;
	}
	return (0);
}
