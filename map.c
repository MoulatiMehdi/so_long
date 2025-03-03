#include "libft/libft.h"
#include "so_long.h"

t_map	*ft_map_new(char **array)
{
	t_map	*map;

	if (!array)
		return (NULL);
	map = malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	map->data = array;
	map->width = ft_strlen(array[0]);
	map->height = 0;
	while (array[map->height])
		map->height++;
	return (map);
}

void	ft_map_destroy(t_map **map)
{
	if (map == NULL || *map == NULL)
		return ;
	ft_split_free(&(*map)->data);
	free(*map);
	*map = NULL;
}
