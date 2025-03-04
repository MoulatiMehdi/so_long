/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoulati <mmoulati@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/03 17:32:44 by mmoulati          #+#    #+#             */
/*   Updated: 2025/03/03 21:25:13 by mmoulati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "image.h"
#include "so_long.h"

void	ft_render_sprites_init(t_render *render);

t_render	*ft_render_new(void)
{
	t_render	*render;

	render = ft_calloc(sizeof(t_render), 1);
	if (render == NULL)
		return (NULL);
	render->mlx = mlx_init();
	render->window = mlx_new_window(render->mlx, WINDOW_WIDTH, WINDOW_HEIGHT,
			WINDOW_TITLE);
	render->stop = false;
	render->back = ft_image_new(render->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	render->front = ft_image_new(render->mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	if (render->back == NULL || render->front == NULL)
	{
		ft_render_clear(&render);
		return (NULL);
	}
	ft_render_sprites_init(render);
	return (render);
}

void	ft_sprites_clear(t_sprite ***sprites)
{
	unsigned int	i;

	if (!*sprites)
		return ;
	i = 0;
	while ((*sprites)[i])
	{
		ft_image_clear(&(*sprites)[i]->image);
		free((*sprites)[i]);
		i++;
	}
	free(*sprites);
	*sprites = NULL;
}

void	ft_render_clear(t_render **render)
{
	if (*render == NULL)
		return ;
	ft_image_clear(&(*render)->back);
	ft_image_clear(&(*render)->front);
	ft_sprites_clear(&(*render)->sprites);
	mlx_destroy_window((*render)->mlx, (*render)->window);
	mlx_destroy_display((*render)->mlx);
	free((*render)->mlx);
	free(*render);
	*render = NULL;
}

bool ft_camera_is_inview(t_point * camera,t_point * p)
{
    if(camera->x > p->x && camera ->x + WINDOW_WIDTH < p->x)
        return false;
    if(camera->y > p->y && camera ->y + WINDOW_HEIGHT < p->y)
        return false;
    return true;
}
