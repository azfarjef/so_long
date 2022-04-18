/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_pl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahmad-j <mahmad-j@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 22:04:34 by mahmad-j          #+#    #+#             */
/*   Updated: 2022/04/18 19:03:39 by mahmad-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	free_pl(t_game *g, t_vector old)
{
	t_player	*pl;
	t_player	*prev;

	pl = g->pl;
	prev = NULL;
	g->info->player--;
	while (pl)
	{
		if (pl->pos.x == old.x && pl->pos.y == old.y)
		{
			mlx_destroy_image(g->id, pl->img);
			if (!prev)
				return (free_firstpl(g));
			if (prev && !pl->next)
				return (free_lastpl(g));
			prev->next = pl->next;
			free(pl);
			pl = NULL;
			return (1);
		}
		prev = pl;
		pl = pl->next;
	}
	return (1);
}

int	free_firstpl(t_game *g)
{
	t_player	*pl;

	pl = g->pl;
	if (pl->next)
		g->pl = pl->next;
	else
		g->pl = NULL;
	free(pl);
	pl = NULL;
	return (1);
}

int	free_lastpl(t_game *g)
{
	t_player	*pl;

	pl = g->pl;
	while (pl->next->next)
		pl = pl->next;
	free(pl->next);
	pl->next = NULL;
	return (1);
}

void	free_playerlist(t_game *g)
{
	t_player	*pl;

	while (g->pl)
	{
		pl = g->pl;
		g->pl = g->pl->next;
		free(pl);
		pl = NULL;
	}
}

int	free_img(t_game *g)
{
	t_player	*pl;

	pl = g->pl;
	while (pl)
	{
		mlx_destroy_image(g->id, pl->img);
		pl = pl->next;
	}
	mlx_destroy_image(g->id, g->img.collect);
	mlx_destroy_image(g->id, g->img.exit);
	mlx_destroy_image(g->id, g->img.floor);
	mlx_destroy_image(g->id, g->img.wall);
	return (0);
}
