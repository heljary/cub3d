/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heljary <heljary@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/08 10:32:57 by heljary           #+#    #+#             */
/*   Updated: 2025/10/08 10:33:29 by heljary          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void Key__A(t_game *game, float *new_x,float *new_y,float speed){
    *new_x = game->player.x - sin(game->player.angle) * speed;
    *new_y = game->player.y + cos(game->player.angle) * speed;
}


void Key__D(t_game *game, float *new_x,float *new_y,float speed){
    *new_x = game->player.x + sin(game->player.angle) * speed;
    *new_y = game->player.y - cos(game->player.angle) * speed;
}

void Key__S__DW(t_game *game, float *new_x,float *new_y,float speed){
    *new_x = game->player.x - cos(game->player.angle) * speed;
    *new_y = game->player.y - sin(game->player.angle) * speed;
}

void Key__W__UP(t_game *game, float *new_x,float *new_y,float speed){
    *new_x = game->player.x + cos(game->player.angle) * speed;
    *new_y = game->player.y + sin(game->player.angle) * speed;
}

void ft_move(t_game *game,int key,float *new_x,float *new_y,float speed)
{
    if (key == Key_A)
        Key__A(game,new_x,new_y,speed);
    if (key == Key_D)
        Key__D(game,new_x,new_y,speed);
    if (key == Key_S || key == Key_DW)
        Key__S__DW(game,new_x,new_y,speed);
    if (key == Key_W || key == Key_UP)
        Key__W__UP(game,new_x,new_y,speed);
}