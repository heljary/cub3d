/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heljary <heljary@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 10:28:23 by heljary           #+#    #+#             */
/*   Updated: 2025/10/08 10:31:20 by heljary          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void draw_tile(t_game *game,int map_x, int map_y, unsigned int color)
{
    int start_x = map_x * game->size_pxl;
    int start_y = map_y * game->size_pxl;
    int end_x = start_x + game->size_pxl;
    int end_y = start_y + game->size_pxl;
    if (start_x >= SCREEN_WIDTH || start_y >= SCREEN_HEIGHT)
        return;
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
    while(game->map.map[y])
    {
        int x = 0;
        while (game->map.map[y][x])
        {
            if(game->map.map[y][x] == '1')
                draw_tile(game,x,y,0xE67514);
            if(game->map.map[y][x] == '0')
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