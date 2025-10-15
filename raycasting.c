/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heljary <heljary@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 10:43:09 by heljary           #+#    #+#             */
/*   Updated: 2025/10/15 11:04:48 by heljary          ###   ########.fr       */
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
	float ray_x, ray_y, dirRay_x, dirRay_y, step, distance;
	int map_x, map_y;

	ray_x = game->player.x;
	ray_y = game->player.y;
	dirRay_x = cosf(ray_angle);
	dirRay_y = sinf(ray_angle);
	step = 0.01f;
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

	int column, y;
	float ray_angle, distance, perp_distance, start_y;
	float dist_proj = (SCREEN_WIDTH / 2.0f) / tanf(game->player.fov / 2.0f);

	column = 0;
	while (column < SCREEN_WIDTH)
	{
		ray_angle = game->player.angle - (game->player.fov / 2.0f)
			+ (float)column * (game->player.fov / (float)SCREEN_WIDTH);
		distance = get_ray_distance(game, ray_angle);
		perp_distance = distance * cosf(ray_angle - game->player.angle);
		if (perp_distance <= 0.0001f)
			perp_distance = 0.0001f;
		wall_height = (1.0f / perp_distance) * dist_proj;
		start_y = (SCREEN_HEIGHT / 2.0f) - (wall_height / 2.0f);
		end_y = (SCREEN_HEIGHT / 2.0f) + (wall_height / 2.0f);
		y = (int)start_y;
		if (y < 0)
			y = 0;
		if (end_y > SCREEN_HEIGHT)
			end_y = SCREEN_HEIGHT;
		while ((float)y < end_y)
		{
			my_mlx_pixel_put(game->img, column, y, WALL_COLOR);
			y++;
		}
		column++;
	}
}
