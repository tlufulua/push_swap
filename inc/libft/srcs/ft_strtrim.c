/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlufulua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 15:45:32 by tlufulua          #+#    #+#             */
/*   Updated: 2021/04/03 16:20:33 by tlufulua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s1, const char *set)
{
	const char	*end;

	if (!s1)
		return (0);
	while (*s1 && ft_strchr(set, *s1))
		s1++;
	end = &s1[ft_strlen(s1)];
	while (end > s1 && ft_strchr(set, *(end - 1)))
		end--;
	s1 = ft_substr(s1, 0, end - s1);
	if (s1 == 0)
		return (0);
	return ((char *)s1);
}
