#include "libft.h"
#include <ctype.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void	put(char *line, int scale)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	while (i < scale)
	{
		k = 0;
		while (line[k])
		{
			j = 0;
			if (ft_strchr("\"\n", line[k]) != NULL)
				ft_putchar_fd(line[k], 1);
			else
				while (j < scale)
				{
					ft_putchar_fd(line[k], 1);
					j++;
				}
			k++;
		}
		i++;
	}
}

char	**ft_strs_new(int width, int height)
{
	char	**strs;
	int		i;

	strs = malloc(sizeof(char *) * (height + 1));
	i = 0;
	while (i < height)
	{
		strs[i] = malloc(sizeof(char) * (width + 1));
		strs[i][width] = '\0';
		i++;
	}
	strs[i] = NULL;
	return (strs);
}

void	read_file(char *filename, int scale)
{
	char	**strs;
	char	*line;
	int		fd;
	int		arr[4];
	int		i;
	int		j;

	fd = open(filename, O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		ft_putstr_fd(line, 1);
		if (strstr(line, "rows") != NULL)
		{
			free(line);
			break ;
		}
		free(line);
	}
	line = get_next_line(fd);
	i = 0;
	j = 0;
	while (!isdigit(line[i]))
	{
		ft_putchar_fd(line[i], 1);
		i++;
	}
	while (j < 2)
	{
		arr[j] = atoi(&line[i]);
		ft_putnbr_fd(arr[j] * scale, 1);
		ft_putchar_fd(' ', 1);
		while (isdigit(line[i]))
			i++;
		while (!isdigit(line[i]) && line[i] != '\0')
			i++;
		j++;
	}
	ft_putstr_fd(&line[i], 1);
	free(line);
	while (1)
	{
		line = get_next_line(fd);
		ft_putstr_fd(line, 1);
		if (strstr(line, "pixels") != NULL)
		{
			free(line);
			break ;
		}
		free(line);
	}
	while (1)
	{
		line = get_next_line(fd);
		if (strstr(line, "}") != NULL)
			break ;
		put(line, scale);
		free(line);
	}
	while (line)
	{
		ft_putstr_fd(line, 1);
		free(line);
		line = get_next_line(fd);
	}
}

int	main(int argc, char *argv[])
{
	int	scale;

	scale = 2;
	if (argc < 2)
		return (0);
	if (argc >= 3)
		scale = ft_atoi(argv[2]);
	if (scale < 2)
	{
		fprintf(stderr, "Invalid scale\n");
		return (0);
	}
	read_file(argv[1], scale);
	return (EXIT_SUCCESS);
}
/*int		scale;*/
/*int		i;*/
/*int		j;*/
/*int		height;*/
/*int		width;*/
/*char	**res;*/
/*char	*arr[] = {"      ....      ", "     .XXoX..    ",*/
/*		"    .XXooooX.   ", " . ..OXXoXO.X.. ", ".+.@..OOOO..X.+.",*/
/*		".+.@@@....@@..+.", ".#+.@@@@@@@@.+#.", ".#.@........@.#.",*/
/*		" .#.#$$##$$#.#. ", "  .##$.++.$##.  ", "  ..#%.++.+#..  ",*/
/*		" .&&.#++++#..&. ", " .&&&..##...&&. ", " .&&..*..*=*.&. ",*/
/*		" .&.--.*==***.  ", "  ..--.*=**;;.  ", "  .*...;;.;**.  ",*/
/*		"  ..**;;;.*.... ", "   ...****.::O. ", "      ....:.... ",*/
/*		"          ...   ", "                ", "                ",*/
/*		"                ", NULL};*/
/**/
/*scale = 2;*/
/*i = 0;*/
/*width = strlen(arr[0]);*/
/*while (arr[i])*/
/*	i++;*/
/*height = i;*/
/*res = ft_strs_new(width * 2, height * 2);*/
/*i = 0;*/
/*while (i < height)*/
/*{*/
/*	j = 0;*/
/*	while (j < width)*/
/*	{*/
/*		put(arr, res, i, j, scale);*/
/*		j++;*/
/*	}*/
/*	i++;*/
/*}*/
/*i = 0;*/
/*while (i < height * 2)*/
/*{*/
/*	printf("\"%s\"\n", res[i]);*/
/*	free(res[i]);*/
/*	i++;*/
/*}*/
/*free(res);*/
