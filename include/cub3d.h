/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rwassim <rwassim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 20:47:07 by oprosvir          #+#    #+#             */
/*   Updated: 2025/07/07 18:34:06 by rwassim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft.h"
# include "mlx.h"
# include <X11/keysym.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>

# define WIN_TITLE "cub3D"
# define WIN_WIDTH 1024
# define WIN_HEIGHT 768
# define MAX_MAP 70
# define MAX_TEX 800

# define MINIMAP_SCALE 8
# define DIR_LEN 10
# define MIN_SCALE 5
# define MAX_SCALE 12

# define MOVE_SPEED 0.015
# define ROT_SPEED 0.007
# define MOUSE_SENS 0.006
# define EPS 1e-6

# define BLACK 0x000000
# define WHITE 0xFFFFFF
# define DARK_GREY 0x333333
# define GREY 0xCCCCCC
# define RED 0xFF0000

typedef struct s_map_node
{
	char				*line;
	struct s_map_node	*next;
}						t_map_node;

typedef struct s_map
{
	int					width;
	int					height;
	char				**grid;
	char				*no_texture;
	char				*so_texture;
	char				*we_texture;
	char				*ea_texture;
	int					floor_rgb;
	int					ceiling_rgb;
	int					fd;
	t_map_node			*temp_list;
}						t_map;

typedef struct s_keys
{
	int					w;
	int					a;
	int					s;
	int					d;
	int					left;
	int					right;
	int					m_down;
	int					x_old;
}						t_keys;

typedef struct s_player
{
	double				pos_x;
	double				pos_y;
	double				dir_x;
	double				dir_y;
	double				plane_x;
	double				plane_y;
}						t_player;

typedef struct s_image
{
	void				*img;
	char				*addr;
	int					w;
	int					h;
	int					bpp;
	int					line_len;
	int					endian;
}						t_image;

typedef struct s_tex
{
	t_image				no;
	t_image				so;
	t_image				we;
	t_image				ea;
}						t_tex;

typedef struct s_ray
{
	double				dir_x;
	double				dir_y;
	int					map_x;
	int					map_y;
	double				s_dist_x;
	double				s_dist_y;
	double				d_dist_x;
	double				d_dist_y;
	int					step_x;
	int					step_y;
	int					side;
	int					hit;
	double				wall_dist;
}						t_ray;

typedef struct s_game
{
	void				*mlx;
	void				*win;
	int					minimap;
	int					map_scale;
	int					controls;
	t_image				image;
	t_player			player;
	t_keys				keys;
	t_map				map;
	t_ray				ray;
	t_tex				tex;
}						t_game;

// main, init & exit
void					load_textures(t_game *cub);
void					init_hooks(t_game *cub);
void					free_tab(char **tab);
void					free_map(t_map *m);
void					free_textures(t_game *cub);
void					error_exit(t_game *cub, const char *msg);
void					exit_code(t_game *cub, int code);
void					exit_failure(char *msg);
void					purge_gnl(int fd);
void					error_close_exit(t_game *cub, char *msg);

// map & config parser
void					parse_scene_file(char *file_name, t_game *cub);
int						is_config_line(char *trimmed);
void					save_map_to_grid(t_game *cub);
void					classify_line(char *line, t_game *cub, int *map_started,
							int *map_ended);
void					map_list_append(t_game *cub, char *line,
							t_map_node **head);
int						line_is_empty(char *line);
void					validate_map_lines(t_game *cub, t_map_node *head);
void					validate_tiles(t_game *cub);
int						is_config_line(char *s);
void					parse_config(char *line, t_game *cub);
int						parse_rgb_line(t_game *cub, char *line, int *dst);
void					save_map_to_grid(t_game *cub);

// render
void					set_player_direction(t_game *cub, char c);
void					render_frame(t_game *cub);
void					put_pixel(t_image *img, int x, int y, int color);
void					draw_minimap(t_game *cub);
int						mouse_press(int button, int x, int y, t_game *cub);
int						mouse_release(int button, int x, int y, t_game *cub);
int						mouse_move(int x, int y, t_game *cub);
void					rotate(t_player *p, double angle);
void					move_forward(t_game *cub);
void					move_backward(t_game *cub);
void					strafe_right(t_game *cub);
void					strafe_left(t_game *cub);
void					render_rays(t_game *cub);
void					draw_wall(t_game *cub, int x);
int						get_tex_y(int y, int line_h, int tex_h);
int						get_tex_x(t_ray *ray, t_image *wall, t_player *player);
int						clamp_int(int value, int min, int max);

// debug
void					print_data(const t_game *cub);
void					print_temp_list(t_map_node *map_lines);

#endif
