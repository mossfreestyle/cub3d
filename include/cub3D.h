/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfernand <mfernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/28 18:18:04 by mfernand          #+#    #+#             */
/*   Updated: 2025/06/28 23:43:32 by mfernand         ###   ########.fr       */
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
	int				ceiling_color;
	int				floor_color;
	void			*no;
	void			*so;
	void			*we;
	void			*ea;
}					t_assets;

//////////MAP//////////////

typedef struct s_map
{
	char **stash; // mettre tout le file ici
	char **map;   // map final bien parse
	char			player_dir;
	int				x_max;
	int				y_max;
	bool			closed;
	int				distance_to_wall;
	int				nb_players;
	int				x_spawn;
	int				y_spawn;

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
	bool			valid_map;
	bool			valid_assets;
	char			*map_file;

}					t_info;

//////////INIT//////////
void				init_info(t_info *info);

int					key_info(t_info *info, int keycode);
///////IS_PRESSED//////////
void				is_w(t_info *info, t_player *player);
void				is_s(t_info *info, t_player *player);
void				is_a(t_info *info, t_player *player);
void				is_d(t_info *info, t_player *player);
void				is_esc(t_info *info, t_player *player);

///////UTILS////////////////
int					close_window(t_info *info);
int					error(t_info *info, char *msg, int exit_code);
int					check_arg(char *msg, int exit_code);

//////Handle events////////////
void				handle_events(t_info *info);
# endif
#endif