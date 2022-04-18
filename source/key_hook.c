/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahmad-j <mahmad-j@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 23:48:36 by mahmad-j          #+#    #+#             */
/*   Updated: 2022/04/18 18:24:32 by mahmad-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int key, t_game *g)
{
	if (key == KEY_Q || key == KEY_ESC)
	{
		ft_putstr_fd("You exited the game early!\n", 1);
		end_game(g);
	}
	if (key == KEY_W && g->next_dir != N)
		new_direction(g, N);
	if (key == KEY_S && g->next_dir != S)
		new_direction(g, S);
	if (key == KEY_D && g->next_dir != E)
		new_direction(g, E);
	if (key == KEY_A && g->next_dir != W)
		new_direction(g, W);
	return (0);
}
