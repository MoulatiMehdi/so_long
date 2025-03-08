/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 20:29:51 by mmoulati          #+#    #+#             */
/*   Updated: 2025/03/08 16:47:16 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "so_long.h"
#include <stdbool.h>
#include <stdio.h>

static t_map_state	ft_file_isvalid(char *filename)
{
	size_t	size;

	if (filename == NULL)
		return (ERR_FILENAME_INVALID);
	size = ft_strlen(filename);
	if (size < 5)
		return (ERR_FILENAME_INVALID);
	if (ft_strncmp(&filename[size - 4], ".ber", 4) != 0)
		return (ERR_FILENAME_INVALID);
	return (OK);
}

static int	ft_file_open(char *filename)
{
	int			fd;
	t_map_state	state;

	state = ft_file_isvalid(filename);
	if (filename == NULL || state != OK)
		ft_map_error(NULL, state);
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

t_map	*ft_map_new(char *filename)
{
	int		fd;
	int		i;
	t_map	*map;
	int		len;

	map = ft_calloc(sizeof(t_map), 1);
	if (map == NULL)
		return (NULL);
	i = 0;
	fd = ft_file_open(filename);
	map->height = ft_count_height(filename);
	map->data = malloc(sizeof(char *) * (map->height + 1));
	while (i < map->height)
	{
		map->data[i] = get_next_line(fd);
		if (!map->data[i])
			break ;
		len = ft_strlen(map->data[i]);
		if (map->data[i][0] != '\0' && map->data[i][len - 1] == '\n')
			map->data[i][len - 1] = '\0';
		i++;
	}
	map->data[i] = NULL;
	return (map);
}

void	ft_map_destroy(t_map **map)
{
	if (map == NULL || *map == NULL)
		return ;
	ft_split_free(&(*map)->data);
	free(*map);
	*map = NULL;
}
