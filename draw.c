/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 19:30:10 by mmoulati          #+#    #+#             */
/*   Updated: 2025/03/08 11:10:20 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"
#include "so_long.h"

void	ft_rect_draw(t_render *render, t_rect *rect)
{
	int		j;
	t_point	p;
	int		color;

	color = 0X00FF0000;
	p.x = rect->center.x - rect->width / 2;
	p.y = rect->center.y - rect->height / 2;
	j = 0;
	while (j < rect->width)
		ft_image_putpixel(render->back, p.x + j++, p.y, color);
	j = 0;
	while (j < rect->height)
	{
		ft_image_putpixel(render->back, p.x, p.y + j, color);
		ft_image_putpixel(render->back, p.x + rect->width - 1, p.y + j, color);
		j++;
	}
	j = 0;
	while (j < rect->width)
		ft_image_putpixel(render->back, p.x + j++, p.y + rect->height - 1,
			color);
}

void	draw_player_collision(t_render *render, t_player *player)
{
	t_rect	c;

	c.center.x = player->x - render->camera.x + player->origin_x;
	c.center.y = player->y - render->camera.y + player->origin_y;
	c.width = player->width;
	c.height = player->height;
	ft_rect_draw(render, &c);
}

void	draw_enemy_collision(t_render *render, t_enemy *enemy)
{
	t_rect	c;

	c.center.x = enemy->x - render->camera.x + enemy->origin_x;
	c.center.y = enemy->y - render->camera.y + enemy->origin_y;
	c.width = enemy->width;
	c.height = enemy->height;
	ft_rect_draw(render, &c);
}

void	draw_coin_collision(t_render *render, t_point p)
{
	t_rect		c;
	t_sprite	*sprite;

	sprite = render->sprites[SPRITE_RUPEE];
	c.center.x = p.x - render->camera.x + sprite->frame_width / 2;
	c.center.y = p.y - render->camera.y + sprite->frame_height / 2;
	c.width = sprite->frame_width;
	c.height = sprite->frame_height;
	ft_rect_draw(render, &c);
}

void	draw_door_collision(t_engine *engine, t_render *render)
{
	t_rect		c;
	t_sprite	*sprite;
	t_exit		*door;

	door = &engine->exit;
	sprite = render->sprites[SPRITE_EXIT];
	c.center.x = door->x - render->camera.x + sprite->frame_width;
	c.center.y = door->y - render->camera.y + sprite->frame_height;
	c.width = sprite->frame_width / 2;
	c.height = sprite->frame_height / 2;
	ft_rect_draw(render, &c);
}

void	draw_spin_collision(t_engine *engine, t_render *render)
{
	t_rect		c;
	t_player	*player;

	player = engine->player;
	ft_rect_spin(&c, player);
	c.center.x -= render->camera.x;
	c.center.y -= render->camera.y;
	ft_rect_draw(render, &c);
}

void	draw_attack_collision(t_engine *engine, t_render *render)
{
	t_rect		c;
	t_player	*player;

	player = engine->player;
	ft_rect_attack(&c, player);
	c.center.x -= render->camera.x;
	c.center.y -= render->camera.y;
	ft_rect_draw(render, &c);
}
