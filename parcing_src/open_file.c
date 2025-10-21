/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: haitaabe <haitaabe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/20 13:42:11 by haitaabe          #+#    #+#             */
/*   Updated: 2025/10/21 12:54:52 by haitaabe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "p_cub3d.h"

int	open_file(const char *filename)
{
	int	fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		perror("Cub3D");
		exit(EXIT_FAILURE);
	}
	return (fd);
}
