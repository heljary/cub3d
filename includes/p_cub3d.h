/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_cub3d.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haitaabe <haitaabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/03 15:14:52 by haitaabe          #+#    #+#             */
/*   Updated: 2025/10/14 09:10:09 by haitaabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_CUB3D_H
#define PARSING_CUB3D_H

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

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
} t_colors;


typedef struct s_map
{
    char **map;
    int width;
    int height;
} t_map;

typedef struct s_data
{
    t_textures textures;
    t_colors colors;
    t_map map;
} t_data;


int parse_cub_file(const char *path, t_data *data);


// these functions for textures and colors
int parse_config_line(char *line, t_data *data);
int parse_textures(char *id, char *value, t_textures *tx);
int parse_color(char id, char *value, t_colors *colors);


// reading map
char **collect_map_lines(int fd, size_t *out_count);

int build_map(char **lines, size_t count, t_map *map);


// to validate our data 
int validate_data(const t_data *data);
int validate_map_chars(const t_map *map);
int validate_map_enclosed(const t_map *map);
int find_player_pos(const t_map *map, int *px, int *py, char *dir);


// to free our data (avoiding leaks and other issues)
void free_map(char **map, int height);
void free_data(t_data *data);
void exit_error(const char *msg, t_data *data, int code);

#endif