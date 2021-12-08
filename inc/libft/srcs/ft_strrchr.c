/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlufulua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/24 18:31:31 by tlufulua          #+#    #+#             */
/*   Updated: 2021/02/08 15:43:19 by tlufulua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*result;

	result = 0;
	while (*s)
		if (*s++ == (char)c)
			result = (char *)s - 1;
	if (*s == (char)c)
		result = (char *)s;
	return (result);
}
