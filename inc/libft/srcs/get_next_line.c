/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlufulua <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 11:27:15 by tlufulua          #+#    #+#             */
/*   Updated: 2021/04/14 21:25:30 by tlufulua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	delete(char **ptr)
{
	if (ptr && *ptr)
	{
		free(*ptr);
		*ptr = 0;
	}
}

int	read_fd(int fd, char **stat)
{
	char		buffer[BUFFER_SIZE + 1];
	int			ret;
	char		*aux;

	ret = read(fd, buffer, BUFFER_SIZE);
	if (ret < 0)
	{
		delete(stat);
		return (-1);
	}
	buffer[ret] = 0;
	if (*buffer && stat)
	{
		aux = *stat;
		*stat = ft_strjoin(aux, buffer);
		delete(&aux);
		if (!*stat)
			return (-1);
	}
	return (ret);
}

int	make_line(char **line, char **stat, char *newline)
{
	int		len;
	char	*aux;

	if (!newline)
	{
		*line = ft_strdup(*stat);
		if (!line)
			return (0);
	}
	else
	{
		len = newline - *stat;
		*line = ft_substr(*stat, 0, len);
		if (!*line)
		{
			delete(stat);
			return (0);
		}
		aux = *stat;
		*stat = ft_strdup(newline + 1);
		delete(&aux);
		if (!*stat)
			return (0);
	}
	return (1);
}

int	get_next_line(int fd, char **line)
{
	static char	*stat[1024];
	int			ret;
	char		*newline;

	ret = 1;
	if (fd < 0 || BUFFER_SIZE <= 0 || !line)
		return (-1);
	if (!stat[fd])
		stat[fd] = ft_strdup("");
	newline = ft_strchr(stat[fd], '\n');
	while (!newline && stat[fd] != 0)
	{
		ret = read_fd(fd, &stat[fd]);
		if (ret < 0)
			return (ret);
		if (ret == 0)
			break ;
		newline = ft_strchr(stat[fd], '\n');
	}
	if (!stat[fd] || !make_line(line, &stat[fd], newline))
		return (-1);
	if (ret == 0)
		delete(&stat[fd]);
	return (ret > 0);
}
