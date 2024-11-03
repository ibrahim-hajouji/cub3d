/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihaffout <ihaffout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 10:44:47 by ihaffout          #+#    #+#             */
/*   Updated: 2024/10/22 15:02:13 by ihaffout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../cub.h"

void	detect_texture(t_data *data, t_rays *rays)
{
	if (rays->direction == 'N')
		data->textures->img = data->textures->north_img;
	if (rays->direction == 'S')
		data->textures->img = data->textures->south_img;
	if (rays->direction == 'W')
		data->textures->img = data->textures->west_img;
	if (rays->direction == 'E')
		data->textures->img = data->textures->east_img;
}

int	get_color(int color)
{
	return (color << 8 | 255);
}

int	get_rgba(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

void	get_player_drawing_info(mlx_texture_t *player_img, int *x_start,
		int *y_start)
{
	int	player_image_width;
	int	player_image_height;

	player_image_width = player_img->width;
	player_image_height = player_img->height;
	if (player_image_width > WINDOW_WIDTH
		|| player_image_height > WINDOW_HEIGHT)
		exit(1);
	*x_start = (WINDOW_WIDTH / 2) - (player_image_width / 2);
	*y_start = WINDOW_HEIGHT - player_image_height;
}

void	draw_player_image(t_data *data, mlx_texture_t *player_img, int x_start,
		int y_start)
{
	int	y;
	int	x;
	int	player_image_width;
	int	player_image_height;

	player_image_width = player_img->width;
	player_image_height = player_img->height;
	y = 0;
	while (y++ < player_image_height)
	{
		x = 0;
		if (y_start + y >= 0 && y_start + y < WINDOW_HEIGHT)
		{
			while (x++ < player_image_width)
			{
				if (x_start + x >= 0 && x_start + x < WINDOW_WIDTH)
				{
					if (get_color_of_texture(x, y, player_img) != 0)
						mlx_put_pixel(data->mlx->mlx_img, x_start + x, y_start
							+ y, get_color_of_texture(x, y, player_img));
				}
			}
		}
	}
}
