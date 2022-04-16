/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahmad-j <mahmad-j@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 00:08:04 by mahmad-j          #+#    #+#             */
/*   Updated: 2022/04/16 12:16:24 by mahmad-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	read_map(int fd, t_err *map_err, t_map *info, char **raw_map)
{
	char	*line;
	char	*prev;
	
	
	line = NULL;
	prev = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
		{
			if (!info->col)
				print_error("Empty map!", &prev);
			else
				check_map_err(prev, map_err, info, 1);
			free(prev);
			break ;
		}
		free(prev);
		check_map_err(line, map_err, info, !info->row);
		prev = ft_strdup(line);
		*raw_map = ft_strjoinfree(*raw_map, line);
		info->row++;
	}
}

void	check_map_err(char *line, t_err *map_err, t_map *info, int is_last)
{
	if (!info->col)
		info->col = ft_strlen(line) - 1;
	if (info->col && ((info->col != (int)ft_strlen(line) - 1 && \
			ft_strchr(line, '\n')) || (info->col != (int)ft_strlen(line) && \
			!ft_strchr(line, '\n'))))
		map_err->row_err = 1;
	if (line[0] != '1' || line[info->col - 1] != '1' || \
			(ft_countcharinstr(line, '1') != info->col && is_last))
		map_err->border_err = 1;
	info->player += ft_countcharinstr(line, 'P');
	info->collect += ft_countcharinstr(line, 'C');
	info->exit += ft_countcharinstr(line, 'E');
	map_err->player_err = info->player < 1;
	map_err->collect_err = info->collect < 1;
	map_err->exit_err = info->exit < 1;
	while (line && *line)
	{
		if (!ft_strchr("01PCE\n", *line))
			map_err->char_err = 1;
		line++;
	}	
}

int	print_map_error(t_err *map_err, char **raw_map)
{
	if (map_err->row_err)
		print_error("Map must be rectangular!", raw_map);
	if (map_err->border_err)
		print_error("Map must be surrounded by walls!", raw_map);
	if (map_err->char_err)
		print_error("Invalid char in map!", raw_map);
	if (map_err->exit_err)
		print_error("Exit must be at least one!", raw_map);
	if (map_err->collect_err)
		print_error("Collectible must be at least one!", raw_map);
	if (map_err->player_err)
		print_error("Player must be at least one!", raw_map);
	return (0);
}
