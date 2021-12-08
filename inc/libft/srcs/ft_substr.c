/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlufulua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/01 01:08:04 by tlufulua          #+#    #+#             */
/*   Updated: 2021/04/03 14:59:15 by tlufulua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_substr(const char *s, unsigned int start, unsigned int len)
{
	char			*buffer;
	unsigned int	n;

	n = 0;
	buffer = (char *)malloc(sizeof(char) * (len + 1));
	if (!s || !buffer)
		return (0);
	while (len-- && start < ft_strlen(s))
		buffer[n++] = s[start++];
	buffer[n] = '\0';
	return (buffer);
}
