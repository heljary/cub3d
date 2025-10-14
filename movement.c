/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heljary <heljary@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 10:32:57 by heljary           #+#    #+#             */
/*   Updated: 2025/10/14 09:28:52 by heljary          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	key__a(t_game *game, float *new_x, float *new_y)
{
	*new_x = game->player.x - sin(game->player.angle) * game->player.speed;
	*new_y = game->player.y + cos(game->player.angle) * game->player.speed;
}

void	key__d(t_game *game, float *new_x, float *new_y)
{
	*new_x = game->player.x + sin(game->player.angle) * game->player.speed;
	*new_y = game->player.y - cos(game->player.angle) * game->player.speed;
}

void	key__s__dw(t_game *game, float *new_x, float *new_y)
{
	*new_x = game->player.x - cos(game->player.angle) * game->player.speed;
	*new_y = game->player.y - sin(game->player.angle) * game->player.speed;
}

void	key__w__up(t_game *game, float *new_x, float *new_y)
{
	*new_x = game->player.x + cos(game->player.angle) * game->player.speed;
	*new_y = game->player.y + sin(game->player.angle) * game->player.speed;
}

void	ft_move(t_game *game, int key, float *new_x, float *new_y)
{
	if (key == KEY_A)
		key__a(game, new_x, new_y);
	if (key == KEY_D)
		key__d(game, new_x, new_y);
	if (key == KEY_S || key == KEY_DW)
		key__s__dw(game, new_x, new_y);
	if (key == KEY_W || key == KEY_UP)
		key__w__up(game, new_x, new_y);
}
