#ifndef CUB3D_H
#define CUB3D_H
#include "minilibx/mlx.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
# define Pi 3.14159265358979323846
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600
#define CEILING_COLOR 0x87CEEB
#define FLOOR_COLOR 0x8B4513


#define Key_A  97
#define Key_D  100
#define Key_S  115
#define Key_W  119

#define Key_L  65361
#define Key_UP 65362
#define Key_R  65363
#define Key_DW 65364



#define MAP_WIDTH 15
#define MAP_HEIGHT 28
#define MAX_DISTANCE_SQ 400.0f // 20.0f * 20.0f
#define MIN_DISTANCE 0.1f

typedef struct s_player {
    float x, y;           // Position f map
    float dir_x, dir_y;   // Direction vector
    float plane_x, plane_y; // Camera plane (FOV)
    float fov;
    float speed;          // Movement speed
    float angle;
} t_player;


                                        
typedef struct s_img {
    void *img;
    char *addr;
    int bpp, line_len, endian;
} t_img;

typedef struct s_game {
    void *mlx;
    int size_pxl;
    void *win;
    char **map;           // 2D map array
    t_player player;
    t_img *img;
    int map_width, map_height;
} t_game;

// // Add these structures and functions to cub3d.h

// typedef struct s_parse_info {
//     char    *north_texture;
//     char    *south_texture;
//     char    *west_texture;
//     char    *east_texture;
//     int     floor_r, floor_g, floor_b;
//     int     ceiling_r, ceiling_g, ceiling_b;
//     char    **map;
//     int     map_width;
//     int     map_height;
//     int     player_x;
//     int     player_y;
//     char    player_dir;
// } t_parse_info;

// Function prototypes
int game_loop(t_game *game);
int key_press(int keycode, t_game *game);
int close_window(t_game *game);
void cleanup_hardcoded_game(t_game *game);
void init_hardcoded_game(t_game *game);









void    draw_tile(t_game *game,int map_x, int map_y, unsigned int color);
void draw_minimap(t_game *game);
void draw_player(t_game *game);
int key_hook(int key,void *pram);
void send_more_rays(t_game *game);
extern char *hardcoded_map[];





#endif