#include "cub3d.h"
int main(void)
{
    t_game *game;
    t_img *img;

    game = malloc(sizeof(t_game));
    img = malloc(sizeof(t_img));
    if (!game || !img)
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
    img->img = mlx_new_image(game->mlx,SCREEN_WIDTH,SCREEN_HEIGHT);
    img->addr = mlx_get_data_addr(img->img, &img->bpp, &img->line_len, &img->endian);
    draw_minimap(game,img);
    draw_player(game,img);
    mlx_put_image_to_window(game->mlx,game->win,img->img,0,0);
    mlx_hook(game->win, 17, 1L<<17, close_window, &game);
    mlx_loop(game->mlx);
    
    return (0);
}