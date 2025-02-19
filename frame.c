#include "image.h"
#include "key.h"
#include "mlx.h"
#include "so_long.h"

t_render	*ft_render_new(void *mlx, void *window)
{
	t_render	*render;

	render = malloc(sizeof(t_render));
	if (render == NULL)
		return (NULL);
	render->window = window;
	render->mlx = mlx;
	render->curr = ft_image_new(mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	render->next = ft_image_new(mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	return (render);
}

void	ft_render_display(t_render *render)
{
	t_image	*tmp;

	if (render == NULL)
		return ;
	mlx_put_image_to_window(render->mlx, render->window, render->next->address,
		0, 0);
	tmp = render->next;
	render->next = render->curr;
	render->curr = tmp;
}

void	ft_render_clear(t_render *render)
{
	ft_image_clear(&render->curr);
	ft_image_clear(&render->next);
	free(render);
}
