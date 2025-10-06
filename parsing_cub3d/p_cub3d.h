/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_cub3d.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haitaabe <haitaabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 15:14:52 by haitaabe          #+#    #+#             */
/*   Updated: 2025/10/06 16:34:13 by haitaabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_CUB3D_H
#define PARSING_CUB3D_H


typedef struct s_config
{
    char    *no_texture;
    char    *so_texture;
    char    *we_texture;
    char    *ea_texture;
    int     floor_color[3];
    int     ceiling_color[3];
}   t_config;

typedef struct s_map
{
    char    **map;
    int     width;
    int     height;
    float  player_x;
    float  player_y;
    char    player_dir;
}   t_map;

typedef struct s_data
{
    t_config config;
    t_map map;
}   t_data;


typedef struct s_file
{
    char **config_textures;
    char **map_lines;
    int   directions;
    int   raw_map;
}   t_file;



#endif