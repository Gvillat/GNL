#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

void ft_exit(const char *str)
{
	if (str)
		ft_putendl_fd(str, 2);
	exit(1);
}

/* Main pour STDIN */

int		main(void)
{
	char	*line;
	int		fd;
	int		code;
	int		len;

	fd = 0;
	while ((code = get_next_line(fd, &line)) > 0)
	{
		len = ft_strlen(line);
		printf("%d - %d - |%s|\n", code, len, line);
		free(line);
	}
	return (0);
}

/* Main Basique 

int		main(int argc, char **argv)
{
	char		*line;
	int			fd;
	int			code;
	int			len;
	int			i;

	i = 1;
	while (i < argc)
	{
		if ((fd = open(argv[i], O_RDONLY)) == -1)
			ft_exit("Error : NIQUE TA MER");
		while ((code = get_next_line(fd, &line)) > 0)
		{
			len = ft_strlen(line);
			printf("%d - %d - |%s|\n", code, len, line);
			free(line);
		}
		i++;
		if (i < argc)
			printf("\n___Changement de FD___ \n\n");
	}
	printf("LAST %d _ |%s|\n", code, line);
	return (0);
}
*/
