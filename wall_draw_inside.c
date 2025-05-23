/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_draw_inside.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 17:32:45 by mmoulati          #+#    #+#             */
/*   Updated: 2025/03/03 17:32:45 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_map_wall_left_top(t_render *render, t_point *point)
{
	t_sprite	*sprite;

	sprite = render->sprites[SPRITE_WALL];
	sprite->x = 0;
	sprite->y = 0;
	ft_render_sprite(render, sprite, point);
}

void	ft_map_wall_right_top(t_render *render, t_point *point)
{
	t_sprite	*sprite;

	sprite = render->sprites[SPRITE_WALL];
	sprite->x = sprite->frame_width * 2;
	sprite->y = 0;
	ft_render_sprite(render, sprite, point);
}

void	ft_map_wall_right_bottom(t_render *render, t_point *point)
{
	t_sprite	*sprite;

	sprite = render->sprites[SPRITE_WALL];
	sprite->x = sprite->frame_width * 3;
	sprite->y = 0;
	ft_render_sprite(render, sprite, point);
}

void	ft_map_wall_left_bottom(t_render *render, t_point *point)
{
	t_sprite	*sprite;

	sprite = render->sprites[SPRITE_WALL];
	sprite->x = sprite->frame_width * 1;
	sprite->y = 0;
	ft_render_sprite(render, sprite, point);
}
