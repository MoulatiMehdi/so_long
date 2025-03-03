#ifndef WALL_H

# define WALL_H

# include "so_long.h"

bool	is_valid_point(t_map *map, t_point *point);
bool	ft_wall_isroof(t_map *map, t_point *point);
int		ft_wall_tonbr(t_map *map, t_point *point);

bool	ft_wall_ismiddle_top(t_map *map, t_point *point);
bool	ft_wall_ismiddle_bottom(t_map *map, t_point *point);
bool	ft_wall_ismiddle_left(t_map *map, t_point *point);
bool	ft_wall_ismiddle_right(t_map *map, t_point *point);

bool	ft_wall_isright_top(t_map *map, t_point *point);
bool	ft_wall_isright_bottom(t_map *map, t_point *point);
bool	ft_wall_isleft_top(t_map *map, t_point *point);
bool	ft_wall_isleft_bottom(t_map *map, t_point *point);

bool	ft_wall_ismiddle_top(t_map *map, t_point *point);
bool	ft_wall_ismiddle_bottom(t_map *map, t_point *point);
bool	ft_wall_ismiddle_right(t_map *map, t_point *point);
bool	ft_wall_ismiddle_left(t_map *map, t_point *point);

bool	ft_wall_outside_isleft_top(t_map *map, t_point *point);
bool	ft_wall_outside_isright_top(t_map *map, t_point *point);
bool	ft_wall_outside_isright_bottom(t_map *map, t_point *point);
bool	ft_wall_outside_isleft_bottom(t_map *map, t_point *point);

void	ft_map_obstacle(t_render *render, t_point *point);
void	ft_map_wall_left_top(t_render *render, t_point *point);
void	ft_map_wall_right_top(t_render *render, t_point *point);
void	ft_map_outside_left_top(t_render *render, t_point *point);
void	ft_map_wall_right_bottom(t_render *render, t_point *point);
void	ft_map_outside_left_bottom(t_render *render, t_point *point);
void	ft_map_outside_right_bottom(t_render *render, t_point *point);
void	ft_map_outside_right_top(t_render *render, t_point *point);
void	ft_map_wall_left_bottom(t_render *render, t_point *point);
void	ft_map_middle_top(t_render *render, t_point *point);
void	ft_map_middle_bottom(t_render *render, t_point *point);
void	ft_map_middle_left(t_render *render, t_point *point);
void	ft_map_middle_right(t_render *render, t_point *point);
void	ft_map_floor_blue(t_render *render, t_point *point);
void	ft_map_roof(t_render *render, t_point *point);

bool	ft_wall_inter_isdiagonal(t_map *map, t_point *point);
bool	ft_wall_inter_isantidiagonal(t_map *map, t_point *point);

void	ft_map_inter_diagonal(t_render *render, t_point *point);
void	ft_map_inter_antidiagonal(t_render *render, t_point *point);
#endif
