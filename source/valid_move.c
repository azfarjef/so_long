/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahmad-j <mahmad-j@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 18:02:54 by mahmad-j          #+#    #+#             */
/*   Updated: 2022/04/18 18:59:49 by mahmad-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	update_valid_move(t_game *g, t_player *pl)
{
	pl->valid.north = !ft_strchr("1", g->map[pl->pos.y - 1][pl->pos.x]);
	pl->valid.south = !ft_strchr("1", g->map[pl->pos.y + 1][pl->pos.x]);
	pl->valid.east = !ft_strchr("1", g->map[pl->pos.y][pl->pos.x + 1]);
	pl->valid.west = !ft_strchr("1", g->map[pl->pos.y][pl->pos.x - 1]);
}

int	is_valid_move(t_player *pl, int dir)
{
	if (dir == N && pl->valid.north)
		return (1);
	if (dir == S && pl->valid.south)
		return (1);
	if (dir == E && pl->valid.east)
		return (1);
	if (dir == W && pl->valid.west)
		return (1);
	if (dir == ST)
		return (1);
	return (0);
}
