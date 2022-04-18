/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redraw_pl.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahmad-j <mahmad-j@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 15:24:28 by mahmad-j          #+#    #+#             */
/*   Updated: 2022/04/18 18:59:09 by mahmad-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	redraw_pl(t_game *g)
{
	t_player	*pl;

	pl = g->pl;
	while (pl)
	{
		if (pl->win_pos.x < pl->pos.x * SIZE && pl->moving)
			pl->win_pos.x++;
		if (pl->win_pos.x > pl->pos.x * SIZE && pl->moving)
			pl->win_pos.x--;
		if (pl->win_pos.y < pl->pos.y * SIZE && pl->moving)
			pl->win_pos.y++;
		if (pl->win_pos.y > pl->pos.y * SIZE && pl->moving)
			pl->win_pos.y--;
		if (pl->win_pos.x == pl->pos.x * SIZE && \
				pl->win_pos.y == pl->pos.y * SIZE)
			pl->moving = 0;
		pl = pl->next;
	}
	put_pl(g);
}

void	put_pl(t_game *g)
{
	t_player	*pl;

	pl = g->pl;
	while (pl)
	{
		mlx_put_image_to_window(g->id, g->w_id, g->img.floor, \
			pl->win_pos.x, pl->win_pos.y);
		mlx_put_image_to_window(g->id, g->w_id, pl->img, \
			pl->win_pos.x, pl->win_pos.y);
		if (!pl->moving)
			mlx_put_image_to_window(g->id, g->w_id, pl->img, \
				pl->pos.x * SIZE, pl->pos.y * SIZE);
		pl = pl->next;
	}
}
