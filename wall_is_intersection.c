#include "wall.h"

bool	ft_wall_inter_isdiagonal(t_map *map, t_point *point)
{
	return (ft_wall_tonbr(map, point) == 443);
}

bool	ft_wall_inter_isantidiagonal(t_map *map, t_point *point)
{
	return (ft_wall_tonbr(map, point) == 254);
}
