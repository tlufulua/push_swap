/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlufulua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 19:50:53 by tlufulua          #+#    #+#             */
/*   Updated: 2021/03/01 18:44:06 by tlufulua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	if (!n)
		return (0);
	while (n-- > 0 && *(unsigned char *)s1 == *(unsigned char *)s2)
	{
		if (!n || *s1++ == '\0' || *s2++ == '\0')
			return (*(unsigned char *)s1 - *(unsigned char *)s2);
	}
	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}
