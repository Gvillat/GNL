/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gvillat <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/24 15:59:54 by gvillat           #+#    #+#             */
/*   Updated: 2016/01/24 17:22:21 by gvillat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int		main(int argc, char **argv)
{
	int		fd;
	int		i;
	char	*line;

	if (argc != 2)
		return (0);
	line = NULL;
	fd = open(argv[1], O_RDONLY);
	i = get_next_line(fd, &line);
	while (i > 0)
	{
		printf("%s\n", line);
		i = get_next_line(fd, &line);

	}
	return (0);
}