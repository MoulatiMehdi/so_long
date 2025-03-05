/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   engine.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 17:32:17 by mmoulati          #+#    #+#             */
/*   Updated: 2025/03/03 17:32:17 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "so_long.h"

void	ft_engine_init(t_engine *engine)
{
	engine->map = NULL;
	engine->player = ft_player_new();
	engine->paused = false;
	engine->coins = NULL;
	engine->coins_total = 0;
	ft_bzero(engine->keys, KEYS_TOTAL);
}

t_engine	*ft_engine_new(void)
{
	t_engine	*engine;

	engine = malloc(sizeof(t_engine));
	if (engine == NULL)
		return (NULL);
	ft_engine_init(engine);
	return (engine);
}

void	ft_engine_destroy(t_engine **engine)
{
	ft_player_destroy(&(*engine)->player);
	ft_map_destroy(&(*engine)->map);
	ft_lstclear(&(*engine)->coins, free);
	free(*engine);
	*engine = NULL;
}
