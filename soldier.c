/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   soldier.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/07 17:10:53 by mmoulati          #+#    #+#             */
/*   Updated: 2025/03/07 17:10:54 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_soldier_state_set(t_enemy *enemy, t_state state)
{
	if (enemy->is_dead || enemy->state == STATE_DYING)
		return ;
	if (enemy->is_fixed && state != STATE_DYING)
		return ;
	if (enemy->state == state)
		return ;
	enemy->state = state;
	enemy->frame_on_loop = 0;
	enemy->is_fixed = false;
}

void	ft_way_init(int *dx, int *dy, t_way way)
{
	*dx = 0;
	*dy = 0;
	if (way == WAY_DOWN)
		*dy = 1;
	else if (way == WAY_UP)
		*dy = -1;
	else if (way == WAY_RIGHT)
		*dx = 1;
	else if (way == WAY_LEFT)
		*dx = -1;
}
