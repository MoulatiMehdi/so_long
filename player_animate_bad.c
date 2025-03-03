/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_animate_bad.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 17:32:36 by mmoulati          #+#    #+#             */
/*   Updated: 2025/03/03 17:32:36 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

#define FRAME_FADE_IN 10.0
#define FRAME_FADE_OUT 104.0

void	ft_player_hurt(t_player *player, t_render *render)
{
	t_sprite	*sprite;
	t_point		point;

	ft_player_camera_center(render, player, &point);
	sprite = render->sprites[SPRITE_LINK_HURT];
	sprite->x = 0;
	sprite->y = sprite->frame_height * player->way;
	ft_render_sprite(render, sprite, &point);
}

void	ft_player_fadein(t_player *player, t_render *render, int n)
{
	t_ellipse	ellipse;
	double		factor;

	factor = ((FRAME_FADE_IN - n) / FRAME_FADE_IN);
	if (factor < 0)
		factor = 0;
	ft_player_camera_center(render, player, &ellipse.center);
	ellipse.center.x += player->width / 2;
	ellipse.center.y += player->height * 0.60;
	ellipse.raduis_x = WINDOW_WIDTH * factor;
	ellipse.raduis_y = WINDOW_HEIGHT * factor * 3 / 4;
	if (ellipse.raduis_y == 0 || ellipse.raduis_x == 0)
		ft_image_fill(render->back, 0x00000000);
	else
		ft_image_ellipse(render->back, &ellipse, 0x00000000);
	ft_player_hurt(player, render);
}

void	ft_player_fadeout(t_image *image, int n)
{
	t_color	color;
	t_byte	red;

	red = 0XFF * ((FRAME_FADE_OUT - n + FRAME_FADE_IN + 1) / FRAME_FADE_OUT);
	color = ft_color_rgba(red, 0, 0, 0);
	ft_image_fill(image, color);
}

void	ft_render_gameover(t_render *render)
{
	t_sprite	*sprite;
	t_point		point;

	sprite = render->sprites[SPRITE_GAMEOVER];
	point.x = WINDOW_WIDTH / 2 - sprite->frame_width / 2;
	point.y = WINDOW_HEIGHT / 3 - sprite->frame_height / 2;
	ft_render_sprite(render, sprite, &point);
	render->stop = true;
}

void	ft_player_dying(t_player *player, t_render *render)
{
	static int	n = 0;
	t_sprite	*sprite;
	t_point		point;

	sprite = render->sprites[SPRITE_LINK_DYING];
	sprite->y = 0;
	ft_player_camera_center(render, player, &point);
	if (n <= FRAME_FADE_IN)
		ft_player_fadein(player, render, n++);
	else
	{
		ft_player_fadeout(render->back, n);
		sprite->x = sprite->frame_width * (player->frame_on_loop
				/ sprite->loop);
		if (player->frame_on_loop + 1 == sprite->col * sprite->loop)
			player->is_dead = true;
		if (player->is_dead)
			sprite->x = sprite->frame_width * (sprite->col - 1);
		n += player->is_dead && n <= FRAME_FADE_OUT + FRAME_FADE_IN;
		ft_render_sprite(render, sprite, &point);
	}
	if (player->is_dead && n >= FRAME_FADE_OUT + FRAME_FADE_IN)
		ft_render_gameover(render);
}
