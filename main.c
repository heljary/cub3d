#include "cub3d.h"
int main(void)
{
    t_game *game;

    game = malloc(sizeof(t_game));
    game->img = malloc(sizeof(t_img));
    if (!game || !game->img)
        return 1;    
    game->mlx = mlx_init();
    if (!game->mlx)
    {
        printf("Error: MLX initialization failed\n");
        return (1);
    }
    
    game->win = mlx_new_window(game->mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "Cub3D");
    if (!game->win)
    {
        printf("Error: Window creation failed\n");
        return (1);
    }
    game->size_pxl = 30;
    game->player.angle = 0;
    game->player.dir_x = cos(game->player.angle);
    game->player.dir_y = sin(game->player.angle);
    game->img->img = mlx_new_image(game->mlx,SCREEN_WIDTH,SCREEN_HEIGHT);
    game->img->addr = mlx_get_data_addr(game->img->img, &game->img->bpp, &game->img->line_len, &game->img->endian);
    game->player.x = 5.0;
    game->player.y = 5.0;
    draw_minimap(game);
    draw_player(game);
    mlx_put_image_to_window(game->mlx,game->win,game->img->img,0,0);
    mlx_key_hook(game->win,key_hook,game);
    mlx_hook(game->win, 17, 1L<<17, close_window,game);
    mlx_loop(game->mlx);
    return (0);
}