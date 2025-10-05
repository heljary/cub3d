/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haitaabe <haitaabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 09:45:11 by haitaabe          #+#    #+#             */
/*   Updated: 2025/10/05 09:45:12 by haitaabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H
#include "minilibx/mlx.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
# define Pi 3.14159265358979323846
#define SCREEN_WIDTH 1800
#define SCREEN_HEIGHT 800
#define CEILING_COLOR 0x000000
#define FLOOR_COLOR 0x8B4513
#define WALL_COLOR 0xFFFFFF
#define Dog_to_Rad(x) ((x) * Pi / 180.0)

#define Key_A  97
#define Key_D  100
#define Key_S  115
#define Key_W  119

#define Key_ESC  65307

#define Key_L  65361
#define Key_UP 65362
#define Key_R  65363
#define Key_DW 65364

typedef struct s_player {
    float x, y;
    float dir_x, dir_y;
    float fov;
    float speed;
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
    char **map;
    t_player player;
    t_img *img;
    int map_width, map_height;
} t_game;


int close_window(t_game *game);
void    draw_tile(t_game *game,int map_x, int map_y, unsigned int color);
void draw_minimap(t_game *game);
void draw_player(t_game *game);
int key_hook(int key,void *pram);
void send_more_rays(t_game *game);
void draw_background(t_game *game);
void wall_height_projection(t_game *game);
extern char *hardcoded_map[];

#endif