/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_cub3d.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haitaabe <haitaabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 15:14:52 by haitaabe          #+#    #+#             */
/*   Updated: 2025/10/17 15:16:57 by haitaabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_CUB3D_H
#define PARSING_CUB3D_H

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <fcntl.h>

typedef struct s_textures 
{
    char *north;
    char *south;
    char *west;
    char *east;
} t_textures;


typedef struct s_colors
{
    int floor;
    int ceiling;
} t_colors;


typedef struct s_map
{
    char **map;
    int width;
    int height;
} t_map;

typedef struct s_data
{
    char **file_cub;
    t_textures textures;
    t_colors colors;
    t_map map;
} t_data;




char **read_file_lines(const char *filename);

#endif