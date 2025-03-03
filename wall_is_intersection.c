/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_is_intersection.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 17:32:49 by mmoulati          #+#    #+#             */
/*   Updated: 2025/03/03 17:32:49 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wall.h"

bool	ft_wall_inter_isdiagonal(t_map *map, t_point *point)
{
	return (ft_wall_tonbr(map, point) == 443);
}

bool	ft_wall_inter_isantidiagonal(t_map *map, t_point *point)
{
	return (ft_wall_tonbr(map, point) == 254);
}
