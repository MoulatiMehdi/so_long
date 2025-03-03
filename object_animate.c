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

void	ft_number_render(t_animation *animation, t_point *point, int nbr,
		int digits)
{
	int			i;
	t_sprite	*sprite;

	sprite = animation->render->sprites[SPRITE_DIGITS];
	sprite->y = 0;
	i = 0;
	while (i < digits)
	{
		sprite->x = (nbr % 10) * sprite->frame_width;
		ft_render_sprite(animation->render, sprite, point);
		point->x -= sprite->frame_width;
		nbr /= 10;
		i++;
	}
}

void	ft_coin_render(t_animation *animation)
{
	t_sprite	*sprite;
	t_point		point;
	int			coin;

	sprite = animation->render->sprites[SPRITE_COIN];
	point.x = PLAYER_STATUS_X;
	point.y = 32;
	sprite->x = 0;
	sprite->y = 0;
	ft_render_sprite(animation->render, sprite, &point);
	point.y += sprite->frame_height + 8;
	point.x += sprite->frame_width;
	coin = animation->engine->player->coins;
	if (coin > 999)
		coin = 999;
	ft_number_render(animation, &point, coin, 3);
}

void	ft_counter_render(t_animation *animation)
{
	t_sprite	*sprite;
	t_point		point;
	int			coin;

	sprite = animation->render->sprites[SPRITE_CAPE];
	point.x = PLAYER_STATUS_X + 6 * 16;
	point.y = 32;
	sprite->x = 0;
	sprite->y = 0;
	ft_render_sprite(animation->render, sprite, &point);
	point.y += sprite->frame_height + 8;
	point.x += sprite->frame_width * 3;
	coin = animation->engine->player->moves;
	if (coin > 9999999)
		coin = 9999999;
	ft_number_render(animation, &point, coin, 7);
}

void	ft_hearts_render(t_animation *animation)
{
	t_sprite	*sprite;
	t_point		point;
	int			heart;
	int			i;

	sprite = animation->render->sprites[SPRITE_HEARTS];
	heart = animation->engine->player->hearts;
	point.x = WINDOW_WIDTH - sprite->frame_width * (PLAYER_HEARTS_TOTAL + 1)
		- 48;
	point.y = 48;
	sprite->y = 0;
	i = 0;
	while (i < PLAYER_HEARTS_TOTAL)
	{
		sprite->x = sprite->frame_width * (2 * (heart <= 0));
		ft_render_sprite(animation->render, sprite, &point);
		point.x += sprite->frame_width;
		heart--;
		i++;
	}
}

void	ft_key_debug(t_animation *animation)
{
	int			i;
	t_render	*render;
	t_sprite	*sprite;
	t_point		o_dest;

	render = animation->render;
	sprite = render->sprites[SPRITE_DEBUG];
	sprite->x = 0;
	sprite->y = 0;
	o_dest.y = KEY_DEBUG_Y;
	o_dest.x = KEY_DEBUG_X;
	i = 0;
	while (KEY_TRACK[i])
	{
		if (animation->engine->keys[(int)KEY_TRACK[i]] == 1)
			ft_render_sprite(render, sprite, &o_dest);
		o_dest.x += sprite->frame_width;
		sprite->x += sprite->frame_width;
		i++;
	}
	if (animation->engine->paused)
		ft_render_sprite(render, sprite, &o_dest);
}
