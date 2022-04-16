/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahmad-j <mahmad-j@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/15 22:59:47 by mahmad-j          #+#    #+#             */
/*   Updated: 2022/04/16 12:19:39 by mahmad-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int		print_error(char *msg, char **map)
{
	if (map)
		free(*map);
	ft_putstr_fd("Error\n", 1);
	ft_putstr_fd(msg, 1);
	exit(0);
	return (0);
}

t_map	init_map(void)
{
	t_map	map;

	map.row = 0;
	map.col = 0;
	map.player = 0;
	map.collect = 0;
	map.exit = 0;
	return (map);
}

t_err	init_map_err(void)
{
	t_err	map;

	map.row_err = 0;
	map.player_err = 0;
	map.collect_err = 0;
	map.exit_err = 0;
	map.border_err = 0;
	map.char_err = 0;
	return (map);
}

char	**parse_arg(int ac, char **av, t_map *map)
{
	int	fd;

	if (ac != 2)
		print_error("Argument number must be two!", NULL);
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		print_error("Missing file!", NULL);
	if (ft_strrncmp(av[1], ".ber", 4))
		print_error("File must be of '.ber' type!", NULL);
	return (parse_map(fd, map));
}

char	**parse_map(int fd, t_map *info)
{
	char	**map;
	char	*raw_map;
	t_err	map_err;
	
	map = NULL;
	raw_map = NULL;
	map_err = init_map_err();
	*info = init_map();
	read_map(fd, &map_err, info, &raw_map);
	print_map_error(&map_err, &raw_map);
	map = ft_split(raw_map, '\n');
	free(raw_map);
	if (!map)
		print_error("Malloc error!", NULL);
	return (map);
}
