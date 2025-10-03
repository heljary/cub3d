#include "cub3d.h"

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
                draw_tile(game,x,y,0xE67514);
            if(hardcoded_map[y][x] == '0')
                draw_tile(game,x,y,0x00FF00);
            x++;
        }
        y++;
    }
}

void draw_player(t_game *game)
{
    int px_start = (int)(game->player.x * game->size_pxl);
    int py_start = (int)(game->player.y * game->size_pxl);

    int y = py_start;
    while (y < py_start + game->size_pxl)
    {
        int x = px_start;
        while (x < px_start + game->size_pxl)
        {
            my_mlx_pixel_put(game->img, x, y, 0x27445D);
            x++;
        }
        y++;
    }
}



float calcule_distance(float ray_x,float ray_y,float px, float py)
{
    float dis_x = ray_x - px;
    float dis_y = ray_y - py;
    float distance = sqrt(pow(dis_x,2) + pow(dis_y,2));
    return distance;
}

float get_ray_distance(t_game *game,float ray_angle){
    float ray_x = game->player.x + 0.5;
    float ray_y = game->player.y + 0.5;
    game->player.dir_x = cos(ray_angle);
    game->player.dir_y = sin(ray_angle);
    float step = 0.01;
    while(hardcoded_map[(int)ray_y][(int)ray_x] != '1')
    {
        ray_x += game->player.dir_x * step;
        ray_y += game->player.dir_y * step;
        my_mlx_pixel_put(game->img,(int)(ray_x * game->size_pxl),(int)(ray_y * game->size_pxl),0xE52020);
    }
    float distance = calcule_distance(ray_x,ray_y,game->player.x,game->player.y);
    return (distance);
}

void draw_background(t_game *game)
{
    int x, y;

    y = 0;
    while (y < SCREEN_HEIGHT)
    {
        x = 0;
        while (x < SCREEN_WIDTH)
        {
            if (y < SCREEN_HEIGHT / 2)
                my_mlx_pixel_put(game->img, x, y, CEILING_COLOR);
            else
                my_mlx_pixel_put(game->img, x, y, FLOOR_COLOR);
            x++;
        }
        y++;
    }
}


void wall_height_projection(t_game *game)
{
    int column = 0;
    while(column < SCREEN_WIDTH -1)
    {
        float ray_angle = game->player.angle - (game->player.fov/2) + (float)column * (game->player.fov / SCREEN_WIDTH);
        float distance = get_ray_distance(game ,ray_angle);
        float fish_eye_distance = distance * cos(ray_angle - game->player.angle);
        float wall_height = SCREEN_HEIGHT / fish_eye_distance;
        float start_y = (SCREEN_HEIGHT/2) - (wall_height/2);
        float end_y = (SCREEN_HEIGHT/2) + (wall_height/2);
        int y = start_y;
        while (y < end_y)
        {
            my_mlx_pixel_put(game->img, column, y, WALL_COLOR);
            y++;
        }
        column++;
    }
}


void Key__A(t_game *game, float *new_x,float *new_y,float speed){
    *new_x = game->player.x - sin(game->player.angle) * speed;
    *new_y = game->player.y + cos(game->player.angle) * speed;
}


void Key__D(t_game *game, float *new_x,float *new_y,float speed){
    *new_x = game->player.x + sin(game->player.angle) * speed;
    *new_y = game->player.y - cos(game->player.angle) * speed;
}

void Key__S__DW(t_game *game, float *new_x,float *new_y,float speed){
    *new_x = game->player.x - cos(game->player.angle) * speed;
    *new_y = game->player.y - sin(game->player.angle) * speed;
}

void Key__W__UP(t_game *game, float *new_x,float *new_y,float speed){
    *new_x = game->player.x + cos(game->player.angle) * speed;
    *new_y = game->player.y + sin(game->player.angle) * speed;
}

void ft_redraw(t_game *game)
{
    draw_background(game);
    draw_minimap(game);
    draw_player(game);
    wall_height_projection(game);
}

int key_hook(int key, void *pram)
{
    t_game *game = (t_game*)pram;
    mlx_clear_window(game->mlx, game->win);
    float new_x = game->player.x;
    float new_y = game->player.y;
    float speed = 0.5;
    float rot_speed = 0.1;
    if (key == Key_ESC)
        close_window(game);
    if (key == Key_L)
        game->player.angle -= rot_speed;
    if (key == Key_R)
        game->player.angle += rot_speed;
    while (game->player.angle >= 2 * Pi)
        game->player.angle -= 2 * Pi;
    while (game->player.angle < 0)
        game->player.angle += 2 * Pi;
    if (key == Key_A)
        Key__A(game,&new_x,&new_y,speed);
    if (key == Key_D)
        Key__D(game,&new_x,&new_y,speed);
    if (key == Key_S || key == Key_DW)
        Key__S__DW(game,&new_x,&new_y,speed);
    if (key == Key_W || key == Key_UP)
        Key__W__UP(game,&new_x,&new_y,speed);
    game->player.x = new_x;
    game->player.y = new_y;
    ft_redraw(game);
    mlx_put_image_to_window(game->mlx, game->win, game->img->img, 0, 0);
    return 0;
}
