/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlufulua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 17:25:59 by tlufulua          #+#    #+#             */
/*   Updated: 2021/04/03 17:32:08 by tlufulua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	numb_of_str(const char *s, char c)
{
	int		wd_size;
	int		nb_wd;

	wd_size = 0;
	nb_wd = 0;
	while (*s)
	{
		if (*s != c)
			wd_size += 1;
		else if (*s == c)
			wd_size = 0;
		if (wd_size == 1)
			nb_wd += 1;
		s++;
	}
	return (nb_wd);
}

static int	lenofstr(const char *s, char c)
{
	int		i;

	i = 0;
	while (*s && *s++ != c)
		i++;
	return (i);
}

static void	free_split(char **array, int x)
{
	while (x-- > 0)
		free(array[x]);
	free(array);
}

static char	**write_words(char **array, const char *s, char c, int nb)
{
	int		len;
	int		x;
	int		y;

	x = 0;
	while (x < nb)
	{
		while (*s == c)
			s++;
		len = lenofstr(s, c);
		array[x] = (char *)malloc(sizeof(char) * (len + 1));
		if (!array[x])
		{
			free_split(array, x);
			return (0);
		}
		y = 0;
		while (y < len)
			array[x][y++] = *s++;
		array[x][y] = '\0';
		x++;
	}
	array[nb] = NULL;
	return (array);
}

char	**ft_split(const char *s, char c)
{
	char	**array;
	int		nb;

	if (!s)
		return (0);
	nb = numb_of_str(s, c);
	array = (char **)malloc(sizeof(char *) * (nb + 1));
	if (!array)
		return (0);
	return (write_words(array, s, c, nb));
}
