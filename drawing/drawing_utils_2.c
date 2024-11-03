/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_utils_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajouji <ihajouji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 14:30:04 by ihaffout          #+#    #+#             */
/*   Updated: 2024/10/30 22:21:23 by ihajouji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../cub.h"

void	calculate_wall_height(t_data *data, t_rays *rays)
{
	float	half_height;
	float	real_distance;
	float	half_real_distance;

	half_height = WINDOW_HEIGHT / 2;
	real_distance = WINDOW_HEIGHT / rays->distance * 32;
	half_real_distance = real_distance / 2;
	data->textures->wall_height = real_distance;
	data->textures->wall_start = half_height - half_real_distance;
	data->textures->wall_end = half_height + half_real_distance;
}

void	get_texture_x(t_data *data, t_rays *rays)
{
	if (rays->wall_hit)
	{
		if (rays->wall_hit_x >= 0 && rays->wall_hit_x < data->size_x * SQUARE)
			data->textures->texture_x = fmod(rays->wall_hit_y, SQUARE)
				* data->textures->img->width / SQUARE;
	}
	else
	{
		if (rays->wall_hit_y >= 0 && rays->wall_hit_y < data->size_y * SQUARE)
			data->textures->texture_x = fmod(rays->wall_hit_x, SQUARE)
				* data->textures->img->width / SQUARE;
	}
}

void	get_texture_y(t_data *data, float current_pixel)
{
	data->textures->texture_y = (current_pixel - data->textures->wall_start)
		* data->textures->img->height / data->textures->wall_height;
}

int	get_color_of_texture(int x, int y, mlx_texture_t *image)
{
	int	index;
	int	max;

	max = image->height * image->width * image->bytes_per_pixel;
	index = ((y * image->width) + x) * image->bytes_per_pixel;
	if (index >= max)
		return (0);
	return (get_rgba(
			image->pixels[index + 0],
			image->pixels[index + 1],
			image->pixels[index + 2],
			image->pixels[index + 3]));
}
