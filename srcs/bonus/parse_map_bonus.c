/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: equesnel <equesnel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/14 15:34:05 by equesnel          #+#    #+#             */
/*   Updated: 2022/07/26 23:23:08 by equesnel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long_bonus.h"

static void	check_extension(char *av)
{
	char	*str;
	int		len;

	len = ft_strlen(av);
	str = av + len - 4;
	if (ft_strncmp(str, ".ber", 4) == 0)
		return ;
	ft_printf("Error\nWrong map extension !");
	exit(0);
}

static int	len_map(char *av, t_data *l)
{
	int		len;
	int		fd;
	int		i;

	l->tmp = ft_calloc(sizeof(char), 1);
	if (!l->tmp)
		return (0);
	fd = open(av, O_RDONLY);
	if (fd == -1)
		ft_error(l);
	i = 1;
	len = 0;
	while (i)
	{
		i = read(fd, l->tmp, 1);
		if (i == -1)
			ft_error(l);
		len++;
	}
	free (l->tmp);
	l->tmp = NULL;
	if (close(fd) == -1)
		ft_error(l);
	return (len);
}

void	parse_map(char *av, t_data *l)
{
	int		len;
	int		fd;
	int		i;

	l->map = NULL;
	l->tmp = NULL;
	check_extension(av);
	len = len_map(av, l);
	l->tmp = ft_calloc(sizeof(char), len);
	if (!l->tmp)
		return ;
	fd = open(av, O_RDONLY);
	if (fd == -1)
		ft_error(l);
	i = read(fd, l->tmp, len);
	if (i == -1)
		return ;
	l->map = ft_split(l->tmp, '\n');
	if (close(fd) == -1)
		ft_error(l);
}
