/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_map_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equesnel <equesnel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 20:08:07 by equesnel          #+#    #+#             */
/*   Updated: 2022/07/26 23:23:12 by equesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

static void	put_img(t_data *l, int i, int x)
{
	if (l->map[i][x] == '0')
		mlx_put_image_to_window(l->mlx, l->win, l->floor, x * 48, i * 48);
	else if (l->map[i][x] == '1')
		mlx_put_image_to_window(l->mlx, l->win, l->wall, x * 48, i * 48);
	else if (l->map[i][x] == 'C')
		mlx_put_image_to_window(l->mlx, l->win, l->chest, x * 48, i * 48);
	else if (l->map[i][x] == 'E')
		mlx_put_image_to_window(l->mlx, l->win, l->exit, x * 48, i * 48);
	else if (l->map[i][x] == 'P')
		mlx_put_image_to_window(l->mlx, l->win, l->heros, x * 48, i * 48);
	else if (l->map[i][x] == 'S')
		mlx_put_image_to_window(l->mlx, l->win, l->slime, x * 48, i * 48);
}

void	put_map(t_data *l)
{
	int	i;
	int	x;

	i = 0;
	while (l->map[i])
	{
		x = 0;
		while (l->map[i][x])
		{
			put_img(l, i, x);
			x++;
		}
		i++;
	}
	mlx_string_put(l->mlx, l->win, 5, 10, 0xFFFFFFFF, "0");
}
