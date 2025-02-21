#include "image.h"
#include "key.h"
#include "mlx.h"
#include "so_long.h"



void ft_render_sprites(t_render* render)
{
    render->sprites = malloc(sizeof(t_sprite*) * (SPRITE_TOTAL + 1));
   if(render->sprites == NULL)
        return ;
    render->sprites[SPRITE_SPINNING] = ft_sprite_new(render->mlx,"./textures/xpm/link.spinning.xpm",22,4);
    render->sprites[SPRITE_LOADING] = ft_sprite_new(render->mlx,"./textures/xpm/link.loading.xpm",6,4);
    render->sprites[SPRITE_VICTORY] = ft_sprite_new(render->mlx,"./textures/xpm/link.victory.xpm",18,1);
    render->sprites[SPRITE_WALKING] = ft_sprite_new(render->mlx,"./textures/xpm/link.walking.xpm",8,4);
    render->sprites[SPRITE_ATTACKING] = ft_sprite_new(render->mlx,"./textures/xpm/link.attack.xpm",12,4);
    render->sprites[SPRITE_DYING] = ft_sprite_new(render->mlx,"./textures/xpm/link.dying.xpm",10,1);
    render->sprites[SPRITE_HURT] = ft_sprite_new(render->mlx,"./textures/xpm/link.hurt.xpm",1,1);
    render->sprites[SPRITE_IDLE] = ft_sprite_new(render->mlx,"./textures/xpm/link.idle.xpm",1,4);

    render->sprites[SPRITE_DEBUG] = ft_sprite_new(render->mlx,"./textures/xpm/debug.xpm",9,1);
    render->sprites[SPRITE_COIN] = ft_sprite_new(render->mlx,"./textures/xpm/coin.xpm",1,1);
    render->sprites[SPRITE_DIGITS] = ft_sprite_new(render->mlx,"./textures/xpm/digits.xpm",10,2);
    render->sprites[SPRITE_CAPE] = ft_sprite_new(render->mlx,"./textures/xpm/cape.xpm",2,1);
    render->sprites[SPRITE_HEARTS] = ft_sprite_new(render->mlx,"./textures/xpm/hearts.xpm",3,1);
    render->sprites[SPRITE_TOTAL] = NULL;
}

t_render	*ft_render_new(void *mlx, void *window)
{
	t_render	*render;

	render = malloc(sizeof(t_render));
	if (render == NULL)
		return (NULL);
	render->window = window;
	render->mlx = mlx;
	render->back = ft_image_new(mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	render->front = ft_image_new(mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
	ft_render_sprites(render);
    return (render);
}


void	ft_render_display(t_render *render)
{
	t_image	*tmp;

	if (render == NULL)
		return ;
    mlx_clear_window(render->mlx, render->window);
	mlx_put_image_to_window(render->mlx, render->window, render->back->address,0, 0);
	tmp = render->front;
	render->front = render->back;
	render->back = tmp;
}

void	ft_render_clear(t_render *render)
{
	ft_image_clear(&render->back);
	ft_image_clear(&render->front);
	free(render);
}
