/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heljary <heljary@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 10:27:19 by heljary           #+#    #+#             */
/*   Updated: 2025/10/26 14:38:20 by heljary          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, unsigned int color)
{
	int	offset;

	if (x < 0 || y < 0 || x >= SCREEN_WIDTH || y >= SCREEN_HEIGHT)
		return ;
	offset = y * img->line_len + x * (img->bpp / 8);
	*(unsigned int *)(img->addr + offset) = color;
}


int	close_window(t_game *game)
{
	if (!game)
		exit(0);
	if (game->img && game->img->img)
		mlx_destroy_image(game->mlx, game->img->img);
	if (game->img)
		free(game->img);
	if (game->win)
		mlx_destroy_window(game->mlx, game->win);
	if (game->mlx)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
	free(game);
	exit(0);
}

int	is_valid_pos(t_game *game, float x, float y)
{
	int	map_x;
	int	map_y;

	map_x = (int)x;
	map_y = (int)y;
	if (map_x < 0 || map_y < 0 || map_y >= game->map.height
		|| map_x >= game->map.width)
		return (0);
	if (game->map.map[map_y][map_x] == '1')
		return (0);
	return (1);
}



