/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_union.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlufulua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 18:38:49 by tlufulua          #+#    #+#             */
/*   Updated: 2021/09/02 15:26:52 by tlufulua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
 *  This function compares two strings and displays, without doubles, 
 *  the characters that appear in either one of the strings.
 *
 *  The display will be in the order characters appear in the command line, and
 *  will be followed by a '\n'. If the number of arguments is not 2, the program 
 *  displays '\n'.
 *
 *  It returns the number of displays characters.
*/

int	ft_union(char *s1, char *s2)
{
	size_t	n;
	size_t	len;
	char	*start;
	char	*aux;

	if (!s1 || !s2)
		return (write(1, "\n", 1));
	start = ft_strjoin(s1, s2);
	len = ft_strlen(start) + 1;
	aux = start;
	n = 0;
	while (n < len && s1 && s2)
	{
		if (*aux != '\0' && !ft_memchr(start, *aux, n))
			write(1, aux, 1);
		aux++;
		n++;
	}
	write(1, "\n", 1);
	free(start);
	return (n);
}
