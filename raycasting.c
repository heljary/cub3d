#include "cub3d.h"


char *hardcoded_map[] = {
    "1111111111111111111111111",
    "1000000000110000000000001",
    "1011000001110000000000001",
    "1001000000000000000000001",
    "1111111111000001110000001",
    "1000000000000001110111111",
    "1111011111111101110000001",
    "1111011111111101110101001",
    "1100000011010101110000001",
    "1000000000000001100000001",
    "1000000000000001101010001",
    "1100000111010101111101111",
    "1111011111101010101110001",
    "1111111111111111111111111",
    NULL
};

void my_mlx_pixel_put(t_img *img,int x,int y,unsigned int color)
{
    if (x < 0 || y < 0)
        return;
    int offset = y * img->line_len + x * (img->bpp/8);
    *(unsigned int*)(img->addr + offset) = color;

}

int close_window(t_game *game)
{
    mlx_destroy_window(game->mlx, game->win);
    exit(0);
    return (0);
}

void draw_tile(t_game *game, t_img *img, int map_x, int map_y, unsigned int color)
{
    int start_x = map_x * game->size_pxl;
    int start_y = map_y * game->size_pxl;
    int end_x = start_x + game->size_pxl;
    int end_y = start_y + game->size_pxl;

    for (int i = start_y; i < end_y; i++)
    {
        for (int j = start_x; j < end_x; j++)
        {
            my_mlx_pixel_put(img, j, i, color);
        }
    }
}


void draw_minimap(t_game *game,t_img *img)
{
    int y = 0;
    while(hardcoded_map[y])
    {
        int x = 0;
        while (hardcoded_map[y][x])
        {
            if(hardcoded_map[y][x] == '1')
                draw_tile(game,img,x,y,0x00FF00);
            else
                draw_tile(game,img,x,y,0x000000);
            x++;
        }
        y++;
    }
}

void draw_player(t_game *game, t_img *img)
{
    int px;
    int py;
    px = game->player.x * game->size_pxl;
    py = game->player.y * game->size_pxl;

    int j = 0;
    while(j < game->size_pxl)
    {
        int i = 0;
        while (i < game->size_pxl)
        {
            my_mlx_pixel_put(img,px+i,py+j,0xFFFFFF);
            i++;
        }
        j++;
    }
}




float cast_single_ray(t_game *game, t_img *img, float rayDirX, float rayDirY)
{
    int mapx = (int)game->player.x;
    int mapy = (int)game->player.y;
    
}