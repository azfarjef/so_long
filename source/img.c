/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahmad-j <mahmad-j@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 18:24:06 by mahmad-j          #+#    #+#             */
/*   Updated: 2022/04/18 18:56:50 by mahmad-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_img	load_image(t_game *g)
{
	int	size;

	size = SIZE;
	g->img.wall = mlx_xpm_file_to_image(g->id, "asset/wall.xpm", &size, &size);
	g->img.exit = mlx_xpm_file_to_image(g->id, "asset/exit.xpm", &size, &size);
	g->img.collect = mlx_xpm_file_to_image(g->id, "asset/collect.xpm", &size, \
		&size);
	g->img.floor = mlx_xpm_file_to_image(g->id, "asset/floor.xpm", &size, \
		&size);
	return (g->img);
}

void	load_pl_image(t_game *g)
{
	t_player	*pl;
	int			s;

	s = SIZE;
	pl = g->pl;
	while (pl)
	{
		pl->img = mlx_xpm_file_to_image(g->id, "asset/player.xpm", &s, &s);
		pl = pl->next;
	}
}
