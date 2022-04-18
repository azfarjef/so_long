#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include "../get_next_line/get_next_line.h"

# define SIZE 32

enum	e_direction
{
	ST = 0,
	N = 1,
	S = -1,
	E = 2,
	W = -2
};

typedef struct s_map
{
	int	row;
	int	col;
	int	player;
	int	collect;
	int	exit;
}				t_map;

typedef struct s_err
{
	int	row_err;
	int	player_err;
	int	collect_err;
	int	exit_err;
	int	border_err;
	int	char_err;
}				t_err;

typedef struct s_valid_mv
{
	int	north;
	int	south;
	int	east;
	int	west;
}				t_valid_mv;

typedef struct s_player
{
	t_vector		pos;
	t_vector		win_pos;
	int				dir;
	int				moving;
	void			*img;
	t_valid_mv		valid;
	struct s_player	*next;
}				t_player;

typedef struct s_img
{
	void	*wall;
	void	*collect;
	void	*floor;
	void	*exit;
}				t_img;

typedef struct s_game
{
	void		*id;
	void		*w_id;
	int			width;
	int			height;
	int			nmove;
	int			collect_cp;
	int			next_dir;
	int			redraw;
	int			n_update;
	int			g_rate;
	char		**map;
	char		**map_cp;
	t_map		*info;
	t_map		info_cp;
	t_img		img;
	t_player	*pl;
}				t_game;

char		**parse_arg(int ac, char **av, t_map *map);
int			print_error(char *msg, char **map);
char		**parse_map(int fd, t_map *info);
t_err		init_map_err(void);
t_map		init_map(void);
void		read_map(int fd, t_err *map_err, t_map *info, char **raw_map);
void		check_map_err(char *line, t_err *map_err, t_map *info, int is_last);
int			print_map_error(t_err *map_err, char **raw_map);

void		init_game(char **map, t_map info);
void		start_game(t_game *g, char **map, t_map *info);
t_img		load_image(t_game *g);
void		playerlist(char **map, t_game *g);
void		ft_pladd_back(t_player **lst, t_player *new);
t_player	*ft_plnew(t_vector pos);
void		load_pl_image(t_game *g);
int			update_game(t_game *g);
void		check_game(t_game *g);
void		redraw_pl(t_game *g);
void		put_pl(t_game *g);
void		next_dir(t_game *g);
void		update_valid_move(t_game *g, t_player *pl);
int			is_valid_move(t_player *pl, int dir);
int			free_pl(t_game *g, t_vector old);
void		move_pl(int dir, t_game *g, t_player *pl);
int			update_grid(t_vector old, t_vector new, t_game *g);
int			end_game(t_game *g);
int			free_img(t_game *g);
void		put_map(t_game *g, int x, int y);
int			key_hook(int key, t_game *g);
void		new_direction(t_game *g, int dir);
int			free_firstpl(t_game *g);
int			free_lastpl(t_game *g);
void		free_playerlist(t_game *g);

#endif
