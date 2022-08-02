/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equesnel <equesnel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 20:11:11 by equesnel          #+#    #+#             */
/*   Updated: 2022/07/27 14:09:24 by equesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	check_char(t_data *l)
{
	int	i;
	int	x;

	i = 0;
	while (l->map[i])
	{
		x = 0;
		while (l->map[i][x + 1])
		{
			if (l->map[i][x] != '1' && l->map[i][x] != '0'
				&& l->map[i][x] != 'E' && l->map[i][x] != 'P'
				&& l->map[i][x] != 'C')
				ft_error(l);
			x++;
		}
		i++;
	}
}

static void	check_basics(t_data *l)
{
	int	i;
	int	x;

	i = 0;
	while (l->map[i])
	{
		x = 0;
		while (l->map[i][x])
		{
			if (l->map[i][x] == 'P')
			{
				l->p++;
				l->i = i;
				l->x = x;
			}
			if (l->map[i][x] == 'E')
				l->e++;
			if (l->map[i][x] == 'C')
				l->c++;
			x++;
		}
		i++;
	}
	if (l->p != 1 || l->e < 1 || l->c < 1)
		ft_error(l);
}

static void	check_rectangular(t_data *l)
{
	size_t	len;
	int		i;

	len = ft_strlen(l->map[0]);
	i = 1;
	while (l->map[i])
	{
		if (ft_strlen(l->map[i]) != len)
			ft_error(l);
		i++;
	}
}

static void	check_wall(t_data *l)
{
	int	tmp;
	int	i;
	int	x;

	i = 0;
	x = 1;
	while (l->map[i] && l->map[i][0] == '1')
		i++;
	while (l->map[0][x] == '1')
		x++;
	if (l->map[i] || l->map[0][x])
		ft_error(l);
	x--;
	tmp = 0;
	while (l->map[tmp] && l->map[tmp][x] == '1')
		tmp++;
	if (tmp != i)
		ft_error(l);
	i--;
	tmp = 0;
	while (l->map[i][tmp] == '1')
		tmp++;
	if (l->map[i][tmp])
		ft_error(l);
}

void	check_map(t_data *l)
{
	l->p = 0;
	l->c = 0;
	l->e = 0;
	check_char(l);
	check_basics(l);
	check_rectangular(l);
	check_wall(l);
}
