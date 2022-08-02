/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_animation.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equesnel <equesnel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 11:50:12 by equesnel          #+#    #+#             */
/*   Updated: 2022/07/27 11:52:35 by equesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	ft_animation(t_data *l)
{
	static int	i;

	usleep(8000);
	if (++i / 1000)
	{
		i = 0;
		mlx_put_image_to_window(l->mlx, l->win, l->heros,
			l->x * 48, l->i * 48);
	}
	if (++i / 100)
	{
		i = 0;
		mlx_put_image_to_window(l->mlx, l->win, l->heros3,
			l->x * 48, l->i * 48);
	}
	if (++i / 100)
	{
		i = 0;
		mlx_put_image_to_window(l->mlx, l->win, l->heros5,
			l->x * 48, l->i * 48);
	}
	return (0);
}
