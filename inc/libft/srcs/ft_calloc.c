/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlufulua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 15:57:31 by tlufulua          #+#    #+#             */
/*   Updated: 2021/06/30 19:10:25 by tlufulua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_calloc(unsigned int count, unsigned int size)
{
	void	*buffer;

	buffer = (char *)malloc(size * count);
	if (!buffer)
		return (0);
	else
		ft_bzero(buffer, size * count);
	return (buffer);
}
