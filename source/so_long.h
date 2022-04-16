#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdlib.h>
# include <fcntl.h>
#include "../libft/libft.h"
#include "../get_next_line/get_next_line.h"

typedef struct	s_map
{
	int	row;
	int	col;
	int	player;
	int collect;
	int	exit;
}				t_map;

typedef struct	s_err
{
	int	row_err;
	int	player_err;
	int collect_err;
	int	exit_err;
	int	border_err;
	int	char_err;
}				t_err;

char	**parse_arg(int ac, char **av, t_map *map);
int		print_error(char *msg, char **map);
char	**parse_map(int fd, t_map *info);
t_err	init_map_err(void);
t_map	init_map(void);
void	read_map(int fd, t_err *map_err, t_map *info, char **raw_map);
void	check_map_err(char *line, t_err *map_err, t_map *info, int is_last);
int		print_map_error(t_err *map_err, char **raw_map);

#endif
