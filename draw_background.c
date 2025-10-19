/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_background.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heljary <heljary@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 10:30:59 by heljary           #+#    #+#             */
/*   Updated: 2025/10/19 10:36:32 by heljary          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	draw_background(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (y < SCREEN_HEIGHT)
	{
		x = 0;
		while (x < SCREEN_WIDTH)
		{
			if (y < SCREEN_HEIGHT / 2)
				my_mlx_pixel_put(game->img, x, y, CEILING_COLOR);
			else
				my_mlx_pixel_put(game->img, x, y, FLOOR_COLOR);
			x++;
		}
		y++;
	}
}

void	ft_draw(t_game *game)
{
	draw_background(game);
	// wall_height_projection(game);
	render_walls(game);
	draw_minimap(game);
	draw_player(game);
	ft_more_ray(game);
	mlx_put_image_to_window(game->mlx, game->win, game->img->img, 0, 0);
}
