/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   integers_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlufulua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 01:34:20 by tlufulua          #+#    #+#             */
/*   Updated: 2022/01/07 18:08:37 by tlufulua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void	write_int(va_list arg, const char **format, t_store *ste)
{
	ste->result = ft_itoa(va_arg(arg, int));
	if (ste->flags)
	{
		ste->flags |= NUM;
		mk_flags(ste);
	}
	(*format)++;
}

void	write_unint(va_list arg, const char **format, t_store *ste)
{
	long int		num;

	num = va_arg(arg, long int);
	if (num < 0)
		ste->result = ft_strdup("0");
	else
		ste->result = ft_itoa(num);
	if (ste->flags)
	{
		ste->flags |= NUM;
		mk_flags(ste);
	}
	(*format)++;
}

void	write_hex(va_list arg, const char **format, t_store *ste)
{
	if (ste->flags & HASHTAG)
		write_long_hex(arg, format, ste);
	else
		ste->result = ft_itoa_base(va_arg(arg, unsigned int), HEX_BASE);
	if (ste->flags)
	{
		ste->flags |= NUM;
		mk_flags(ste);
	}
	if (!(ste->flags & HASHTAG))
		(*format)++;
}

void	write_hex_upper(va_list arg, const char **format, t_store *ste)
{
	char	*aux;

	if (ste->flags & HASHTAG)
		write_long_hex(arg, format, ste);
	else
		ste->result = ft_itoa_base(va_arg(arg, unsigned int), HEX_BASE);
	aux = ste->result;
	while (*aux)
	{
		*aux = ft_toupper(*aux);
		aux++;
	}
	if (ste->flags)
	{
		ste->flags |= NUM;
		mk_flags(ste);
	}
	if (!(ste->flags & HASHTAG))
		(*format)++;
}

void	write_long_hex(va_list arg, const char **format, t_store *ste)
{
	char	*nb;

	nb = ft_itoa_base(va_arg(arg, long unsigned int), HEX_BASE);
	if (*nb)
	{
		ste->result = ft_strjoin("0x", nb);
		free(nb);
	}
	if (ste->flags)
		mk_flags(ste);
	(*format)++;
}
