/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_vars.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equesnel <equesnel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 23:12:38 by equesnel          #+#    #+#             */
/*   Updated: 2022/07/26 16:40:04 by equesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	init_size_win(t_data *l)
{
	l->height = 0;
	l->width = 0;
	while (l->map[0][l->width])
		l->width++;
	while (l->map[l->height])
		l->height++;
	l->height *= 48;
	l->width *= 48;
}

static void	init_sprite(t_data *l)
{
	int	width;
	int	height;

	l->floor = mlx_xpm_file_to_image(l->mlx, "../image/floor.xpm",
			&width, &height);
	l->wall = mlx_xpm_file_to_image(l->mlx, "../image/wall.xpm",
			&width, &height);
	l->heros = mlx_xpm_file_to_image(l->mlx, "../image/knight.xpm",
			&width, &height);
	l->chest = mlx_xpm_file_to_image(l->mlx, "../image/chest.xpm",
			&width, &height);
	l->exit = mlx_xpm_file_to_image(l->mlx, "../image/door.xpm",
			&width, &height);
}

void	init_vars(t_data *l)
{
	l->mlx = mlx_init();
	init_sprite(l);
	init_size_win(l);
	l->win = mlx_new_window(l->mlx, l->width, l->height, "So long");
}
