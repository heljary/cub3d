/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heljary <heljary@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 10:43:09 by heljary           #+#    #+#             */
/*   Updated: 2025/10/09 12:21:35 by heljary          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

float	calcule_distance(float ray_x, float ray_y, float px, float py)
{
	float	dis_x;
	float	dis_y;
	float	distance;

	dis_x = ray_x - px;
	dis_y = ray_y - py;
	distance = sqrt(pow(dis_x, 2) + pow(dis_y, 2));
	return (distance);
}

void	ft_more_ray(t_game *game, float ray_x, float ray_y)
{
	my_mlx_pixel_put(game->img, (int)(ray_x * game->size_pxl), (int)(ray_y
			* game->size_pxl), 0xFF0000);
}

float	get_ray_distance(t_game *game, float ray_angle)
{
	float (ray_x), (ray_y), (dirRay_x), (dirRay_y), (step), (distance);
	int (map_x), (map_y);
	ray_x = game->player.x + 0.5;
	ray_y = game->player.y + 0.5;
	dirRay_x = cos(ray_angle);
	dirRay_y = sin(ray_angle);
	step = 0.01;
	while (1)
	{
		map_x = (int)ray_x;
		map_y = (int)ray_y;
		if (map_x < 0 || map_x >= game->map.width || map_y < 0
			|| map_y >= game->map.height)
			break ;
		if (game->map.map[map_y][map_x] == '1')
			break ;
		ray_x += dirRay_x * step;
		ray_y += dirRay_y * step;
		ft_more_ray(game, ray_x, ray_y);
	}
	distance = calcule_distance(ray_x, ray_y, game->player.x, game->player.y);
	return (distance);
}

void	wall_height_projection(t_game *game)
{
	float	end_y;
	float	wall_height;

	int (column), (y);
	float (ray_angle), (distance), (fish_eye_distance), (start_y);
	column = 0;
	while (column < SCREEN_WIDTH - 1)
	{
		ray_angle = game->player.angle - (game->player.fov / 2) + (float)column
			* (game->player.fov / SCREEN_WIDTH);
		distance = get_ray_distance(game, ray_angle);
		fish_eye_distance = distance * cos(ray_angle - game->player.angle);
		if (fish_eye_distance < 0)
			fish_eye_distance = 0.01f;
		wall_height = SCREEN_HEIGHT / fish_eye_distance;
		start_y = (SCREEN_HEIGHT / 2) - (wall_height / 2);
		end_y = (SCREEN_HEIGHT / 2) + (wall_height / 2);
		y = start_y;
		while (y < end_y)
		{
			my_mlx_pixel_put(game->img, column, y, WALL_COLOR);
			y++;
		}
		column++;
	}
}
