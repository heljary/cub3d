/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heljary <heljary@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 09:39:34 by heljary           #+#    #+#             */
/*   Updated: 2025/10/14 09:39:35 by heljary          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(void)
{
	t_game *game;

	game = malloc(sizeof(t_game));
	game->img = malloc(sizeof(t_img));
	if (!game || !game->img)
		return (1);
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		printf("Error: MLX initialization failed\n");
		return (1);
	}

	game->map.map = (char *[]){"111111111111111111111111111",
		"100000000000000000000000001", "100000000000000000000000001",
		"100000000000000000000000001", "100000000000000000000000001",
		"100000000000000000000000001", "100000000000000000000000001",
		"100000000000000000000000001", "100000000000000000000000001",
		"100000000000000000000000001", "100000000000000000000000001",
		"100000000000000000000000001", "100000000000000000000000001",
		"100000000000000000000000001", "111111111111111111111111111", NULL};

	game->map.width = 27;
	game->map.height = 15;
	game->map.player_x = 2.5;
	game->map.player_y = 2.5;
	game->map.player_dir = 'N';

	game->win = mlx_new_window(game->mlx, SCREEN_WIDTH, SCREEN_HEIGHT, "Cub3D");
	if (!game->win)
	{
		printf("Error: Window creation failed\n");
		return (1);
	}
	game->size_pxl = 10;
	game->player.angle = 0 * PI / 180.0;
	game->map_width = 27;
	game->map_height = 14;
	game->player.fov = 45 * PI / 180.0;
	game->player.dir_x = cos(game->player.angle);
	game->player.dir_y = sin(game->player.angle);
	game->img->img = mlx_new_image(game->mlx, SCREEN_WIDTH, SCREEN_HEIGHT);
	game->img->addr = mlx_get_data_addr(game->img->img, &game->img->bpp,
			&game->img->line_len, &game->img->endian);
	game->player.x = 5.0;
	game->player.y = 7.0;
	game->player.speed = 0.3;
	ft_draw(game);
	mlx_key_hook(game->win, key_hook, game);
	mlx_hook(game->win, 17, 1L << 17, close_window, game);
	mlx_loop(game->mlx);
	return (0);
}