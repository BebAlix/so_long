/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equesnel <equesnel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 20:05:26 by equesnel          #+#    #+#             */
/*   Updated: 2022/07/27 14:15:55 by equesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static int	check_wall(t_data *l, char move)
{
	if (move == 'w')
		if (l->map[l->i - 1][l->x] == '1')
			return (1);
	if (move == 'a')
		if (l->map[l->i][l->x - 1] == '1')
			return (1);
	if (move == 's')
		if (l->map[l->i + 1][l->x] == '1')
			return (1);
	if (move == 'd')
		if (l->map[l->i][l->x + 1] == '1')
			return (1);
	return (0);
}

static int	check_wall_exit(t_data *l, char move)
{
	if (l->c == 0)
		return (check_wall(l, move));
	if (move == 'w')
		if (l->map[l->i - 1][l->x] == '1' || l->map[l->i - 1][l->x] == 'E')
			return (1);
	if (move == 'a')
		if (l->map[l->i][l->x - 1] == '1' || l->map[l->i][l->x - 1] == 'E')
			return (1);
	if (move == 's')
		if (l->map[l->i + 1][l->x] == '1' || l->map[l->i + 1][l->x] == 'E')
			return (1);
	if (move == 'd')
		if (l->map[l->i][l->x + 1] == '1' || l->map[l->i][l->x + 1] == 'E')
			return (1);
	return (0);
}

static void	move_heros(t_data *l, char move)
{
	if (check_wall_exit(l, move) == 1)
		return ;
	mlx_put_image_to_window(l->mlx, l->win, l->floor, l->x * 48, l->i * 48);
	if (move == 'w')
		l->i -= 1;
	if (move == 'a')
		l->x -= 1;
	if (move == 's')
		l->i += 1;
	if (move == 'd')
		l->x += 1;
	if (l->map[l->i][l->x] == 'C')
	{
		l->map[l->i][l->x] = '0';
		l->c--;
	}
	mlx_put_image_to_window(l->mlx, l->win, l->heros, l->x * 48, l->i * 48);
	ft_printf("move : %d\n", ++l->p);
	if (l->map[l->i][l->x] == 'E' && l->c < 1)
		close_win(l);
}

static int	key_hook(int keycode, t_data *l)
{
	(void)l;
	if (keycode == XK_Escape)
		close_win(l);
	if (keycode == XK_w)
		move_heros(l, 'w');
	if (keycode == XK_a)
		move_heros(l, 'a');
	if (keycode == XK_s)
		move_heros(l, 's');
	if (keycode == XK_d)
		move_heros(l, 'd');
	return (0);
}

void	play(t_data *l)
{
	l->p = 0;
	mlx_key_hook(l->win, key_hook, l);
	mlx_hook(l->win, 17, 0, close_win, l);
	mlx_loop(l->mlx);
}
