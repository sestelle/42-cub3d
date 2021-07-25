#ifndef STRUCTS_H
# define STRUCTS_H

/* POINTS */

typedef struct s_int
{
	int	x;
	int	y;
}				t_int;

typedef struct s_double
{
	double	x;
	double	y;
}				t_double;

/* BOOLEAN */

typedef enum e_bool
{
	false,
	true
}				t_bool;

/* CONFIG */

typedef struct s_res
{
	int	width;
	int	height;
}				t_res;

typedef struct s_plr
{
	t_double	pos;
	t_double	dir;
	t_double	plane;
}				t_plr;

typedef struct s_cfg
{
	t_res	res;
	int		ceiling;
	int		floor;
	char	*north;
	char	*south;
	char	*west;
	char	*east;
	char	*sprite;
	char	**map;
	t_plr	plr;
	t_bool	save;
}				t_cfg;

/* IMG */

typedef struct s_img
{
	void	*img;
	int		*addr;
	int		bpp;
	int		ll;
	int		endian;
	int		width;
	int		height;
}				t_img;

/* ENGINE */

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
}				t_mlx;

typedef struct s_textures
{
	int	*north;
	int	*south;
	int	*west;
	int	*east;
	int	*sprite;
}				t_textures;

typedef struct s_events
{
	t_bool	key_a;
	t_bool	key_s;
	t_bool	key_d;
	t_bool	key_w;
	t_bool	key_left;
	t_bool	key_right;
}				t_events;

typedef struct s_engine
{
	t_mlx		mlx;
	t_cfg		cfg;
	t_img		img;
	t_textures	textures;
	t_events	events;
	double		*z_buffer;
}				t_engine;

/* WALLS */

typedef struct s_walls
{
	double		camera_x;
	t_double	ray;
	t_int		map;
	t_double	side_dist;
	t_double	delta_dist;
	double		perp_wall_dist;
	t_int		step;
	int			side;
	int			line_height;
	int			draw_start;
	int			draw_end;
	int			color;
	int			tex_x;
	int			tex_y;
	int			tex_num;
	double		wall_x;
	double		tex_pos;
	double		_step;
}				t_walls;

/* SPRITES */

typedef struct s_pair
{
	double	first;
	int		second;
}				t_pair;

typedef struct s_sprites
{
	t_double	*sprites;
	int			*sprite_order;
	double		*sprite_distance;
	int			count;
	t_double	sprite;
	double		inv_det;
	t_double	transform;
	int			sprite_screen_x;
	int			v_move_screen;
	int			sprite_height;
	int			sprite_width;
	int			draw_start_y;
	int			draw_end_y;
	int			draw_start_x;
	int			draw_end_x;
	int			tex_x;
	int			d;
	int			tex_y;
	int			color;
}				t_sprites;

#endif