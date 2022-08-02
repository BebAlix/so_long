/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equesnel <equesnel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 16:40:10 by equesnel          #+#    #+#             */
/*   Updated: 2022/07/26 23:23:08 by equesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

int	main(int ac, char **av)
{
	t_data	l;

	if (ac != 2)
		return (0);
	parse_map(av[1], &l);
	check_map(&l);
	init_vars(&l);
	put_map(&l);
	play(&l);
}
