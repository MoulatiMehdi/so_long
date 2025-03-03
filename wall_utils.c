#include "wall.h"

bool	is_valid_point(t_map *map, t_point *point)
{
	return (point->x >= 0 && point->y >= 0 && point->y < map->height
		&& point->x < map->width);
}

int	ft_wall_tonbr(t_map *map, t_point *point)
{
	t_point	p;
	int		i;
	int		j;
	int		test;

	test = 0;
	i = -1;
	while (i < 2)
	{
		j = -1;
		while (j < 2)
		{
			p.x = point->x + i;
			p.y = point->y + j;
			test <<= 1;
			if (is_valid_point(map, &p))
				test += (map->data[p.y][p.x] == '1');
			else
				test++;
			j++;
		}
		i++;
	}
	return (test);
}
