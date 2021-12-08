/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlufulua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/31 23:59:50 by tlufulua          #+#    #+#             */
/*   Updated: 2021/07/13 07:56:56 by tlufulua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*buffer;
	int		n;

	n = 0;
	buffer = (char *)ft_calloc(sizeof(char *), (ft_strlen(s1) + 1));
	if (!buffer)
		return (0);
	while (*s1)
		buffer[n++] = *s1++;
	return (buffer);
}
