/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlufulua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 22:22:40 by tlufulua          #+#    #+#             */
/*   Updated: 2021/10/20 00:32:01 by tlufulua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void	digit(va_list arg, t_store *ste, const char **format)
{
	if (**format == '.' && (*format)++)
	{
		if (**format == '*' && (*format)++)
			ste->precision = va_arg(arg, int);
		else
			ste->precision = ft_atoi(*format);
	}
	else if (**format == '0')
	{
		ste->flags |= ZERO;
		ste->width = ft_atoi(*format);
	}
	else if (**format == '*' && (*format)++)
	{	
		ste->width = va_arg(arg, unsigned int);
		if (ste->width < 0)
		{
			ste->flags |= MINUS;
			ste->width *= -1;
		}
	}
	else
		ste->width = ft_atoi(*format);
	while (ft_isdigit(**format))
		(*format)++;
}

void	get_flags(va_list arg, t_store *ste, const char **format)
{
	while (!ft_isalpha(**format) && **format != '%')
	{
		if (ft_isdigit(**format) || **format == '*')
		{
			ste->flags |= WIDTH;
			digit(arg, ste, format);
		}
		else if (**format == ' ')
		{
			ste->flags |= SPACE;
			ste->count += write(1, " ", 1);
			(*format)++;
		}
		else if (**format == '.')
		{
			digit(arg, ste, format);
			ste->flags |= PRECISION;
		}
		else if (**format == '-' && (*format)++)
			ste->flags |= MINUS;
		else if (**format == '+' && (*format)++)
			ste->flags |= PLUS;
		else if (**format == '#' && (*format)++)
			ste->flags |= HASHTAG;
	}
}
