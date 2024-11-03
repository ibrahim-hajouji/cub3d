/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajouji <ihajouji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 13:18:50 by ihaffout          #+#    #+#             */
/*   Updated: 2024/11/03 01:05:51 by ihajouji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include "./MLX42/include/MLX42/MLX42.h"
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define FOV_ANGLE 1.047197551 // (60 * (M_PI / 180))
# define WINDOW_WIDTH 1920
# define WINDOW_HEIGHT 1080
# define NUM_RAYS 1920
# define SQUARE 32
# define RED 0xFF0000
# define PATH_C 0xC2B2Cb
# define WALL_C 0x411E5D
# define _X 0x2A1434
# define BLUE 0x0000FF
# define YELLOW 0xFFFF00
# define PLAYER_C 0xDC7D10
# define ORANGE 0x819F32
# define RAYS_COLOR 0xFFE7C7
# define MINIMAP_WIDTH 288
# define MINIMAP_HEIGHT 160
# define EPSILON 0.0001
# define PLAYER_MINIMAP_X 144
# define PLAYER_MINIMAP_Y 80

typedef struct s_door
{
	int				x;
	int				y;
	int				open;

}					t_door;

typedef struct s_parser
{
	char			*no;
	char			*so;
	char			*we;
	char			*ea;
	char			*f;
	char			*c;
	char			**map;
	int				x_player;
	int				y_player;
	char			player_dir;
	int				d_count;
	t_door			*doors;
}					t_parser;

typedef struct s_player
{
	float			x_start;
	float			y_start;
	float			player_texture_x;
	float			player_texture_y;
	mlx_texture_t	*player_img_1;
	mlx_texture_t	*player_img_2;
	mlx_texture_t	*player_img_3;
	mlx_texture_t	*player_img_4;
	mlx_texture_t	*player_img_5;
	float			animation;

}					t_player;

typedef struct s_player_off
{
	float			x_start;
	float			y_start;
	float			player_texture_x;
	float			player_texture_y;
	mlx_texture_t	*player_img_1;
	mlx_texture_t	*player_img_2;
	mlx_texture_t	*player_img_3;
	mlx_texture_t	*player_img_4;
	float			animation;

}					t_player_off;

typedef struct s_light_off
{
	mlx_texture_t	*light_off_1;
	mlx_texture_t	*light_off_2;
	mlx_texture_t	*light_off_3;
	mlx_texture_t	*ghost_1;
	float			animation;
	float			animation_ghost;
}					t_light_off;

typedef struct s_rays
{
	float			ray_angle;
	float			dx;
	float			dy;
	float			x_intercept_v;
	float			y_intercept_v;
	float			x_intercept_h;
	float			y_intercept_h;
	float			x_door_v;
	float			y_door_v;
	float			x_door_h;
	float			y_door_h;
	float			wall_hit_x;
	float			wall_hit_y;
	float			wall_hit_x_h;
	float			wall_hit_y_h;
	float			wall_hit_x_v;
	float			wall_hit_y_v;
	float			distance;
	float			distance_h;
	float			distance_v;
	int				is_ray_facing_down;
	int				is_ray_facing_up;
	int				is_ray_facing_right;
	int				is_ray_facing_left;
	char			direction;
	int				wall_hit;
}					t_rays;

typedef struct s_textures
{
	mlx_texture_t	*door_img;
	mlx_texture_t	*north_img;
	mlx_texture_t	*south_img;
	mlx_texture_t	*west_img;
	mlx_texture_t	*east_img;
	mlx_texture_t	*img;
	int				texture_x;
	int				texture_y;
	float			wall_height;
	float			wall_start;
	float			wall_end;

}					t_textures;

typedef struct s_mlx
{
	void			*mlx_ptr;
	void			*mlx_img;
	int				fc;
	int				cc;

}					t_mlx;

typedef struct s_data
{
	int				light;
	int				size_x;
	int				size_y;
	float			xp;
	float			yp;
	float			player_rotation_angle;
	char			**minimap;
	float			minimap_xp;
	float			minimap_yp;
	int				minimap_x_start;
	int				minimap_y_start;
	int				shift_x;
	int				shift_y;
	int				door_x;
	int				door_y;
	int				nmbr_of_lines;
	int				nmbr_of_columns;
	int				last_mouse_x;
	float			intro_animation;
	mlx_texture_t	*intro1;
	mlx_texture_t	*intro2;
	mlx_texture_t	*controllers;
	t_parser		*parser;
	t_textures		*textures;
	t_player		*player;
	t_player_off	*player_off;
	t_light_off		*light_off;
	t_mlx			*mlx;
}					t_data;

t_textures			*init_textures(t_data *data);
int					is_closed(int x, int y, t_data *data);
void				draw_img(mlx_texture_t *img, t_data *data);
void				set_shifts(t_data *data);
int					is_out_of_horizontal_bounds(t_data *data, int *i, int *j);
void				fill_index(t_data *data, int i, int j);
void				draw_ray(float ray_angle, t_data *data);
void				draw_pixel(t_data *data, int x, int y);
int					is_closed(int x, int y, t_data *data);
void				draw_border(t_data *data);
void				redraw_player_border(t_data *data);
int					locked(t_data *data, int new_x, int new_y);
int					can_move(t_data *data, int new_x, int new_y);
void				handle_ceiling(char **content, t_parser *parser, int i,
						int j);
void				handle_floor(char **content, t_parser *parser, int i,
						int j);
void				handle_west(char **content, t_parser *parser, int i, int j);
void				handle_east(char **content, t_parser *parser, int i, int j);
void				handle_south(char **content, t_parser *parser, int i,
						int j);
void				handle_north(char **content, t_parser *parser, int i,
						int j);
int					inv_char(char **map, t_parser *parser);
int					surrounded_by_walls(char **str, int len);
int					check_spaces(char **map, int len);
int					check_path(char **map, int x_player, int y_player, int len);
int					check_doors(t_parser *parser, t_door *doors);
void				fill_map(char **content, t_parser *parser, int map_start);
int					missing_detail(t_parser *parser);
int					skip_space(char *str);
int					valid_details(t_parser *parser);
int					is_valid_color_component(char *str);
char				**get_content(char *name);
int					file_len(char *name);
void				check_name(char *name);
int					skip_spaces(char *str, int i);
void				ft_err(char *str, t_parser *parser);
void				set_shifts(t_data *data);
void				end_game(t_data *data);
void				scene(t_data *data, int option);
void				dark_mode(t_data *data, int *space_pressed);
void				mouse_click(t_data *data, int *door_pressed);
void				handle_mouse_rotation(t_data *data);
void				look_right(t_data *data);
void				look_left(t_data *data);
void				animate_background(t_data *data);
void				animate_player(t_data *data, int light);
void				_display(t_data *data);
void				init_img(t_data *data);
void				intro(t_data *data);
int					end_of_map(char **content, int i);

// _____________________________ PARSING ______________________________//
//CHECKING FUNCTIONS:
char				**get_content(char *name);
void				check_valid(char **content, t_parser *parser);

// _____________________________ INIT ______________________________//
t_parser			*init_parser(void);
t_data				*init_data(t_parser *parser);
t_mlx				*init_mlx(t_data *data);
t_player			*init_player(void);
t_light_off			*init_light_off(void);
t_player_off		*init_player_off(void);

// _____________________________MINIMAP ______________________________//
void				minimap(t_data *data);

// _____________________________ MOVES ______________________________//
void				move_left(t_data *data);
void				move_right(t_data *data);
void				move_forward(t_data *data);
void				move_backward(t_data *data);
int					is_player(char c);

// _____________________________ RAY-CASTING ______________________________//
void				cast_rays_walls(t_data *data);
void				horizontal_intersections(t_data *data, t_rays *rays);
void				vertical_intersections(t_data *data, t_rays *rays);
void				doors_h_intersections(t_data *data, t_rays *rays);
void				doors_v_intersections(t_data *data, t_rays *rays);
int					is_door_v(float x, float y, t_data *data, t_rays *rays);
int					is_door_h(float x, float y, t_data *data, t_rays *rays);

// _____________________________ DRAWING ______________________________//
int					get_color(int color);
int					get_rgba(int r, int g, int b, int a);
int					get_color_of_texture(int x, int y, mlx_texture_t *image);
void				cast_rays_doors(t_data *data);
void				draw_doors_to_image(t_data *data, t_rays *rays, int x);
void				get_player_drawing_info(mlx_texture_t *player_img,
						int *x_start,
						int *y_start);
void				draw_player_image(t_data *data, mlx_texture_t *player_img,
						int x_start, int y_start);
void				draw_player_to_image(t_data *data,
						mlx_texture_t *player_img);
void				draw_ceiling_floor(t_data *data);
void				draw_ray_to_image(t_data *data, t_rays *rays, int x);
void				calculate_wall_height(t_data *data, t_rays *rays);
void				get_texture_x(t_data *data, t_rays *rays);
void				get_texture_y(t_data *data, float current_pixel);
void				detect_texture(t_data *data, t_rays *rays);

// _____________________________ UTILS ______________________________//
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

float				normalize_angle(float angle);
void				ft_free(char **str);
void				free_all(t_parser *parser);
int					is_player(char c);
int					get_the_len(char **str, int x);
int					ft_atoi(char *str);
char				**ft_split(char *s, char c);
int					ft_strlen(const char *s);
int					is_space(char c);
char				*ft_strnstr(const char *haystack, const char *needle,
						size_t len);
char				*ft_strdup(char *s1);
int					ft_strcmp(char *s1, char *s2);
char				*_free(char *buffer);
char				*ft_strchr(const char *s, int c);
char				*ft_strjoin(char const *s1, char const *s2);
char				*get_next_line(int fd);
void				ft_bzero(void *s, size_t n);

#endif