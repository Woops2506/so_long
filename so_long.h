#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx/mlx.h"
# include "mlx/mlx_int.h"
# include "libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <X11/X.h>
# include <X11/keysym.h>

typedef struct s_position
{
	int	c;
	int	i;
}	t_position;

typedef struct s_map
{
	char		**map;
	t_position	player;
	int			rows;
	int			collums;
	int			collectables;
}	t_map;

typedef struct s_player
{
	int		width;
	int		height;
	int		line_len;
	int		bpp;
	int		endian;
	void	*ptr[16];
	void	*tr[16];
	char	*name[16];
	char	*addr[16];
	char	*tr_addr[16];
}	t_player;


typedef struct s_imge
{
	int			width;
	int			height;
	int			line_len[4];
	int			bpp[4];
	int			endian[4];
	void		*ptr[4];
	void		*tr[4];
	char		*name[4];
	char		*addres[4];
	char		*tr_addr[4];
}	t_imge;

typedef struct s_data
{
	void		*mlx_ptr;
	void		*win_ptr;
	int			win_h;
	int			win_w;
	t_imge		img;
	t_player	player;
	t_position	currentimg;
	t_map		map;
	int			steps;
}	t_data;

//start
int				start_check(t_map *map, char *argv[]);
int				map_init(t_map map);

//get_values
int				linecount(int fd);
int				count_collectables(t_map *map);
void			player_position(t_map *map);

//level_check	
int				p_e_check(t_map *map);
char			**create_map(t_map *map, char **visited, int fd);
char			**fill_map(t_map *map, int fd);
int				line_check(t_map *map);
int				wall_check(t_map *map);

//solve_level
char			explore_surroundings(char c);
int				pathfinder(char **visited, int c, int i, int counter);
int				deadend(char **visited, int c, int i);
int				iterate_map(char **visited, t_map *map);
int				solve_level(char **visited, t_map *map);

//solve_level2
int				counter_check(char c);

//freemem
void			freevisited(char **visited, t_map *map);
void			freemap(t_map *map);
void			freeimg(t_data *data, void *img[]);
void			freename(char *name[]);
void			freedata(t_data *data);

//error
void			wall_error(int i);

//so_long
void			map_to_terminal(t_map map);

//keyhandling
int				on_destroy(t_data *data);
int				on_keypress(int keysym, t_data *data);

//game_handling
int				control(t_data *data);

//image_handling
int				image_to_window(t_data *data);
int				animation(t_data *data);
int				frames(t_data *data, int i, int frame);
int				base_img_print(t_data *data, int i);

//paths
char			*path(int c);

//movment handling
int				valid_move(t_data *data, char c);
void			collecting(t_data *data);
void			end_game(t_data *data);

//trancperancy
void			transperency(t_data *data, int n);
void			put_pixel_img(t_data *data, int c, int i, int n, int color);
unsigned int	get_pixel_img(t_data *data, int c, int i, int n);
unsigned int	get_pixel_img_img(t_data *data, int c, int i, int n);
void			put_pixel_img_img(t_data *data, int c, int i, int n, int color);
void			transperency_img(t_data *data, int n);

//update
int				update(t_data *data);
void			player(t_data *data);

#endif