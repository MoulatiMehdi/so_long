#include "wall.h"

void	ft_map_fill_void(t_render *render, t_map *map)
{
	t_point		point;
	t_sprite	*sprite;
	int			i;

	sprite = render->sprites[SPRITE_FLOOR];
	sprite->x = sprite->frame_width * 1;
	sprite->y = sprite->frame_height * 1;
	i = 0;
	while (i < WINDOW_HEIGHT / 2 - map->height * 32)
	{
		point.x = 0;
		while (point.x < WINDOW_WIDTH)
		{
			point.y = i;
			ft_render_sprite(render, sprite, &point);
			point.y = WINDOW_HEIGHT - i - sprite->frame_height;
			ft_render_sprite(render, sprite, &point);
			point.x += sprite->frame_width;
		}
		i += sprite->frame_height;
	}
	while (i < WINDOW_HEIGHT / 2 + map->height * 32)
	{
		point.x = 0;
		while (point.x < WINDOW_WIDTH / 2 - map->width * 32)
		{
			point.y = i;
			i = point.x;
			ft_render_sprite(render, sprite, &point);
			point.x = WINDOW_WIDTH - i - sprite->frame_width;
			ft_render_sprite(render, sprite, &point);
			point.x = i;
			i = point.y;
			point.x += sprite->frame_width;
		}
		i += sprite->frame_height;
	}
	i = 0;
}

void	ft_map_wall(t_render *render, t_map *map)
{
	t_point	idx;
	t_point	shift;

	idx.x = 0;
	while (idx.x < map->width)
	{
		idx.y = 0;
		while (idx.y < map->height)
		{
			shift.x = WINDOW_WIDTH / 2 - map->width * 32 + idx.x * 64;
			shift.y = WINDOW_HEIGHT / 2 - map->height * 32 + idx.y * 64;
			if (map->data[idx.y][idx.x] == WALL_EMPTY)
				ft_map_floor_blue(render, &shift);
			else if (map->data[idx.y][idx.x] == WALL_ROOF)
				ft_map_roof(render, &shift);
			else if (map->data[idx.y][idx.x] == WALL_IN_MID_TOP)
				ft_map_middle_top(render, &shift);
			else if (map->data[idx.y][idx.x] == WALL_IN_MID_BOTTOM)
				ft_map_middle_bottom(render, &shift);
			else if (map->data[idx.y][idx.x] == WALL_IN_MID_LEFT)
				ft_map_middle_left(render, &shift);
			else if (map->data[idx.y][idx.x] == WALL_IN_MID_RIGHT)
				ft_map_middle_right(render, &shift);
			else if (map->data[idx.y][idx.x] == WALL_IN_LEFT_TOP)
				ft_map_wall_left_top(render, &shift);
			else if (map->data[idx.y][idx.x] == WALL_IN_LEFT_BOTTOM)
				ft_map_wall_left_bottom(render, &shift);
			else if (map->data[idx.y][idx.x] == WALL_IN_RIGHT_BOTTOM)
				ft_map_wall_right_bottom(render, &shift);
			else if (map->data[idx.y][idx.x] == WALL_IN_RIGHT_TOP)
				ft_map_wall_right_top(render, &shift);
			else if (map->data[idx.y][idx.x] == WALL_OUT_LEFT_TOP)
				ft_map_outside_left_top(render, &shift);
			else if (map->data[idx.y][idx.x] == WALL_OUT_LEFT_BOTTOM)
				ft_map_outside_left_bottom(render, &shift);
			else if (map->data[idx.y][idx.x] == WALL_OUT_RIGHT_BOTTOM)
				ft_map_outside_right_bottom(render, &shift);
			else if (map->data[idx.y][idx.x] == WALL_OUT_RIGHT_TOP)
				ft_map_outside_right_top(render, &shift);
			else if (map->data[idx.y][idx.x] == WALL_INTER_ANTIDIAGONAL)
				ft_map_inter_antidiagonal(render, &shift);
			else if (map->data[idx.y][idx.x] == WALL_INTER_DIAGONAL)
				ft_map_inter_diagonal(render, &shift);
			else if (map->data[idx.y][idx.x] == WALL_OBSTACLE)
				ft_map_obstacle(render, &shift);
			idx.y++;
		}
		idx.x++;
	}
}

void	ft_map_display(t_render *render, t_map *map)
{
	ft_map_fill_void(render, map);
	ft_map_wall(render, map);
}
