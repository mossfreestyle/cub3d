/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwassim <rwassim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 18:18:04 by mfernand          #+#    #+#             */
/*   Updated: 2025/07/07 16:02:33 by rwassim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../minilibx-linux/mlx.h"
# include "../minilibx-linux/mlx_int.h"
# include "libft.h"
# include <X11/Xlib.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef ERROR_MSG
#  define ERROR_MSG "Error\n"
# endif

# ifndef WIDTH_DISPLAY
#  define WIDTH_DISPLAY 1024
# endif

# define WIN_TITLE "cub3D"
# ifndef HEIGHT_DISPLAY
#  define HEIGHT_DISPLAY 768
# endif
# define EPS 1e-6
# define MIN_SCALE 5
# define MAX_SCALE 12
# define ROT_SPEED 0.007
# define MOUSE_SENS 0.007
# define DIR_LEN 10
# define MINIMAP_SCALE 8
# define MAX_TEX 800
# define MOVE_SPEED 0.009

# define BLACK 0x000000
# define WHITE 0xFFFFFF
# define DARK_GREY 0x333333
# define GREY 0xCCCCCC
# define RED 0xFF0000

typedef enum s_orientation
{
	N,
	S,
	E,
	W,
}					t_orientation;

typedef enum s_move
{
	m_forward,
	m_backward,
	m_left,
	m_right,
}					t_move;

/////////PLAYER///////////////

typedef struct s_player
{
	t_orientation	view;
	t_move			move;

	double			x;
	double			y;
	double			dir_x;
	double			dir_y;
	double			plane_x;
	double			plane_y;
	double			angle;
	float			speed;
	float			speed_rot;

}					t_player;

//////////////KEY///////////////////
typedef struct s_key
{
	int				key_w;
	int				key_s;
	int				key_a;
	int				key_d;
	int				key_down;
	int				turn_left;
	int				turn_right;
	int				x_old;
	int				esc;
	bool			press_w;
	bool			press_s;
	bool			press_a;
	bool			press_d;
	bool			press_turn_left;
	bool			press_turn_right;

}					t_key;

///////////MLX//////////////
typedef struct m_mlx
{
	void			*mlx;
	void			*window;
	void			*img;
	int				width;
	int				height;
	char			*adr;
	int				bpp;
	int				size_line;
	int				endian;
}					t_mlx;
//////////////ASSETS/////////////////////

typedef struct s_assets
{
	char			*path_no;
	char			*path_so;
	char			*path_we;
	char			*path_ea;
	int				ceiling_color[3];
	int				floor_color[3];
	int				floor_col;
	int				ceiling_col;
	bool			c_color;
	bool			f_color;
	bool			valid_cardinals;
	t_mlx			*no;
	t_mlx			*so;
	t_mlx			*we;
	t_mlx			*ea;
}					t_assets;

//////////MAP//////////////

typedef struct s_map
{
	char			**stash;
	char			**final_map;
	char			**first_map;
	char			player_dir;
	int				x_max;
	int				y_max;
	int				fd;
	bool			closed;
	bool			map_ready;
	int				distance_to_wall;
	int				nb_players;
	int				nb_lines;
	int				x_spawn;
	int				y_spawn;
	int				line_max;

}					t_map;

typedef struct s_ray
{
	double			dir_x;
	double			dir_y;
	int				map_x;
	int				map_y;
	double			s_dist_x;
	double			s_dist_y;
	double			d_dist_x;
	double			d_dist_y;
	int				step_x;
	int				step_y;
	int				side;
	int				hit;
	double			wall_dist;
}					t_ray;

typedef struct s_draw
{
	int				tex_x;
	int				y;
	int				end;
	double			step;
	double			tex_pos;
	int				line_height;
}					t_draw;

typedef struct s_info
{
	t_player		*player;
	t_map			*map_info;
	t_assets		*assets;
	t_mlx			*mlx;
	t_key			*key;
	t_ray			*ray;
	t_draw			*draw;
	void			*win;
	int				minimap;
	int				controls;
	bool			in_map;
	bool			valid_map;
	bool			valid_assets;
	bool			map_copied;
	int				map_scale;
	int				map_file;

}					t_info;

//////////MAIN//////////
void				exit_failure(char *msg);
void				free_all(t_info *info);

//////////PARSING//////////
void				parse_scene_file(char *filename, t_info *cub);
t_mlx				*get_wall_texture(t_info *info);

//////////RENDER//////////
void				render_frame(t_info *cub);
void				render_rays(t_info *cub);
void				draw_wall(t_info *cub, int x);
void				draw_minimap(t_info *cub);
void				put_pixel(t_mlx *img, int x, int y, int color);
void				convert_colors_to_int(t_info *info);
void				init_render_system(t_info *info);
int					create_rgb_color(int r, int g, int b);
int					game_loop(t_info *info);
void				start_game_loop(t_info *info);
int					key_press(int keycode, t_info *info);
int					key_release(int keycode, t_info *info);
void				init_player_position(t_info *info);
void				init_other(t_info *info);
int					init_assets(t_assets *assets);

//////////PLAYER//////////
void				set_player_direction(t_info *cub, char c);

//////////MOVEMENT//////////
void				move_forward(t_info *cub);
void				move_backward(t_info *cub);
void				strafe_left(t_info *cub);
void				strafe_right(t_info *cub);
void				rotate(t_player *p, double angle);

//////////EVENTS//////////
void				init_hooks(t_info *cub);
int					mouse_move(int x, int y, t_info *cub);
int					mouse_release(int button, int x, int y, t_info *cub);
int					mouse_press(int button, int x, int y, t_info *cub);

//////////TEXTURE//////////
void				load_textures(t_info *cub);
void				load_texture(t_info *cub, t_mlx *tex, char *path);
int					get_tex_y(int y, int line_h, int tex_h);

//////////UTILS//////////
void				error_exit(t_info *cub, char *msg);
void				exit_code(t_info *cub, int code);
int					clamp_int(int value, int min, int max);
void				free_map(t_map **map);
void				free_textures(t_info *cub);
void				free_tab(char **tab);
void				add_x(t_info *info, size_t i, int j);
int					v_or_x(t_info *info, char **map, size_t i, size_t j);

//////////LEGACY//////////
int					init_all(t_info *info);
int					key_info(int keycode, void *param);
void				reset_key(t_info *info);
void				is_w(t_info *info, t_player *player);
void				is_s(t_info *info, t_player *player);
void				is_a(t_info *info, t_player *player);
void				is_d(t_info *info, t_player *player);
void				is_esc(t_info *info);
void				handle_events(t_info *info);
void				free_all(t_info *info);
void				destroy_all(t_info *info);
void				fill_stash(t_info *info, char **av);
void				check_info(t_info *info, char *stash);
void				add_rgb(t_info *info, char **tmp, char c);
char				**parse_map(t_info *info);
int					find_longuest_line(char **map);
int					get_nb_lines(char **map);
int					only_white_spaces(char *str);
int					get_nb_players(t_info *info, char **map);
int					is_valid(t_info *info, char *str);
void				equal_line(t_info *info, char **map);
char				**add_tmp(t_info *info, char **tmp);
int					check_map_is_last(t_info *info, char **map);
void				set_up_final_map(t_info *info);
void				print_map(char **map);
int					put_color(t_info *info, char **tmp);
void				check_file(t_info *info, char **av);
int					init_mlx(t_mlx *mlx);
int					is_texture_line(char **stash);
int					is_texture(char *stash);
char				*recup_gnl(int fd);
int					close_window(t_info *info);
int					error(t_info *info, char *msg, int exit_code);
int					check_arg(char *msg, int exit_code);
int					move(t_info *info);
bool				ft_isspace(int c);
size_t				ft_strlenlen(char **tab);
int					check_is_closed(t_info *info, char **map);
void				check_double_comma(t_info *info, char *stash);
void				handle_movement(t_info *info);
int					is_player_char(char c);
#endif