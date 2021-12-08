/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   funct_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlufulua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/16 17:45:47 by tlufulua          #+#    #+#             */
/*   Updated: 2021/10/20 00:31:48 by tlufulua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

void	start_structs(t_funct *fts)
{
	fts[0] = (t_funct){'%', &write_percent};
	fts[1] = (t_funct){'c', &write_char};
	fts[2] = (t_funct){'s', &write_str};
	fts[3] = (t_funct){'p', &write_long_hex};
	fts[4] = (t_funct){'d', &write_int};
	fts[5] = (t_funct){'i', &write_int};
	fts[6] = (t_funct){'u', &write_unint};
	fts[7] = (t_funct){'x', &write_hex};
	fts[8] = (t_funct){'X', &write_heX};
}

void	mk_funct(t_funct *fts, const char **format, t_store *ste, \
		va_list arg)
{
	int		i;

	i = 0;
	while (i <= NB_OF_FTS)
	{
		if (fts[i].c == **format)
		{
			fts[i].f(arg, format, ste);
			i = 0;
			break ;
		}
		i++;
	}
}

void	write_result(t_store *ste)
{
	if (ste->result)
	{
		ste->count += write(1, ste->result, ft_strlen(ste->result));
		free(ste->result);
		ste->result = 0;
		ste->flags = 0;
	}
}
