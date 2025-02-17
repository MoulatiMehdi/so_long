/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 22:10:35 by mmoulati          #+#    #+#             */
/*   Updated: 2025/02/02 12:13:11 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	indexof_nl(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

static char	*get_next_cache(char **line)
{
	char	*to_cache;
	ssize_t	i;
	char	*tmp;

	i = indexof_nl(*line);
	if (i < 0 || !(*line)[i + 1])
		return (NULL);
	to_cache = ft_strdup((*line) + i + 1);
	(*line)[i + 1] = 0;
	tmp = ft_strdup(*line);
	free(*line);
	if (!tmp || !to_cache)
	{
		free(tmp);
		free(to_cache);
		return (*line = NULL);
	}
	*line = tmp;
	if (to_cache && to_cache[0] == '\0')
	{
		free(to_cache);
		to_cache = NULL;
	}
	return (to_cache);
}

static char	*read_file(int fd, char *cache, char *buffer)
{
	ssize_t	bytes;
	char	*tmp;

	bytes = 1;
	while (bytes > 0)
	{
		bytes = read(fd, buffer, BUFFER_SIZE);
		if (bytes < 0)
		{
			free(cache);
			return (NULL);
		}
		if (bytes == 0)
			break ;
		buffer[bytes] = 0;
		tmp = cache;
		cache = ft_strjoin(cache, buffer);
		free(tmp);
		if (indexof_nl(buffer) >= 0 || !cache)
			break ;
	}
	return (cache);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	char		*line;
	static char	*cache;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (free(cache), cache = NULL);
	buffer = (char *)malloc((BUFFER_SIZE + 1UL) * sizeof(char));
	if (!buffer)
		return (free(cache), free(buffer), cache = NULL);
	line = read_file(fd, cache, buffer);
	free(buffer);
	if (!line)
		return (cache = NULL);
	cache = get_next_cache(&line);
	return (line);
}
