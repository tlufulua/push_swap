/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlufulua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/14 16:38:08 by tlufulua          #+#    #+#             */
/*   Updated: 2021/10/20 00:31:22 by tlufulua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void	spaces(t_store *ste, char **spc, int type)
{
	int		i;

	i = 0;
	spc[0] = (char *)ft_calloc(ste->width + 1, sizeof(char));
	while (i < type)
	{
		if (ste->flags & ZERO && !(ste->flags & MINUS) \
				&& ste->flags & NUM)
		{
			if (*ste->result == '-' && i == 0)
			{
				spc[0][i++] = '-';
				ste->result[0] = '0';
			}
			else if (ste->flags & PLUS && i == 0)
				spc[0][i++] = '+';
			if (i < type)
				spc[0][i++] = '0';
		}
		else
			spc[0][i++] = ' ';
	}
}

void	width(t_store *ste)
{
	char	*spc;
	char	*aux;
	int		len;

	len = ft_strlen(ste->result);
	aux = ste->result;
	ste->width -= len;
	if (ste->flags & CHAR && len == 0)
		ste->width--;
	if (ste->flags & SPACE && ste->width)
		ste->width--;
	if (ste->width <= 0)
		return ;
	spaces(ste, &spc, ste->width);
	if (ste->flags & MINUS)
		ste->result = ft_strjoin(ste->result, spc);
	else
		ste->result = ft_strjoin(spc, ste->result);
	free(spc);
	free(aux);
}

void	precision(t_store *ste)
{
	char	*spc;
	char	*aux;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(ste->result);
	spc = (char *)ft_calloc(ste->precision, sizeof(char));
	ste->precision -= len;
	while (ste->precision-- > 0)
		spc[i++] = '0';
	aux = ste->result;
	ste->result = ft_strjoin(spc, ste->result);
	free(spc);
	free(aux);
}

void	mk_flags(t_store *ste)
{
	int		len;

	len = ft_strlen(ste->result);
	if (ste->flags & PRECISION)
	{
		if (ste->precision == 0 && !ft_strncmp(ste->result, "0", 2))
			ste->result[len - 1] = '\0';
		if (ste->flags & NUM && len < ste->precision)
			precision(ste);
		else if (ste->flags & STR)
			while (len >= ste->precision)
				ste->result[len--] = 0;
	}
	if (ste->flags & WIDTH)
		width(ste);
}
