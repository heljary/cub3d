/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haitaabe <haitaabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 12:08:11 by haitaabe          #+#    #+#             */
/*   Updated: 2025/10/14 09:08:06 by haitaabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

float calcule_distance(float ray_x,float ray_y,float px, float py)
{
    float dis_x = ray_x - px;
    float dis_y = ray_y - py;
    float distance = sqrt(pow(dis_x,2) + pow(dis_y,2));
    return distance;
}

float get_ray_distance(t_game *game, float ray_angle)
{
    float ray_x = game->player.x + 0.5;
    float ray_y = game->player.y + 0.5;
    float dir_x = cos(ray_angle);
    float dir_y = sin(ray_angle);
    float step = 0.01;
    while (1)
    {
        int map_x = (int)ray_x;
        int map_y = (int)ray_y;
        if (map_x < 0 || map_x >= game->map.width ||
            map_y < 0 || map_y >= game->map.height)
            break;
        if (game->map.map[map_y][map_x] == '1')
            break;
        ray_x += dir_x * step;
        ray_y += dir_y * step;
        my_mlx_pixel_put(game->img,
                         (int)(ray_x * game->size_pxl),
                         (int)(ray_y * game->size_pxl),
                         0xE52020);
    }
    float distance = calcule_distance(ray_x, ray_y, game->player.x, game->player.y);
    return distance;
}


void wall_height_projection(t_game *game)
{
    int column = 0;
    while(column < SCREEN_WIDTH -1)
    {
        float ray_angle = game->player.angle - (game->player.fov/2) + (float)column * (game->player.fov / SCREEN_WIDTH);
        float distance = get_ray_distance(game ,ray_angle);
        float fish_eye_distance = distance * cos(ray_angle - game->player.angle);
        if (fish_eye_distance < 0)
            fish_eye_distance = 0.05f;
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
