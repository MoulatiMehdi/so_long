/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_soldier.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 21:02:38 by mmoulati          #+#    #+#             */
/*   Updated: 2025/03/08 06:50:05 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_soldier_walk(t_render *render, t_enemy *enemy)
{
	t_point		p;
	t_sprite	*sprite;

	sprite = render->sprites[SPRITE_SOLDIER];
	sprite->x = sprite->frame_width * (enemy->frame_on_loop / sprite->loop);
	sprite->y = sprite->frame_height * enemy->way;
	p.y = enemy->y - render->camera.y;
	p.x = enemy->x - render->camera.x;
	ft_render_sprite(render, sprite, &p);
	enemy->frame_on_loop = (enemy->frame_on_loop + 1) % (sprite->loop
			* (sprite->col - 4));
}

void	ft_soldier_look(t_render *render, t_enemy *enemy)
{
	t_point		p;
	t_sprite	*sprite;

	sprite = render->sprites[SPRITE_SOLDIER];
	sprite->x = sprite->frame_width * (4 + enemy->frame_on_loop / (sprite->loop
				* 4));
	sprite->y = sprite->frame_height * enemy->way;
	p.y = enemy->y - render->camera.y;
	p.x = enemy->x - render->camera.x;
	ft_render_sprite(render, sprite, &p);
	enemy->frame_on_loop = (enemy->frame_on_loop + 1) % (sprite->loop * 8);
	if (enemy->frame_on_loop == 0)
		enemy->is_fixed = false;
}

void	ft_soldier_dying(t_render *render, t_enemy *enemy)
{
	t_point		p;
	t_sprite	*sprite;
	t_sprite	*sprite_smoke;

	sprite = render->sprites[SPRITE_SOLDIER];
	sprite_smoke = render->sprites[SPRITE_SMOKE];
	sprite->x = 0;
	sprite->y = sprite->frame_height * enemy->way;
	p.y = enemy->y - render->camera.y;
	p.x = enemy->x - render->camera.x;
	ft_render_sprite(render, sprite, &p);
	sprite_smoke->x = sprite_smoke->frame_width * (enemy->frame_on_loop
			/ sprite_smoke->loop);
	sprite_smoke->y = 0;
	ft_render_sprite(render, sprite_smoke, &p);
	enemy->frame_on_loop = (enemy->frame_on_loop + 1) % (sprite->loop * 8);
	if (enemy->frame_on_loop == 0)
	{
		enemy->is_fixed = false;
		enemy->is_dead = true;
	}
}
