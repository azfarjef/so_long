/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   playerlist.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mahmad-j <mahmad-j@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 06:59:01 by mahmad-j          #+#    #+#             */
/*   Updated: 2022/04/18 19:00:25 by mahmad-j         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	playerlist(char **map, t_game *g)
{
	int	x;
	int	y;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (map[y][x] == 'P')
				ft_pladd_back(&g->pl, ft_plnew(ft_vectornew(x, y)));
			x++;
		}
		y++;
	}
}

void	ft_pladd_back(t_player **lst, t_player *new)
{
	t_player	*tmp;

	tmp = *lst;
	if (*lst)
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	else
		*lst = new;
}

t_player	*ft_plnew(t_vector pos)
{
	t_player	*pl;

	pl = malloc(sizeof(t_player));
	if (!pl)
		return (NULL);
	pl->pos = pos;
	pl->win_pos = ft_vectornew(pos.x * SIZE, pos.y * SIZE);
	pl->moving = 0;
	pl->dir = ST;
	pl->next = NULL;
	return (pl);
}
