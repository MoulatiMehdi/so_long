#include "wall.h"

bool	ft_wall_outside_isleft_top(t_map *map, t_point *point)
{
	static int	arr[] = {27, 91, 155, 283, 59, 31, 287, 95, 387, 351, 347, 123,
			415, 351, 287};
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
	static int	arr[] = {472, 248, 220, 218, 217, 476, 474, 473, 252, 250, 221,
			477, 254, 253};
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
	static int	arr[] = {432, 496, 440, 434, 433, 436, 497, 498, 500, 441, 442,
			435, 437, 501, 445};
	int			test;
	size_t		k;

	test = ft_wall_tonbr(map, point);
	k = 0;
	while (k < sizeof(arr)/sizeof(arr[0]))
	{
		if (arr[k] == test)
			return (true);
		k++;
	}
	return (false);
}

bool	ft_wall_outside_isleft_bottom(t_map *map, t_point *point)
{
	static int	arr[] = {54, 310, 182, 118, 62, 55, 119, 183, 311, 126, 190,
			318, 374, 246, 375, 382};
	int			test;
	size_t		k;

	test = ft_wall_tonbr(map, point);
	k = 0;
	while (k < sizeof(arr)/sizeof(arr[0]))
	{
		if (arr[k] == test)
			return (true);
		k++;
	}
	return (false);
}
