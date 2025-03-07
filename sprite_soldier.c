/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_soldier.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 21:02:38 by mmoulati          #+#    #+#             */
/*   Updated: 2025/03/06 23:39:36 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_soldier_walk(t_render *render, t_enemy *enemy)
{
	static int	n = 0;
	t_point		p;
	t_sprite	*sprite;

	sprite = render->sprites[SPRITE_SOLDIER];
	sprite->x = sprite->frame_width * (n / sprite->loop);
	sprite->y = sprite->frame_height * enemy->way;
	p.y = enemy->y - render->camera.y;
	p.x = enemy->x - render->camera.x;
	ft_render_sprite(render, sprite, &p);
	n = (n + 1) % (sprite->loop * (sprite->col - 2));
}

void	ft_soldier_look(t_render *render, t_enemy *enemy)
{
	static int	n = 0;
	t_point		p;
	t_sprite	*sprite;

	sprite = render->sprites[SPRITE_SOLDIER];
	sprite->x = sprite->frame_width * (4 + n / sprite->loop);
	sprite->y = sprite->frame_height * enemy->way;
	p.y = enemy->y - render->camera.y;
	p.x = enemy->x - render->camera.x;
	ft_render_sprite(render, sprite, &p);
	n = (n + 1) % (sprite->loop * 2);
}
