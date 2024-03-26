#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx/mlx.h"
# include "mlx/mlx_int.h"
# include "./my_libs/libft/libft.h"
# include "./my_libs/get_next_line/get_next_line.h"
# include "./my_libs/ft_printf/ft_printf.h"
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
	char		**test_map;
	t_position	player;
	int			rows;
	int			collums;
	int			collectables;
	int			testcounter;
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
	void		*ptr[18];
	void		*tr[4];
	char		*path[18];
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

/* start_check.c */
int				start_check(t_data *data, char *argv[]);
int				map_valid(t_data *data, char **visited);

/* get_values.c */
int				linecount(int fd);
int				count_collectables(t_data *data);
void			player_position(t_data *data);

/* get_values */
int				p_e_check(t_data *data);
int				line_check(t_data *data);
int				wall_check(t_data *data);

/* create_map.c */
void			fill_map(t_data *data, int fd);

/* solve_level.c */
char			explore_surroundings(char c, t_data *data);
void			pathfinder(char **visited, int c, int i, t_data *data);
int				deadend(char **visited, int c, int i, t_data *data);
int				iterate_map(char **visited, t_data *data, int i, int c);
int				solve_level(char **visited, t_data *data);

/* freemem.c */
void			freemap(t_data *data, char **map);
void			freeimg(t_data *data, void *img[], int n);
void			freename(char *name[]);
void			freedata(t_data *data);
void			free_everything(t_data *data);

/* error.c */
void			wall_error(int i);

/* so_long.c */
void			map_to_terminal(t_data *data);
void			visited_to_terminal(char **visited);

/* error.c */
void			error_msg(char *msg);
void			error(char *msg, t_data *data);

/* mlx_init.c */
int				mlx_initialize(t_data *data);
int				escape(int key, t_data *data);
int				destruction(t_data *data);

/* mlx_img.c */
void			background(t_data *data);
void			test_stuff(t_data *data);
void			test_walls(t_data *data);

/* what_wall.c */
int				what_wall(t_data *data);
int				explore_walls(char c);
int				place_border(t_data *data);
int				check_for_wall(char c);

/* get_imgs.c */
void			image_alloc(t_data *data);
void			get_imgs(t_data *data);

#endif
