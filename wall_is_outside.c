#include "wall.h"

bool	ft_wall_outside_isleft_top(t_map *map, t_point *point)
{
	static int	arr[] = {27, 31, 59, 91, 95, 123, 155, 159, 187, 283, 287, 315,
			347, 351, 379, 411, 415};
	int			test;
	size_t		k;

	test = ft_wall_tonbr(map, point);
	k = 0;
	while (k < sizeof(arr) / sizeof(arr[0]))
	{
		if (arr[k] == test)
			return (true);
		k++;
	}
	return (false);
}

bool	ft_wall_outside_isright_top(t_map *map, t_point *point)
{
	static int	arr[] = {216, 217, 218, 220, 221, 222, 248, 249, 250, 252, 253,
			472, 473, 474, 476, 477, 478};
	int			test;
	size_t		k;

	test = ft_wall_tonbr(map, point);
	k = 0;
	while (k < sizeof(arr) / sizeof(arr[0]))
	{
		if (arr[k] == test)
			return (true);
		k++;
	}
	return (false);
}

bool	ft_wall_outside_isright_bottom(t_map *map, t_point *point)
{
	static int	arr[] = {432, 433, 434, 435, 436, 437, 440, 441, 442, 444, 445,
			496, 497, 498, 499, 500, 501};
	int			test;
	size_t		k;

	test = ft_wall_tonbr(map, point);
	k = 0;
	while (k < sizeof(arr) / sizeof(arr[0]))
	{
		if (arr[k] == test)
			return (true);
		k++;
	}
	return (false);
}

bool	ft_wall_outside_isleft_bottom(t_map *map, t_point *point)
{
	static int	arr[] = {54, 55, 62, 118, 119, 126, 182, 183, 190, 246, 247,
			310, 311, 318, 374, 375, 382};
	int			test;
	size_t		k;

	test = ft_wall_tonbr(map, point);
	k = 0;
	while (k < sizeof(arr) / sizeof(arr[0]))
	{
		if (arr[k] == test)
			return (true);
		k++;
	}
	return (false);
}
