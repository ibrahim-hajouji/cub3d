/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajouji <ihajouji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 15:49:21 by ihajouji          #+#    #+#             */
/*   Updated: 2024/11/03 01:26:29 by ihajouji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	_display(t_data *data)
{
	if (data->light == 1)
		scene(data, 0);
	else if (data->light == 0)
		scene(data, 1);
}

void	init_img(t_data *data)
{
	data->intro1 = mlx_load_png("./_textures/intro1.png");
	data->intro2 = mlx_load_png("./_textures/intro2.png");
	data->controllers = mlx_load_png("./_textures/controllers.png");
	if (!data->intro1 || !data->intro2 || !data->controllers)
		end_game(data);
}

void	controllers(t_data *data, int *enter_pressed)
{
	if (mlx_is_key_down(data->mlx->mlx_ptr, MLX_KEY_ENTER) && !*enter_pressed)
	{
		data->light = 1;
		*enter_pressed = 1;
	}
	else if (!mlx_is_key_down(data->mlx->mlx_ptr, MLX_KEY_ENTER))
	{
		*enter_pressed = 0;
		draw_img(data->controllers, data);
	}
}

void	welcome(t_data *data, int *enter_pressed)
{
	if (mlx_is_key_down(data->mlx->mlx_ptr, MLX_KEY_ENTER))
	{
		data->light = 3;
		*enter_pressed = 1;
	}
	else
	{
		*enter_pressed = 0;
		if (data->intro_animation <= 1)
			draw_img(data->intro1, data);
		else if (data->intro_animation <= 2)
		{
			draw_img(data->intro2, data);
			if (data->intro_animation == 2)
				data->intro_animation = 0;
		}
		data->intro_animation += 0.125;
	}
}

void	intro(t_data *data)
{
	static int	enter_pressed;

	if (data->light == 2)
		welcome(data, &enter_pressed);
	else if (data->light == 3)
		controllers(data, &enter_pressed);
	else
		return ;
}
