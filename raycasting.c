#include "cub3d.h"

char *hardcoded_map[] = {
    "111111111111111111111111111",
    "110000000000000000000000001",
    "10000000000000000P000000001",
    "100000000000000000000000001",
    "100000000000000000000000001",
    "100000000000000000000000001",
    "100000000000100000000000001",
    "100000000000100000000000001",
    "100000000000100000000000001",
    "100000000000000000000000001",
    "100000000000000000000000001",
    "100000000000000000000000001",
    "100000000000000000000000001",
    "100000000000000000000000001",
    "111111111111111111111111111",
    NULL
};


void send_one_ray_to_wall(t_game *game);



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

void draw_tile(t_game *game,int map_x, int map_y, unsigned int color)
{
    int start_x = map_x * game->size_pxl;
    int start_y = map_y * game->size_pxl;
    int end_x = start_x + game->size_pxl;
    int end_y = start_y + game->size_pxl;

    for (int i = start_y; i < end_y; i++)
    {
        for (int j = start_x; j < end_x; j++)
        {
            my_mlx_pixel_put(game->img, j, i, color);
        }
    }
}


void draw_minimap(t_game *game)
{
    int y = 0;
    while(hardcoded_map[y])
    {
        int x = 0;
        while (hardcoded_map[y][x])
        {
            if(hardcoded_map[y][x] == '1')
                draw_tile(game,x,y,0xFFFFFF);
            if(hardcoded_map[y][x] == '0')
                draw_tile(game,x,y,0x000000);
            x++;
        }
        y++;
    }
}

void draw_player(t_game *game)
{
    int tile_size = game->size_pxl;
    int px = (int)(game->player.x * tile_size + tile_size / 2);
    int py = (int)(game->player.y * tile_size + tile_size / 2);
    int player_size = tile_size / 2;

    for (int y = py; y < py + player_size; y++)
        for (int x = px; x < px + player_size; x++)
            my_mlx_pixel_put(game->img, x, y, 0x00FF00);
}


int key_hook(int key, void *pram)
{
    t_game *game = (t_game*)pram;
    mlx_clear_window(game->mlx, game->win);

    float new_x = game->player.x;
    float new_y = game->player.y;
    float speed = 0.5;
    float rot_speed = 0.1;

    if (key == Key_L)
        game->player.angle -= rot_speed;
    if (key == Key_R)
        game->player.angle += rot_speed;

    if (game->player.angle >= 2 * Pi)
        game->player.angle -= 2 * Pi;
    if (game->player.angle < 0)
        game->player.angle += 2 * Pi;

    if (key == Key_A) { // left
        new_x = game->player.x - sin(game->player.angle) * speed;
        new_y = game->player.y + cos(game->player.angle) * speed;
    }
    if (key == Key_D) { // right
        new_x = game->player.x + sin(game->player.angle) * speed;
        new_y = game->player.y - cos(game->player.angle) * speed;
    }
    if (key == Key_S || key == Key_DW) { // backward
        new_x = game->player.x - cos(game->player.angle) * speed;
        new_y = game->player.y - sin(game->player.angle) * speed;
    }
    if (key == Key_W || key == Key_UP) { // forward
        new_x = game->player.x + cos(game->player.angle) * speed;
        new_y = game->player.y + sin(game->player.angle) * speed;
    }
    game->player.x = new_x;
    game->player.y = new_y;


    // redraw
    draw_minimap(game);
    draw_player(game);
    send_one_ray_to_wall(game);
    mlx_put_image_to_window(game->mlx, game->win, game->img->img, 0, 0);

    return 0;
}



void send_one_ray_to_wall(t_game *game)
{
    game->player.dir_x = cos(game->player.angle);
    game->player.dir_y = sin(game->player.angle);

    float ray_x = game->player.x + 0.75;
    float ray_y = game->player.y + 0.75;

    float step = 0.01;

    while(hardcoded_map[(int)ray_y][(int)ray_x] != '1')
    {
        ray_x += game->player.dir_x * step;
        ray_y += game->player.dir_y * step;
        my_mlx_pixel_put(game->img,(int)(ray_x * game->size_pxl),(int)(ray_y * game->size_pxl),0xFF0000);
    }
}
