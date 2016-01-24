/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvillat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/24 15:08:21 by gvillat           #+#    #+#             */
/*   Updated: 2016/01/24 16:16:50 by gvillat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int			ft_dupanddel(char **line, char **save, char **buf, int res)
{
	if (!(*line = ft_strdup(*save)))
		return (-1);
	ft_strdel(&*save);
	ft_strdel(&*buf);
	if (res == 0 || res == EOF)
		return (0);
	return (-1);
}

int					get_next_line(int const fd, char **line)
{
	static char		*save = NULL;
	int				i;
	char			*buf;
	int				res;

	i = 0;
	if (fd < 0 || !line || BUFF_SIZE < 1)
		return (-1);
	while (i < BUFF_SIZE)
	{
		if (!save)
			save = ft_strnew(2);
		buf = ft_strnew(2);
		if ((res = read(fd, buf, 1)) < 0)
			return (-1);
		if (*buf != '\n' && (res != 0 || res != EOF))
			save = ft_strjoin(save, buf);
		if (*buf == '\n' || res == 0 || res == EOF)
			return (ft_dupanddel(line, &save, &buf, res));
		i++;
	}
	if (i == BUFF_SIZE)
		return (get_next_line(fd, line));
	return (-1);
}
