/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heljary <heljary@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 10:27:19 by heljary           #+#    #+#             */
/*   Updated: 2025/10/08 10:43:20 by heljary          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "cub3d.h"

void my_mlx_pixel_put(t_img *img, int x, int y, unsigned int color)
{
    if (x < 0 || y < 0 || x >= SCREEN_WIDTH || y >= SCREEN_HEIGHT)
        return;
    int offset = y * img->line_len + x * (img->bpp / 8);
    *(unsigned int *)(img->addr + offset) = color;
}

int close_window(t_game *game)
{
    mlx_destroy_window(game->mlx, game->win);
    exit(0);
    return (0);
}


int is_valid_pos(t_game *game,float x,float y)
{
    int map_x = (int)x;
    int map_y = (int)y;

    if(map_x < 0 || map_y < 0 || map_y >= game->map.height || map_x >= game->map.width)
        return 0;
    if(game->map.map[map_y][map_x] == '1')
        return 0;
    return 1;
}
