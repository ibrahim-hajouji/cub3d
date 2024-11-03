/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajouji <ihajouji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 13:18:06 by ihaffout          #+#    #+#             */
/*   Updated: 2024/11/03 01:26:51 by ihajouji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	moves(t_data *data)
{
	if (mlx_is_key_down(data->mlx->mlx_ptr, MLX_KEY_W))
		move_forward(data);
	if (mlx_is_key_down(data->mlx->mlx_ptr, MLX_KEY_S))
		move_backward(data);
	if (mlx_is_key_down(data->mlx->mlx_ptr, MLX_KEY_A))
		move_left(data);
	if (mlx_is_key_down(data->mlx->mlx_ptr, MLX_KEY_D))
		move_right(data);
}

void	rotations(t_data *data)
{
	if (mlx_is_key_down(data->mlx->mlx_ptr, MLX_KEY_LEFT))
		look_left(data);
	if (mlx_is_key_down(data->mlx->mlx_ptr, MLX_KEY_RIGHT))
		look_right(data);
}

void	update_position(void *param)
{
	t_data		*data;
	static int	door_pressed;
	static int	space_pressed;

	data = param;
	intro(data);
	if (mlx_is_key_down(data->mlx->mlx_ptr, MLX_KEY_ESCAPE))
		end_game(data);
	if (data->light == 2 || data->light == 3)
		return ;
	handle_mouse_rotation(data);
	_display(data);
	minimap(data);
	moves(data);
	rotations(data);
	if (mlx_is_key_down(data->mlx->mlx_ptr, MLX_KEY_SPACE) && !space_pressed)
		dark_mode(data, &space_pressed);
	else if (!mlx_is_key_down(data->mlx->mlx_ptr, MLX_KEY_SPACE))
		space_pressed = 0;
	if (mlx_is_mouse_down(data->mlx->mlx_ptr, MLX_MOUSE_BUTTON_LEFT)
		&& !door_pressed)
		mouse_click(data, &door_pressed);
	else if (!mlx_is_mouse_down(data->mlx->mlx_ptr, MLX_MOUSE_BUTTON_LEFT))
		door_pressed = 0;
}

int	main(int ac, char **av)
{
	char		**content;
	t_data		*data;
	t_parser	*parser;

	if (ac != 2)
		return (write(2, "Error\nInvalid args\n", 19), 1);
	content = get_content(av[1]);
	parser = init_parser();
	if (!parser)
		return (ft_free(content), 1);
	check_valid(content, parser);
	data = init_data(parser);
	if (!data)
		return (ft_free(content), free_all(parser), 1);
	data->textures = init_textures(data);
	data->player = init_player();
	data->player_off = init_player_off();
	data->light_off = init_light_off();
	data->mlx = init_mlx(data);
	if (!data->mlx)
		return (ft_free(content), free_all(parser), free(data), 1);
	init_img(data);
	mlx_loop_hook(data->mlx->mlx_ptr, update_position, data);
	mlx_loop(data->mlx->mlx_ptr);
	return (0);
}
