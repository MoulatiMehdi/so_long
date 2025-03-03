#include "so_long.h"
#include "wall.h"

bool	ft_wall_isroof(t_map *map, t_point *point)
{
	return (ft_wall_tonbr(map, point) == 511);
}

bool	ft_wall_isleft_top(t_map *map, t_point *point)
{
	return (ft_wall_tonbr(map, point) == 510);
}

bool	ft_wall_isright_top(t_map *map, t_point *point)
{
	return (ft_wall_tonbr(map, point) == 447);
}

bool	ft_wall_isright_bottom(t_map *map, t_point *point)
{
	return (ft_wall_tonbr(map, point) == 255);
}

bool	ft_wall_isleft_bottom(t_map *map, t_point *point)
{
	return (ft_wall_tonbr(map, point) == 507);
}
