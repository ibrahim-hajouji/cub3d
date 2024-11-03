/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajouji <ihajouji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 13:14:17 by ihajouji          #+#    #+#             */
/*   Updated: 2024/10/28 15:26:40 by ihajouji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../cub.h"

void	candle_on(t_data *data)
{
	if (data->player->animation <= 1)
		draw_player_to_image(data, data->player->player_img_1);
	else if (data->player->animation <= 2)
		draw_player_to_image(data, data->player->player_img_2);
	else if (data->player->animation <= 3)
		draw_player_to_image(data, data->player->player_img_3);
	else if (data->player->animation <= 4)
		draw_player_to_image(data, data->player->player_img_4);
	else if (data->player->animation <= 5)
	{
		draw_player_to_image(data, data->player->player_img_5);
		if (data->player->animation == 5)
			data->player->animation = 0;
	}
	data->player->animation += 0.5;
}

void	candle_off(t_data *data)
{
	if (data->player_off->animation <= 1)
	{
		draw_player_to_image(data, data->player_off->player_img_1);
		data->player_off->animation += 0.5;
	}
	else if (data->player_off->animation <= 2)
	{
		draw_player_to_image(data, data->player_off->player_img_2);
		data->player_off->animation += 0.5;
	}
	else if (data->player_off->animation <= 3)
	{
		draw_player_to_image(data, data->player_off->player_img_3);
		data->player_off->animation += 0.5;
	}
	else if (data->player_off->animation <= 4)
		draw_player_to_image(data, data->player_off->player_img_4);
}

void	animate_player(t_data *data, int light)
{
	if (light)
		candle_on(data);
	else
		candle_off(data);
}

void	draw_img(mlx_texture_t *img, t_data *data)
{
	int	x;
	int	y;

	x = 0;
	while (x < WINDOW_WIDTH)
	{
		y = 0;
		while (y < WINDOW_HEIGHT)
		{
			mlx_put_pixel(data->mlx->mlx_img, x, y, get_color_of_texture(x, y,
					img));
			y++;
		}
		x++;
	}
}

void	animate_background(t_data *data)
{
	if (data->light_off->animation <= 4)
		draw_img(data->light_off->light_off_1, data);
	else if (data->light_off->animation <= 8)
		draw_img(data->light_off->light_off_2, data);
	else if (data->light_off->animation <= 12)
	{
		draw_img(data->light_off->light_off_3, data);
		if (data->light_off->animation == 12)
			data->light_off->animation = 0;
	}
	data->light_off->animation += 0.5;
}
