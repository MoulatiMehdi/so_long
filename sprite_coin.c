/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rupee_animation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 17:31:06 by mmoulati          #+#    #+#             */
/*   Updated: 2025/03/04 17:31:06 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_render_coins(t_render *render, t_engine *engine)
{
	t_sprite	*sprite;
	t_list		*head;
	t_coin		*coin;
	t_point		point;
	static int	frame = 0;

	sprite = render->sprites[SPRITE_RUPEE];
	sprite->x = (frame / sprite->loop) * sprite->frame_width;
	head = engine->coins;
	while (head)
	{
		coin = head->content;
		point.x = coin->x;
		point.y = coin->y;
		if (ft_camera_is_inview(&render->camera, &point))
		{
			sprite->y = sprite->frame_height * (coin->type % sprite->row);
			draw_coin_collision(render, point);
			point.x -= render->camera.x;
			point.y -= render->camera.y;
			ft_render_sprite(render, sprite, &point);
		}
		head = head->next;
	}
	frame = (frame + 1) % (sprite->col * sprite->loop);
}
