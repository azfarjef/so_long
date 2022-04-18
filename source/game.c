/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahmad-j <mahmad-j@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 16:51:50 by mahmad-j          #+#    #+#             */
/*   Updated: 2022/04/18 18:18:25 by mahmad-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_game(char **map, t_map info)
{
	t_game	g;

	g.info_cp = info;
	g.collect_cp = info.collect;
	g.map_cp = ft_matrixdup(map);
	g.id = mlx_init();
	g.w_id = mlx_new_window(g.id, info.col * SIZE, \
		info.row * SIZE, "Wizard");
	start_game(&g, map, &info);
}

void	start_game(t_game *g, char **map, t_map *info)
{
	g->n_update = 1;
	g->nmove = 0;
	g->width = info->col * SIZE;
	g->height = info->row * SIZE;
	g->info = info;
	g->map = map;
	g->img = load_image(g);
	g->pl = NULL;
	playerlist(map, g);
	g->next_dir = 0;
	load_pl_image(g);
	g->g_rate = GAME_RATE;
	g->redraw = 1;
	mlx_loop_hook(g->id, update_game, (void *)g);
	mlx_hook(g->w_id, 17, 0, end_game, (void *)g);
	mlx_key_hook(g->w_id, key_hook, (void *)g);
	mlx_loop(g->id);
}

int	update_game(t_game *g)
{
	int	x;
	int	y;

	y = 0;
	g->n_update++;
	check_game(g);
	if (g->redraw)
	{
		while (g->map[y])
		{
			x = 0;
			while (g->map[y][x])
			{
				put_map(g, x, y);
				x++;
			}
			y++;
		}
		g->redraw = 0;
	}
	return (0);
}

void	check_game(t_game *g)
{
	if (!(g->n_update % g->g_rate))
		redraw_pl(g);
	if (g->next_dir != 0)
		next_dir(g);
	if (!g->info->collect && !g->info->player)
	{
		ft_putstr_fd("CONGRATULATIONS! YOU WIN!\n", 1);
		end_game(g);
	}
}

int	end_game(t_game *g)
{
	if (g->map)
		ft_freematrix(&g->map);
	if (g->map_cp)
		ft_freematrix(&g->map_cp);
	free_img(g);
	free_playerlist(g);
	ft_putstr_fd("You finished with ", 1);
	ft_putnbr_fd(g->nmove, 1);
	ft_putstr_fd(" move(s)\n", 1);
	mlx_clear_window(g->id, g->w_id);
	mlx_destroy_window(g->id, g->w_id);
	mlx_destroy_display(g->id);
	free(g->id);
	exit(0);
	return (0);
}
