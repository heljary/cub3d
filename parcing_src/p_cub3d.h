/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_cub3d.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haitaabe <haitaabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 12:07:48 by haitaabe          #+#    #+#             */
/*   Updated: 2025/10/20 12:20:06 by haitaabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef P_CUB3D_H
# define P_CUB3D_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_texture_paths
{
	char			*no;
	char			*so;
	char			*ea;
	char			*we;
}					t_texture_paths;

typedef struct s_colors
{
	int				floor_color;
	int				ceiling_color;
}					t_colors;

typedef struct s_map
{
	char			**map;
	int				width;
	int				height;
}					t_map;

typedef struct s_data
{
	t_texture_paths	textures;
	t_colors		colors;
	t_map			map;
}					t_data;

#endif