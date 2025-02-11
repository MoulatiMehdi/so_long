/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 20:29:51 by mmoulati          #+#    #+#             */
/*   Updated: 2025/02/11 23:14:15 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "so_long.h"
#include <stdbool.h>
#include <stdio.h>

static bool	ft_file_isvalid(char *filename)
{
	size_t	size;

	if (filename == NULL)
		return (false);
	size = ft_strlen(filename);
	if (size < 4)
		return (false);
	if (ft_strncmp(&filename[size - 4], ".ber", 4) != 0)
		return (false);
	return (true);
}

static int	ft_file_open(char *filename)
{
	int	fd;

	if (filename == NULL || ft_file_isvalid(filename) == 0)
		ft_map_error(NULL, ERR_FILENAME_INVALID);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		ft_error(filename);
		exit(1);
	}
	return (fd);
}

static size_t	ft_count_nl(char *str, ssize_t bytes)
{
	ssize_t	j;
	ssize_t	count;

	j = 0;
	count = 0;
	while (j < bytes)
	{
		if (str[j] == '\n')
			count++;
		j++;
	}
	return (count);
}

static size_t	ft_count_height(char *file)
{
	int		fd;
	char	line[1024];
	size_t	count;
	ssize_t	bytes;

	fd = ft_file_open(file);
	count = 0;
	bytes = 1;
	while (bytes > 0)
	{
		bytes = read(fd, line, 1024);
		if (bytes < 0)
			ft_perror(file);
		count += ft_count_nl(line, bytes);
	}
	close(fd);
	return (count);
}

char	**ft_map_read(char *filename)
{
	int		fd;
	char	**strs;
	size_t	i;
	size_t	size;
	size_t	len;

	i = 0;
	fd = ft_file_open(filename);
	size = ft_count_height(filename);
	strs = malloc(sizeof(char *) * (size + 1));
	while (i < size)
	{
		strs[i] = get_next_line(fd);
		len = ft_strlen(strs[i]);
		if (strs[i] && strs[i][0] != '\0' && strs[i][len - 1] == '\n')
			strs[i][len - 1] = '\0';
		i++;
	}
	strs[i] = NULL;
	return (strs);
}
