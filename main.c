/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 20:08:36 by mmoulati          #+#    #+#             */
/*   Updated: 2025/03/08 16:44:36 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "so_long.h"
#include <stdio.h>

void	ft_map_print(t_map *map)
{
	int	i;

	i = 0;
	while (map->data[i])
	{
		printf("'%s'\n", map->data[i]);
		i++;
	}
}

int	main(int argc, char *argv[])
{
	t_map		*mtrx;
	t_map_state	state;

	if (argc != 2)
	{
		ft_putstr_fd("Usage: ./so_long *.ber\n", 2);
		return (0);
	}
	mtrx = ft_map_new(argv[1]);
	ft_map_print(mtrx);
	state = ft_map_valid(mtrx);
	ft_map_error(&mtrx, state);
	return (EXIT_SUCCESS);
}
