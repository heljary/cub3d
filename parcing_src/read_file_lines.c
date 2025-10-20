/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file_lines.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haitaabe <haitaabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 11:40:33 by haitaabe          #+#    #+#             */
/*   Updated: 2025/10/20 11:59:36 by haitaabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/p_cub3d.h"


char **read_file_lines(const char *filename)
{
    int fd;
    int open_file = open("../maps/map1.cub", O_RDONLY);
    if (open_file == -1)
        return (NULL);
    char buffer[1024];
    
}