/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajouji <ihajouji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 10:58:16 by ihaffout          #+#    #+#             */
/*   Updated: 2024/10/30 22:20:33 by ihajouji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../cub.h"

void	draw_doors_to_image(t_data *data, t_rays *rays, int x)
{
	int		color;
	float	current_pixel;

	calculate_wall_height(data, rays);
	if (rays->direction == 'D')
		data->textures->img = data->textures->door_img;
	get_texture_x(data, rays);
	current_pixel = data->textures->wall_start;
	while (current_pixel < data->textures->wall_end)
	{
		get_texture_y(data, current_pixel);
		if (current_pixel >= 0 && current_pixel < WINDOW_HEIGHT)
		{
			color = get_color_of_texture(data->textures->texture_x,
					data->textures->texture_y,
					data->textures->img);
			if (color != 0 && current_pixel > 0
				&& current_pixel < WINDOW_HEIGHT)
				mlx_put_pixel(data->mlx->mlx_img, x, current_pixel, color);
		}
		current_pixel++;
	}
}

void	draw_ceiling_floor(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < WINDOW_HEIGHT / 2)
	{
		j = 0;
		while (j < WINDOW_WIDTH)
		{
			mlx_put_pixel(data->mlx->mlx_img, j, i, data->mlx->cc);
			j++;
		}
		i++;
	}
	while (i < WINDOW_HEIGHT)
	{
		j = 0;
		while (j < WINDOW_WIDTH)
		{
			mlx_put_pixel(data->mlx->mlx_img, j, i, data->mlx->fc);
			j++;
		}
		i++;
	}
}

void	draw_player_to_image(t_data *data, mlx_texture_t *player_img)
{
	int	x_start;
	int	y_start;

	get_player_drawing_info(player_img, &x_start, &y_start);
	draw_player_image(data, player_img, x_start, y_start);
}

void	draw_ray_to_image(t_data *data, t_rays *rays, int x)
{
	int		color;
	float	current_pixel;

	calculate_wall_height(data, rays);
	detect_texture(data, rays);
	get_texture_x(data, rays);
	current_pixel = data->textures->wall_start;
	while (current_pixel < data->textures->wall_end)
	{
		get_texture_y(data, current_pixel);
		if (current_pixel >= 0 && current_pixel < WINDOW_HEIGHT)
		{
			color = get_color_of_texture(data->textures->texture_x,
					data->textures->texture_y,
					data->textures->img);
			if (current_pixel > 0 && current_pixel < WINDOW_HEIGHT)
				mlx_put_pixel(data->mlx->mlx_img, x, current_pixel, color);
		}
		current_pixel++;
	}
}
