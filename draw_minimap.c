/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heljary <heljary@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 10:28:23 by heljary           #+#    #+#             */
/*   Updated: 2025/10/19 10:35:49 by heljary          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_tile(t_game *game, int map_x, int map_y, unsigned int color)
{
	int	start_x;
	int	start_y;
	int	end_x;
	int	end_y;

	int (i), (j);
	start_x = map_x * game->size_pxl;
	start_y = map_y * game->size_pxl;
	end_x = start_x + game->size_pxl;
	end_y = start_y + game->size_pxl;
	if (start_x >= SCREEN_WIDTH || start_y >= SCREEN_HEIGHT)
		return ;
	i = start_y;
	while (i < end_y)
	{
		j = start_x;
		while (j < end_x)
		{
			my_mlx_pixel_put(game->img, j, i, color);
			j++;
		}
		i++;
	}
}

void	draw_minimap(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (game->map.map[y])
	{
		x = 0;
		while (game->map.map[y][x])
		{
			if (game->map.map[y][x] == '1')
				draw_tile(game, x, y, 0xE67514);
			if (game->map.map[y][x] == '0')
				draw_tile(game, x, y, 0x00FF00);
			x++;
		}
		y++;
	}
}

void	draw_player(t_game *game)
{
	int	px_start;
	int	py_start;
	int	y;
	int	x;

	px_start = (int)(game->player.x * game->size_pxl);
	py_start = (int)(game->player.y * game->size_pxl);
	y = py_start;
	while (y < py_start + game->size_pxl)
	{
		x = px_start;
		while (x < px_start + game->size_pxl)
		{
			my_mlx_pixel_put(game->img, x, y, 0x27445D);
			x++;
		}
		y++;
	}
}

void	ft_one_ray(t_game *game,float start_ray_angle)
{
	float ray_x = game->player.x + 0.5;
	float ray_y = game->player.y + 0.5;
	float dir_x = cos(start_ray_angle);
	float dir_y = sin(start_ray_angle);
	float step = 0.01f;
	while(game->map.map[(int)ray_y][(int)ray_x] != '1')
	{
		ray_x += dir_x * step;
		ray_y += dir_y * step;
		my_mlx_pixel_put(game->img,(int)(ray_x * game->size_pxl),(int)(ray_y * game->size_pxl),0xFF0000);
	}
}

void	ft_more_ray(t_game *game)
{
	float s_ray_dir = game->player.angle - game->player.fov / 2;
	float e_ray_dir = game->player.angle + game->player.fov / 2;
	float step = 0.001f;
	while(s_ray_dir <= e_ray_dir)
	{
		ft_one_ray(game,s_ray_dir);
		s_ray_dir += step;
	}
}