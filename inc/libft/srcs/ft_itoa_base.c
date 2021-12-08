/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlufulua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 14:27:44 by tlufulua          #+#    #+#             */
/*   Updated: 2021/10/02 16:11:58 by tlufulua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	bytes_str(unsigned int n, int bs)
{
	size_t	len;

	len = (n == 0);
	while (n)
	{
		n = n / bs;
		len++;
	}
	return (len);
}

int	check_base(char *base, int *bs)
{
	char	*or_base;
	int		i;

	or_base = base;
	i = 0;
	if (!base || ft_strlen(base) > 16 || repeat_char(base))
		return (0);
	while (*or_base)
	{
		if (*or_base < '0' || (*or_base > '9' && *or_base < 'a' ) \
				|| *or_base > 'f')
			return (0);
		or_base++;
	}
	*bs = ft_strlen(base);
	return (1);
}

char	*ft_itoa_base(long int n, char *base)
{
	unsigned int	num;
	size_t			len;
	char			*str;
	int				bs;

	if (!check_base(base, &bs))
		return (0);
	num = n;
	if (bs == 10 && n < 0)
		num = n * -1;
	len = bytes_str(num, bs) + (n < 0 && bs == 10);
	str = (char *)ft_calloc(sizeof(char), len-- + 1);
	if (str && n == 0)
		str[len] = '0';
	while (str && num > 0)
	{
		if ((num % bs) < 10)
			str[len--] = (num % bs) + '0';
		else
			str[len--] = ((num % bs) + 39) + '0';
		num = num / bs;
	}
	if (n < 0 && bs == 10)
		str[0] = '-';
	return (str);
}
