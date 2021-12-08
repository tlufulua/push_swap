/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlufulua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 13:28:22 by tlufulua          #+#    #+#             */
/*   Updated: 2021/07/13 07:58:48 by tlufulua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*newstr;
	int		n;

	n = 0;
	newstr = (char *)ft_calloc(sizeof(char), \
			(ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!s1 || !s2 || !newstr)
		return (NULL);
	while (*s1)
		newstr[n++] = *s1++;
	while (*s2)
		newstr[n++] = *s2++;
	return (newstr);
}
