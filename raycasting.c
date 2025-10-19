/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heljary <heljary@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 10:43:09 by heljary           #+#    #+#             */
/*   Updated: 2025/10/19 10:32:28 by heljary          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
float	calculate_distance(float x1, float y1, float x2, float y2)
{
	float dx = x2 - x1;
	float dy = y2 - y1;
	return (sqrt(dx * dx + dy * dy));
}
float	cast_ray(t_game *game, float ray_angle)
{
	float	ray_x = game->player.x + 0.5f;
	float	ray_y = game->player.y + 0.5f;
	float	dir_x = cos(ray_angle);
	float	dir_y = sin(ray_angle);
	float	step = 0.01f;
	while (game->map.map[(int)ray_y][(int)ray_x] != '1')
	{
		ray_x += dir_x * step;
		ray_y += dir_y * step;
		my_mlx_pixel_put(game->img,ray_x,ray_y,0xFF0000);
	}
	return (calculate_distance(game->player.x + 0.5f, game->player.y + 0.5f, 
								ray_x, ray_y));
}
void	draw_wall_column(t_game *game, int column, float wall_height)
{
	int		start_y;
	int		end_y;
	int		y;
	start_y = (SCREEN_HEIGHT / 2) - (wall_height / 2);
	end_y = (SCREEN_HEIGHT / 2) + (wall_height / 2);
	if (start_y < 0)
		start_y = 0;
	if (end_y > SCREEN_HEIGHT)
		end_y = SCREEN_HEIGHT;
	y = start_y;
	while (y < end_y)
	{
		my_mlx_pixel_put(game->img, column, y, WALL_COLOR);
		y++;
	}
}
float	calculate_wall_height(t_game *game, float corrected_distance)
{
	float	projection_distance;
	if (corrected_distance < 0.01f)
		corrected_distance = 0.01f;

	projection_distance = (SCREEN_WIDTH / 2.0f) / tan(game->player.fov / 2.0f);
	return ((1.0f / corrected_distance) * projection_distance);
}
void	render_walls(t_game *game)
{
	float	ray_angle;
	float	angle_step;
	float	distance;
	float	corrected_distance;
	float	wall_height;
	int		column;
	ray_angle = game->player.angle - (game->player.fov / 2.0f);
	angle_step = game->player.fov / SCREEN_WIDTH;
	column = 0;
	while (column < SCREEN_WIDTH)
	{
		distance = cast_ray(game, ray_angle);
		corrected_distance = distance * cos(ray_angle - game->player.angle);
		wall_height = calculate_wall_height(game, corrected_distance);
		draw_wall_column(game, column, wall_height);
		column++;
		ray_angle += angle_step;
	}
}
