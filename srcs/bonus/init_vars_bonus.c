/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_vars_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equesnel <equesnel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 23:12:38 by equesnel          #+#    #+#             */
/*   Updated: 2022/07/26 23:59:48 by equesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

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
	int	w;
	int	h;

	l->floor = mlx_xpm_file_to_image(l->mlx, "../image/floor.xpm", &w, &h);
	l->wall = mlx_xpm_file_to_image(l->mlx, "../image/wall.xpm", &w, &h);
	l->chest = mlx_xpm_file_to_image(l->mlx, "../image/chest.xpm", &w, &h);
	l->exit = mlx_xpm_file_to_image(l->mlx, "../image/door.xpm", &w, &h);
	l->slime = mlx_xpm_file_to_image(l->mlx, "../image/slime.xpm", &w, &h);
	l->heros = mlx_xpm_file_to_image(l->mlx, "../image/knight.xpm", &w, &h);
	l->heros3 = mlx_xpm_file_to_image(l->mlx, "../image/knight3.xpm", &w, &h);
	l->heros5 = mlx_xpm_file_to_image(l->mlx, "../image/knight5.xpm", &w, &h);
}

void	init_vars(t_data *l)
{
	l->mlx = mlx_init();
	init_sprite(l);
	init_size_win(l);
	l->win = mlx_new_window(l->mlx, l->width, l->height, "So long");
}
