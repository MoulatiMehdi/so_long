/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 13:25:33 by mmoulati          #+#    #+#             */
/*   Updated: 2025/03/11 17:06:52 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "so_long.h"

#define ERR_MSG "ERROR\n"

static void	ft_map_data_init(t_map *map, t_list *head)
{
	int		i;
	t_list	*p;
	size_t	len;

	map->data = ft_calloc(map->height + 1, sizeof(char *));
	if (map->data == NULL)
		return ;
	i = map->height;
	map->data[i--] = NULL;
	while (head)
	{
		map->data[i] = head->content;
		len = ft_strlen(head->content);
		if (map->data[i][len - 1] == '\n')
			map->data[i][len - 1] = '\0';
		p = head;
		head = head->next;
		free(p);
		i--;
	}
	map->width = ft_strlen(map->data[0]);
}

static void	ft_map_read(t_map *map, int fd)
{
	char	*str;
	t_list	*head;
	t_list	*new_elem;

	head = NULL;
	while (1)
	{
		str = get_next_line(fd);
		if (str == NULL)
			break ;
		new_elem = ft_lstnew(str);
		if (new_elem == NULL)
		{
			free(str);
			return (ft_lstclear(&head, free));
		}
		ft_lstadd_front(&head, new_elem);
		map->height++;
	}
	ft_map_data_init(map, head);
}

t_map	*ft_map_new(char *filename)
{
	t_map	*map;
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		ft_perror(filename);
	map = ft_calloc(sizeof(t_map), 1);
	if (map)
		ft_map_read(map, fd);
	else
		ft_perror("malloc");
	close(fd);
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
