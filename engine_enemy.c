/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine_enemy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 23:37:01 by mmoulati          #+#    #+#             */
/*   Updated: 2025/03/06 23:56:44 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_enemy_init(t_enemy *enemy)
{
	enemy->y = 3 * 64;
	enemy->x = 2 * 64;
	enemy->way = WAY_DOWN;
	enemy->is_dead = false;
	enemy->frame_on_loop = 0;
	enemy->state = STATE_WALK;
	enemy->speed = 1;
	enemy->origin_y = 52;
	enemy->origin_x = 32;
	enemy->width = 24;
	enemy->height = 16;
	enemy->is_fixed = false;
}
