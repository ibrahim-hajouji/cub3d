/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajouji <ihajouji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/11 10:41:26 by ihajouji          #+#    #+#             */
/*   Updated: 2024/10/31 18:55:27 by ihajouji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../cub.h"

void	fill_minimap(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	set_shifts(data);
	while (i < data->nmbr_of_lines)
	{
		j = 0;
		data->minimap[i] = malloc(sizeof(char) * (data->nmbr_of_columns + 1));
		if (!data->minimap[i])
			(write(2, "Error\nMalloc failed\n", 20), end_game(data));
		if (is_out_of_horizontal_bounds(data, &i, &j))
			continue ;
		while (j < data->nmbr_of_columns)
		{
			fill_index(data, i, j);
			j++;
		}
		data->minimap[i][j] = '\0';
		i++;
	}
	data->minimap[i] = NULL;
}

void	render_rays(t_data *data)
{
	float	ray_angle;
	int		i;

	i = 0;
	ray_angle = data->player_rotation_angle - (FOV_ANGLE / 2);
	while (i < 160)
	{
		draw_ray(ray_angle, data);
		ray_angle += FOV_ANGLE / 160;
		i++;
	}
}

void	draw_minimap(t_data *data)
{
	int	x;
	int	y;

	data->minimap_y_start = data->minimap_yp - PLAYER_MINIMAP_Y;
	data->minimap_x_start = data->minimap_xp - PLAYER_MINIMAP_X;
	y = 0;
	while (y < 160)
	{
		x = 0;
		while (x < 288)
		{
			draw_pixel(data, x, y);
			x++;
		}
		y++;
	}
}

void	draw_border(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y <= 160)
	{
		x = 0;
		while (x < 288)
		{
			if (y <= 1 || y >= 158 || x <= 1 || x >= 286)
			{
				mlx_put_pixel(data->mlx->mlx_img, x + 10, y + 10,
					get_color(PLAYER_C));
			}
			x++;
		}
		y++;
	}
}

void	minimap(t_data *data)
{
	data->nmbr_of_columns = 12;
	data->nmbr_of_lines = 8;
	data->minimap = malloc(sizeof(char *) * data->nmbr_of_lines + 1);
	if (!data->minimap)
		(write(2, "Error\nMalloc failed\n", 20), end_game(data));
	fill_minimap(data);
	draw_minimap(data);
	render_rays(data);
	redraw_player_border(data);
	ft_free(data->minimap);
}
