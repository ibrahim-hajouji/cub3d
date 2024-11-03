/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajouji <ihajouji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 13:39:41 by ihaffout          #+#    #+#             */
/*   Updated: 2024/11/03 01:04:45 by ihajouji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../cub.h"

t_parser	*init_parser(void)
{
	t_parser	*parser;

	parser = malloc(sizeof(t_parser));
	if (!parser)
		return (write(2, "Error\nMalloc failed\n", 20), NULL);
	parser->no = NULL;
	parser->so = NULL;
	parser->we = NULL;
	parser->ea = NULL;
	parser->c = NULL;
	parser->f = NULL;
	parser->map = NULL;
	return (parser);
}

t_player_off	*init_player_off(void)
{
	t_player_off	*player_off;

	player_off = malloc(sizeof(t_player_off));
	if (!player_off)
		(write(2, "Error\nMalloc failed\n", 20), exit(1));
	player_off->player_img_1 = mlx_load_png("./_textures/player_off/1.png");
	player_off->player_img_2 = mlx_load_png("./_textures/player_off/2.png");
	player_off->player_img_3 = mlx_load_png("./_textures/player_off/3.png");
	player_off->player_img_4 = mlx_load_png("./_textures/player_off/4.png");
	player_off->animation = 0;
	if (!player_off->player_img_1 || !player_off->player_img_2
		|| !player_off->player_img_3 || !player_off->player_img_4)
		exit(1);
	return (player_off);
}

t_light_off	*init_light_off(void)
{
	t_light_off	*light_off;

	light_off = malloc(sizeof(t_light_off));
	if (!light_off)
		(write(2, "Error\nMalloc failed\n", 20), exit(1));
	light_off->light_off_1 = mlx_load_png("./_textures/light_off/1.png");
	light_off->light_off_2 = mlx_load_png("./_textures/light_off/2.png");
	light_off->light_off_3 = mlx_load_png("./_textures/light_off/3.png");
	light_off->ghost_1 = mlx_load_png("./_textures/ghost.png");
	light_off->animation = 0;
	light_off->animation_ghost = 0;
	if (!light_off->light_off_1 || !light_off->light_off_2
		|| !light_off->light_off_3 || !light_off->ghost_1)
		exit(1);
	return (light_off);
}

t_player	*init_player(void)
{
	t_player	*player;

	player = malloc(sizeof(t_player));
	if (!player)
		(write(2, "Error\nMalloc failed\n", 20), exit(1));
	player->x_start = WINDOW_WIDTH / 2;
	player->y_start = WINDOW_HEIGHT - 1;
	player->player_texture_x = 0;
	player->player_texture_y = 0;
	player->player_img_1 = mlx_load_png("./_textures/player/player_1.png");
	player->player_img_2 = mlx_load_png("./_textures/player/player_2.png");
	player->player_img_3 = mlx_load_png("./_textures/player/player_3.png");
	player->player_img_4 = mlx_load_png("./_textures/player/player_4.png");
	player->player_img_5 = mlx_load_png("./_textures/player/player_5.png");
	if (!player->player_img_1 || !player->player_img_2 || !player->player_img_3
		|| !player->player_img_4 || !player->player_img_5)
		exit(1);
	player->animation = 0;
	return (player);
}

t_data	*init_data(t_parser *parser)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (write(2, "Error\nMalloc failed\n", 20), NULL);
	data->light = 2;
	data->size_x = get_the_len(parser->map, 1);
	data->size_y = get_the_len(parser->map, 0);
	data->xp = (parser->x_player * SQUARE) + (SQUARE / 2);
	data->yp = (parser->y_player * SQUARE) + (SQUARE / 2);
	data->parser = parser;
	if (parser->player_dir == 'N')
		data->player_rotation_angle = 270 * (M_PI / 180);
	if (parser->player_dir == 'S')
		data->player_rotation_angle = 90 * (M_PI / 180);
	if (parser->player_dir == 'W')
		data->player_rotation_angle = 180 * (M_PI / 180);
	if (parser->player_dir == 'E')
		data->player_rotation_angle = 0 * (M_PI / 180);
	data->last_mouse_x = 0;
	data->door_x = 0;
	data->door_y = 0;
	data->intro_animation = 0;
	return (data);
}
