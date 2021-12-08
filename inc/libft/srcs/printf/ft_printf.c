/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlufulua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 17:45:47 by tlufulua          #+#    #+#             */
/*   Updated: 2021/10/20 00:31:36 by tlufulua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int	ft_printf(const char *format, ...)
{
	t_store			ste;
	va_list			arg;
	static t_funct	fts[NB_OF_FTS];

	va_start(arg, format);
	ft_bzero(&ste, sizeof(ste));
	if (!fts->c)
		start_structs(fts);
	while (*format)
	{
		if (*format && *format != '%')
			ste.count += write(1, format++, 1);
		else if (*format == '%' && format++)
		{
			if (!ft_isalpha(*format))
				get_flags(arg, &ste, &format);
			mk_funct(fts, &format, &ste, arg);
			write_result(&ste);
		}
	}
	va_end(arg);
	return (ste.count);
}
