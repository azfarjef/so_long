/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   next_direction.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahmad-j <mahmad-j@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 16:52:33 by mahmad-j          #+#    #+#             */
/*   Updated: 2022/04/18 18:58:11 by mahmad-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	next_dir(t_game *g)
{
	t_player	*pl;
	int			n_pl;

	pl = g->pl;
	n_pl = g->info->player;
	while (pl)
	{
		if (!pl->moving)
		{
			update_valid_move(g, pl);
			if (g->next_dir && is_valid_move(pl, g->next_dir))
				pl->dir = g->next_dir;
			move_pl(pl->dir, g, pl);
			if (n_pl != g->info->player)
				break ;
		}
		pl = pl->next;
	}
}

void	move_pl(int dir, t_game *g, t_player *pl)
{
	t_vector	new;

	if (pl)
	{
		if (dir == N && ft_strchr("0CE", g->map[pl->pos.y - 1][pl->pos.x]))
			new = ft_vectornew(pl->pos.x, pl->pos.y - 1);
		else if (dir == S && ft_strchr("0CE", g->map[pl->pos.y + 1][pl->pos.x]))
			new = ft_vectornew(pl->pos.x, pl->pos.y + 1);
		else if (dir == E && ft_strchr("0CE", g->map[pl->pos.y][pl->pos.x + 1]))
			new = ft_vectornew(pl->pos.x + 1, pl->pos.y);
		else if (dir == W && ft_strchr("0CE", g->map[pl->pos.y][pl->pos.x - 1]))
			new = ft_vectornew(pl->pos.x - 1, pl->pos.y);
		else
			new = ft_vectornew(0, 0);
		if (g->map[new.y][new.x] == 'C')
			g->info->collect--;
		if (new.x && new.y)
			update_grid(ft_vectornew(pl->pos.x, pl->pos.y), new, g);
	}
}

int	update_grid(t_vector old, t_vector new, t_game *g)
{
	t_player	*pl;
	int			hide;

	pl = g->pl;
	hide = 0;
	if (g->map[new.y][new.x] == 'E')
	{
		if (g->info->collect)
			return (1);
		mlx_put_image_to_window(g->id, g->w_id, g->img.floor, \
			old.x * SIZE, old.y * SIZE);
		hide = free_pl(g, old);
	}
	while (!hide && pl)
	{
		if (pl->pos.x == old.x && pl->pos.y == old.y)
		{
			pl->pos = ft_vectornew(new.x, new.y);
			pl->moving = 1;
		}
		pl = pl->next;
	}
	ft_memset(&g->map[new.y][new.x], g->map[old.y][old.x], !hide);
	ft_memset(&g->map[old.y][old.x], '0', 1);
	return (1);
}

void	new_direction(t_game *g, int dir)
{
	t_player	*pl;

	pl = g->pl;
	if (g->nmove < 9999)
		g->nmove++;
	ft_putstr_fd("Current number of move : ", 1);
	ft_putnbr_fd(g->nmove, 1);
	ft_putstr_fd("\n", 1);
	while (pl)
	{
		g->next_dir = dir;
		pl = pl->next;
	}
}
