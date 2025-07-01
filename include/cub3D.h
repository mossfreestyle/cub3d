/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfernand <mfernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 18:18:04 by mfernand          #+#    #+#             */
/*   Updated: 2025/07/01 00:58:03 by mfernand         ###   ########.fr       */
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
	double *radius_buffer; // buffer qui contient toutes les tailles des rayons
	bool			in_map;
	bool			valid_map;
	bool			valid_assets;
	int				map_file;

}					t_info;

//////////INIT//////////
int					init_all(t_info *info);

int					key_info(int keycode, void *param);
///////IS_PRESSED//////////
void				is_w(t_info *info, t_player *player);
void				is_s(t_info *info, t_player *player);
void				is_a(t_info *info, t_player *player);
void				is_d(t_info *info, t_player *player);
void				is_esc(t_info *info);

///////UTILS////////////////
int					close_window(t_info *info);
int					error(t_info *info, char *msg, int exit_code);
int					check_arg(char *msg, int exit_code);

//////Handle events////////////
void				handle_events(t_info *info);

/////////CLOSE N DESTROY//////////
void				free_all(t_info *info);
void				destroy_all(t_info *info);

///////PARSING///////////////
void				fill_stash(t_info *info, char **av);
void				check_info(t_info *info, char *stash);
char				*check_valid_path(t_info *info, char *stash);
void				add_rgb(t_info *info, char **tmp, char c);
int					check_valid_rgb(t_info *info, char c);
#endif