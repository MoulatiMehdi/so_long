/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_animate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 17:32:33 by mmoulati          #+#    #+#             */
/*   Updated: 2025/03/03 17:32:33 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_number_render(t_render *render, t_point *point, int nbr, int digits)
{
	int			i;
	t_sprite	*sprite;

	sprite = render->sprites[SPRITE_DIGITS];
	sprite->y = 0;
	i = 0;
	while (i < digits)
	{
		sprite->x = (nbr % 10) * sprite->frame_width;
		ft_render_sprite(render, sprite, point);
		point->x -= sprite->frame_width;
		nbr /= 10;
		i++;
	}
}

void	ft_render_coins_counter(t_render *render, t_engine *engine)
{
	t_sprite	*sprite;
	t_point		point;
	int			coins;

	sprite = render->sprites[SPRITE_COIN];
	point.x = PLAYER_STATUS_X;
	point.y = 32;
	sprite->x = 0;
	sprite->y = 0;
	ft_render_sprite(render, sprite, &point);
	point.y += sprite->frame_height + 8;
	point.x += sprite->frame_width;
	coins = engine->player->coins;
	if (coins > 999)
		coins = 999;
	ft_number_render(render, &point, coins, 3);
}

void	ft_render_moves_counter(t_render *render, int moves)
{
	t_sprite	*sprite;
	t_point		point;

	sprite = render->sprites[SPRITE_CAPE];
	point.x = PLAYER_STATUS_X + 6 * 16;
	point.y = 32;
	sprite->x = 0;
	sprite->y = 0;
	ft_render_sprite(render, sprite, &point);
	point.y += sprite->frame_height + 8;
	point.x += sprite->frame_width * 3;
	if (moves > 9999999)
		moves = 9999999;
	ft_number_render(render, &point, moves, 7);
}

void	ft_render_hearts_counter(t_render *render, t_engine *engine)
{
	t_sprite	*sprite;
	t_point		point;
	int			heart;
	int			i;

	sprite = render->sprites[SPRITE_HEARTS];
	heart = engine->player->hearts;
	point.x = WINDOW_WIDTH - sprite->frame_width * (PLAYER_HEARTS_TOTAL + 1)
		- 48;
	point.y = 48;
	sprite->y = 0;
	i = 0;
	while (i < PLAYER_HEARTS_TOTAL)
	{
		sprite->x = sprite->frame_width * (2 * (heart <= 0));
		ft_render_sprite(render, sprite, &point);
		point.x += sprite->frame_width;
		heart--;
		i++;
	}
}

void	ft_render_keys(t_render *render, t_engine *engine)
{
	int			i;
	t_sprite	*sprite;
	t_point		o_dest;

	sprite = render->sprites[SPRITE_DEBUG];
	sprite->x = 0;
	sprite->y = 0;
	o_dest.y = KEY_DEBUG_Y;
	o_dest.x = KEY_DEBUG_X;
	i = 0;
	while (KEY_TRACK[i])
	{
		if (engine->keys[(int)KEY_TRACK[i]] == (char)1)
			ft_render_sprite(render, sprite, &o_dest);
		o_dest.x += sprite->frame_width;
		sprite->x += sprite->frame_width;
		i++;
	}
	if (engine->paused)
		ft_render_sprite(render, sprite, &o_dest);
}
