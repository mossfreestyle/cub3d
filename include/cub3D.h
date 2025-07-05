/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfernand <mfernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 18:18:04 by mfernand          #+#    #+#             */
/*   Updated: 2025/07/05 13:41:33 by mfernand         ###   ########.fr       */
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
# include <stdbool.h>

# ifndef ERROR_MSG
#  define ERROR_MSG "Error\n"
# endif

# ifndef WIDTH_DISPLAY
#  define WIDTH_DISPLAY 2560
# endif

# ifndef HEIGHT_DISPLAY
#  define HEIGHT_DISPLAY 1440
# endif

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
	int				turn_left;
	int				turn_right;
	int				esc;
	bool			press_w;
	bool			press_s;
	bool			press_a;
	bool			press_d;
	bool			press_turn_left;
	bool			press_turn_right;

}					t_key;
//////////////ASSETS/////////////////////

typedef struct s_assets
{
	char			*path_no;
	char			*path_so;
	char			*path_we;
	char			*path_ea;
	int				ceiling_color[3];
	int				floor_color[3];
	bool			c_color;
	bool			f_color;
	bool			valid_cardinals;
	void			*no;
	void			*so;
	void			*we;
	void			*ea;
}					t_assets;

//////////MAP//////////////

typedef struct s_map
{
	char **stash;     // mettre tout le file ici
	char **final_map; // map final bien parse
	char **first_map; // map sans les texture et rgb
	char			player_dir;
	int				x_max;
	int				y_max;
	bool			closed;
	int				distance_to_wall;
	int				nb_players;
	int				nb_lines;
	int				x_spawn;
	int				y_spawn;
	int				line_max;

}					t_map;

///////////MLX//////////////
typedef struct m_mlx
{
	void			*mlx;
	void			*window;
	void			*img;
	int				width;
	int				height;
	char			*adr;
	int bpp; // bit par pixels
	int				size_line;
	int				endian;
}					t_mlx;

typedef struct s_info
{
	t_player		*player;
	t_map			*map_info;
	t_assets		*assets;
	t_mlx			*mlx;
	t_key			*key;
	// t_ray			*ray;
	double *radius_buffer; // buffer qui contient toutes les tailles des rayons
	bool			in_map;
	bool			valid_map;
	bool			valid_assets;
	bool			map_copied;
	int				map_file;

}					t_info;

// typedef struct s_ray
// {
// 	double			dir_x;
// 	double			dir_y;
// 	int				map_x;
// 	int				map_y;
// 	double			s_dist_x;
// 	double			s_dist_y;
// 	double			d_dist_x;
// 	double			d_dist_y;
// 	int				step_x;
// 	int				step_y;
// 	int				side;
// 	int				hit;
// 	double			wall_dist;
// }					t_ray;

//////////INIT//////////
int					init_all(t_info *info);

//////////KEY//////////
int					key_info(int keycode, void *param);
void				reset_key(t_info *info);

///////IS_PRESSED//////////
void				is_w(t_info *info, t_player *player);
void				is_s(t_info *info, t_player *player);
void				is_a(t_info *info, t_player *player);
void				is_d(t_info *info, t_player *player);
void				is_esc(t_info *info);

//////Handle events////////////
void				handle_events(t_info *info);

/////////CLOSE N DESTROY//////////
void				free_all(t_info *info);
void				destroy_all(t_info *info);

///////PARSING///////////////
void				fill_stash(t_info *info, char **av);
void				check_info(t_info *info, char *stash);
void				add_rgb(t_info *info, char **tmp, char c);
char				**parse_map(t_info *info);
int					find_longuest_line(char **map);
int					get_nb_lines(char **map);
int					only_white_spaces(char *str);
int					get_nb_players(t_info *info, char **map);
int					is_valid(t_info *info, char *str);
char				*equal_line(char *src, int limit);
char				**add_tmp(t_info *info, char **tmp);
int					check_map_is_last(t_info *info, char **map);
void				set_up_final_map(t_info *info);
void				print_map(char **map);
int					put_color(t_info *info, char **tmp);

///////UTILS////////////////
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

#endif