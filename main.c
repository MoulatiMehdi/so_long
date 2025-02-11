/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 20:08:36 by mmoulati          #+#    #+#             */
/*   Updated: 2025/02/11 23:14:42 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "so_long.h"
#include <stdio.h>

void	ft_map_print(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		printf("'%s'\n", map[i]);
		i++;
	}
}
int	main(int argc, char *argv[])
{
	char	**mtrx;

	if (argc < 2)
		return (0);
	mtrx = ft_map_read(argv[1]);
	ft_map_print(mtrx);
	ft_map_valid(&mtrx);
	ft_split_free(&mtrx);
	return (EXIT_SUCCESS);
}
