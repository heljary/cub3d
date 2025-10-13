/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_cub3d.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haitaabe <haitaabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 15:14:52 by haitaabe          #+#    #+#             */
/*   Updated: 2025/10/13 19:11:58 by haitaabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_CUB3D_H
#define PARSING_CUB3D_H



typedef struct s_textures 
{
    char *north;
    char *south;
    char *west;
    char *east;
} t_textures;


typedef struct s_colors
{
    int floor[3];
    int ceiling[3];
} s_colors;


typedef struct s_map
{
    char **grid_map;
    int width;
    int height;
} t_map;

typedef struct s_data
{
    t_textures textures;
    s_colors colors;
    t_map map;
} s_data;





#endif