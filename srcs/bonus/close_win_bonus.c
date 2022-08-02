/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_win_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equesnel <equesnel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 23:13:06 by equesnel          #+#    #+#             */
/*   Updated: 2022/07/27 00:36:07 by equesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

static void	free_map(t_data *l)
{
	int	i;

	i = 0;
	if (l->map)
	{
		while (l->map[i])
		{
			free(l->map[i]);
			i++;
		}
	}
	free(l->map);
	free(l->tmp);
}

static void	destroy_image(t_data *l)
{
	mlx_destroy_image(l->mlx, l->floor);
	mlx_destroy_image(l->mlx, l->wall);
	mlx_destroy_image(l->mlx, l->chest);
	mlx_destroy_image(l->mlx, l->exit);
	mlx_destroy_image(l->mlx, l->slime);
	mlx_destroy_image(l->mlx, l->heros);
	mlx_destroy_image(l->mlx, l->heros3);
	mlx_destroy_image(l->mlx, l->heros5);
}

int	close_win(t_data *l)
{
	mlx_clear_window(l->mlx, l->win);
	destroy_image(l);
	mlx_destroy_window(l->mlx, l->win);
	mlx_destroy_display(l->mlx);
	free_map(l);
	free(l->mlx);
	exit(0);
}

void	ft_error(t_data *l)
{
	ft_printf("Error\nMap invalid !");
	free_map(l);
	exit(0);
}
