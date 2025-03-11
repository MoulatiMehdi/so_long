/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_solve.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 17:15:27 by mmoulati          #+#    #+#             */
/*   Updated: 2025/03/11 17:43:56 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "so_long.h"

static void	ft_map_eliminate(t_map *map, int x, int y)
{
	t_list	*head;
	t_list	*p;
	t_point	*point;

	head = NULL;
	ft_lstadd_front(&head, ft_lstnew(ft_point_new(x, y)));
	while (head)
	{
		p = head;
		head = head->next;
		point = p->content;
		x = point->x;
		y = point->y;
		if (ft_point_isvalid(map, point) && ft_strchr(CHARS_CHAGE,
				map->data[y][x]) == NULL)
		{
			map->data[y][x] = CHARS_CHAGE[ft_stridx(CHARS_VALID,
					map->data[y][x])];
			ft_lstadd_front(&head, ft_lstnew(ft_point_new(x - 1, y)));
			ft_lstadd_front(&head, ft_lstnew(ft_point_new(x + 1, y)));
			ft_lstadd_front(&head, ft_lstnew(ft_point_new(x, y - 1)));
			ft_lstadd_front(&head, ft_lstnew(ft_point_new(x, y + 1)));
		}
		ft_lstdelone(p, free);
	}
}

static void	ft_map_restore(t_map *map)
{
	t_point	p;
	int		idx;

	p.y = 0;
	while (p.y < map->height)
	{
		p.x = 0;
		while (p.x < map->width)
		{
			idx = ft_stridx(CHARS_CHAGE, map->data[p.y][p.x]);
			if (idx >= 0)
				map->data[p.y][p.x] = CHARS_VALID[idx];
			p.x++;
		}
		p.y++;
	}
	return ;
}

static bool	ft_map_islost(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->height)
	{
		if (ft_strchr(map->data[i], CHAR_COLLECTABLE))
			return (true);
		if (ft_strchr(map->data[i], CHAR_EXIT))
			return (true);
		if (ft_strchr(map->data[i], CHAR_PLAYER))
			return (true);
		i++;
	}
	return (false);
}

static void	ft_map_player(t_map *map, t_point *p)
{
	p->y = 0;
	while (p->y < map->height)
	{
		p->x = 0;
		while (p->x < map->width)
		{
			if (map->data[p->y][p->x] == CHAR_PLAYER)
				return ;
			p->x++;
		}
		p->y++;
	}
}

bool	ft_map_issolvable(t_map *map)
{
	t_point	p;

	ft_map_player(map, &p);
	ft_map_eliminate(map, p.x, p.y);
	if (ft_map_islost(map))
		return (false);
	ft_map_restore(map);
	return (true);
}
