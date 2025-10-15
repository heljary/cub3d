/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heljary <heljary@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 08:40:42 by heljary           #+#    #+#             */
/*   Updated: 2025/10/15 10:38:21 by heljary          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "minilibx/mlx.h"
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# define PI 3.14159265358979323846
# define SCREEN_WIDTH 1070
# define SCREEN_HEIGHT 460
# define CEILING_COLOR 0x000000
# define FLOOR_COLOR 0x8B4513
# define WALL_COLOR 0xFFFFFF
# define KEY_A 97
# define KEY_D 100
# define KEY_S 115
# define KEY_W 119
# define KEY_ESC 65307
# define KEY_L 65361
# define KEY_UP 65362
# define KEY_R 65363
# define KEY_DW 65364

typedef struct s_player
{
	float		x;
	float		y;
	float		dir_x;
	float		dir_y;
	float		fov;
	float		speed;
	float		angle;
}				t_player;
typedef struct s_img
{
	void		*img;
	char		*addr;
	int			bpp;
	int			line_len;
	int			endian;
}				t_img;
typedef struct s_map
{
	char		**map;
	int			width;
	int			height;
	float		player_x;
	float		player_y;
	char		player_dir;
}				t_map;
typedef struct s_game
{
	void		*mlx;
	int			size_pxl;
	void		*win;
	t_player	player;
	t_img		*img;
	t_map		map;
	int			map_width;
	int			map_height;
}				t_game;
void			my_mlx_pixel_put(t_img *img, int x, int y, unsigned int color);
int				close_window(t_game *game);
void			draw_tile(t_game *game, int map_x, int map_y,
					unsigned int color);
void			draw_minimap(t_game *game);
int				is_valid_pos(t_game *game, float x, float y);
void			draw_player(t_game *game);
float			calcule_distance(float ray_x, float ray_y, float px, float py);
float			get_ray_distance(t_game *game, float ray_angle);
void			draw_background(t_game *game);
void			wall_height_projection(t_game *game);
void			ft_draw(t_game *game);
void			ft_move(t_game *game, int key, float *new_x, float *new_y);
int				key_hook(int key, void *pram);
void			ft_more_ray(t_game *game, float ray_x, float ray_y);
#endif