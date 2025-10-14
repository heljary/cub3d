/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_minimap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heljary <heljary@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 10:28:23 by heljary           #+#    #+#             */
/*   Updated: 2025/10/14 09:38:28 by heljary          ###   ########.fr       */
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
