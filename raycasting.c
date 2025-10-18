/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heljary <heljary@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 10:43:09 by heljary           #+#    #+#             */
/*   Updated: 2025/10/18 13:18:02 by heljary          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

float	calcule_distance(t_game *game,float ray_x, float ray_y)
{
	float	dis_x;
	float	dis_y;
	float	distance;

	dis_x = ray_x - game->player.x;
	dis_y = ray_y - game->player.y;
	distance = sqrt(pow(dis_x, 2) + pow(dis_y, 2));
	return (distance);
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



float	get_ray_dis(t_game *game,float start_ray_angle)
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
	float dis = calcule_distance(game, ray_x, ray_y);
	return dis;
}

void	wall_height_projection(t_game *game)
{
	float ray_angle = game->player.angle - (game->player.fov / 2.0f);
	float angle_step = game->player.fov / SCREEN_WIDTH;
	int column = 0;
	while (column < SCREEN_WIDTH)
	{
		float dist = get_ray_dis(game,ray_angle);
		float perp = dist * cos(ray_angle - game->player.angle);
		if(perp <= 0.0001f)
			perp = 0.0001f;
		
		float dis_proj_plan = (SCREEN_WIDTH / 2.0f) / tan(game->player.fov/2.0f);
		float wall_height = (1.0f / perp ) * dis_proj_plan;
		float start_y = (SCREEN_HEIGHT / 2.0f) - (wall_height / 2.0f);
		float end_y = (SCREEN_HEIGHT / 2.0f) + (wall_height / 2.0f);
		if (start_y < 0)
			start_y = 0;
		if (end_y > SCREEN_HEIGHT)
			end_y = SCREEN_HEIGHT;
		int y = (int)start_y;
		while (y < (int)end_y)
		{
			my_mlx_pixel_put(game->img, column, y, WALL_COLOR);
			y++;
		}
		column++;
		ray_angle+= angle_step;
	}
}
