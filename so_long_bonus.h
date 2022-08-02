/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equesnel <equesnel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/13 16:03:21 by equesnel          #+#    #+#             */
/*   Updated: 2022/07/27 14:09:26 by equesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "libft/libft.h"
# include "mlx_linux/mlx.h"
# include "mlx_linux/mlx_int.h"

# include <fcntl.h>

typedef struct s_data
{
	char	**map;
	char	*tmp;
	void	*mlx;
	void	*win;
	void	*heros;
	void	*heros3;
	void	*heros5;
	void	*floor;
	void	*wall;
	void	*chest;
	void	*exit;
	void	*slime;
	int		width;
	int		height;
	int		e;
	int		p;
	int		c;
	int		i;
	int		x;
}				t_data;

void	parse_map(char *av, t_data *l);
void	check_map(t_data *l);
void	put_map(t_data *l);
void	init_vars(t_data *l);
void	play(t_data *l);
int		close_win(t_data *l);
int		ft_animation(t_data *l);

void	ft_error(t_data *l);

#endif
