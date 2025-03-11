/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 20:51:23 by mmoulati          #+#    #+#             */
/*   Updated: 2025/03/08 07:59:17 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

bool	ft_camera_is_inview(t_point *camera, t_point *p)
{
	if (camera->x > p->x && camera->x + WINDOW_WIDTH < p->x)
		return (false);
	if (camera->y > p->y && camera->y + WINDOW_HEIGHT < p->y)
		return (false);
	return (true);
}

void	ft_camera_player_center(t_render *render, t_player *player,
		t_point *point)
{
	t_point	*camera;

	camera = &render->camera;
	point->x = player->x - camera->x;
	point->y = player->y - camera->y;
	if (render->camera.x > 0 && camera->x < render->map_width * 64
		- WINDOW_WIDTH)
		point->x = WINDOW_WIDTH / 2;
	if (render->camera.y > 0 && camera->y < render->map_height * 64
		- WINDOW_HEIGHT)
		point->y = WINDOW_HEIGHT / 2;
}

void	ft_camera_update(t_render *render, t_engine *engine)
{
	t_point		*camera;
	t_player	*player;
	t_point		max;

	max.x = engine->map->width * 64 - WINDOW_WIDTH;
	max.y = engine->map->height * 64 - WINDOW_HEIGHT;
	if (max.x < 0)
		max.x = (engine->map->width * 64 - WINDOW_WIDTH) / 2;
	if (max.y < 0)
		max.y = (engine->map->height * 64 - WINDOW_HEIGHT) / 2;
	player = engine->player;
	camera = &render->camera;
	camera->x = player->x - WINDOW_WIDTH / 2;
	camera->y = player->y - WINDOW_HEIGHT / 2;
	if (camera->x < 0)
		camera->x = 0;
	if (camera->y < 0)
		camera->y = 0;
	if (camera->x > max.x)
		camera->x = max.x;
	if (camera->y > max.y)
		camera->y = max.y;
}
