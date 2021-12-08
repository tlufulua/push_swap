/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chars_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlufulua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/18 01:40:52 by tlufulua          #+#    #+#             */
/*   Updated: 2021/10/20 00:31:08 by tlufulua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void	write_str(va_list arg, const char **format, t_store *ste)
{
	char	*aux;

	aux = va_arg(arg, char *);
	if (aux)
		ste->result = ft_strdup(aux);
	else
		ste->result = ft_strdup("(null)");
	if (ste->flags)
	{
		ste->flags |= STR;
		mk_flags(ste);
	}
	(*format)++;
}

void	write_char(va_list arg, const char **format, t_store *ste)
{
	int	chr;

	ste->flags |= CHAR;
	chr = va_arg(arg, int);
	ste->result = (char *)ft_calloc(sizeof(char), 2);
	ft_memset(ste->result, chr, 1);
	if (chr == '\0')
		ste->count += write(1, "\0", 1);
	if (ste->flags)
	{
		mk_flags(ste);
		write_result(ste);
	}
	(*format)++;
}

void	write_percent(va_list arg, const char **format, t_store *ste)
{
	arg = 0;
	ste->result = ft_strdup("%");
	if (ste->flags)
		mk_flags(ste);
	(*format)++;
}
