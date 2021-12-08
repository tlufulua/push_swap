/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlufulua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/13 18:39:47 by tlufulua          #+#    #+#             */
/*   Updated: 2021/10/20 00:33:45 by tlufulua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H
# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <limits.h>
# include <libft.h>

# define NB_OF_FTS 8

# define WIDTH		0x01
# define MINUS		0x02
# define ZERO		0x04
# define PRECISION	0x08
# define PLUS		0x10
# define SPACE		0x20
# define HASHTAG	0x40
# define NUM		0x80
# define STR		0x100
# define CHAR		0x200

typedef struct s_store
{
	int		count;
	int		flags;
	int		width;
	int		precision;
	char	*result;
}				t_store;

typedef struct s_funct
{
	int		c;
	void	(*f)(va_list arg, const char **format, t_store *ste);
}				t_funct;

int			ft_printf(const char *format, ...);
void		start_structs(t_funct *fts);
void		mk_funct(t_funct *fts, const char **format, \
			t_store *ste, va_list arg);
void		write_result(t_store *ste);

void		mk_flags(t_store *ste);
void		width(t_store *ste);
void		precision(t_store *ste);
void		spaces(t_store *ste, char **spc, int type);
void		get_flags(va_list arg, t_store *ste, const char **format);
void		digit(va_list arg, t_store *ste, const char **format);

void		write_int(va_list arg, const char **format, t_store *ste);
void		write_unint(va_list arg, const char **format, t_store *ste);
void		write_str(va_list arg, const char **format, t_store *ste);
void		write_percent(va_list arg, const char **format, \
			t_store *ste);
void		write_char(va_list arg, const char **format, t_store *ste);
void		write_hex(va_list arg, const char **format, t_store *ste);
void		write_heX(va_list arg, const char **format, t_store *ste);
void		write_long_hex(va_list arg, const char **format, \
			t_store *ste);

#endif
