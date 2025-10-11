/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_cub3d.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haitaabe <haitaabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 15:14:52 by haitaabe          #+#    #+#             */
/*   Updated: 2025/10/11 18:24:39 by haitaabe         ###   ########.fr       */
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
    int floor;
    int ceiling;
} s_colors;

#endif