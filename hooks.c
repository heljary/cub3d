/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heljary <heljary@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 10:34:36 by heljary           #+#    #+#             */
/*   Updated: 2025/10/08 10:35:01 by heljary          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int key_hook(int key, void *pram)
{
    t_game *game = (t_game*)pram;
    mlx_clear_window(game->mlx, game->win);
    float new_x = game->player.x;
    float new_y = game->player.y;
    float speed = 0.3;
    float rot_speed = 0.1;
    if (key == Key_ESC)
        close_window(game);
    if (key == Key_L)
        game->player.angle -= rot_speed;
    if (key == Key_R)
        game->player.angle += rot_speed;
    while (game->player.angle >= 2 * Pi)
        game->player.angle -= 2 * Pi;
    while (game->player.angle < 0)
        game->player.angle += 2 * Pi;
    ft_move(game,key,&new_x,&new_y,speed);
    if (is_valid_pos(game, new_x, game->player.y))
        game->player.x = new_x;
    if (is_valid_pos(game, game->player.x, new_y))
        game->player.y = new_y;
    ft_draw(game);
    return 0;
}