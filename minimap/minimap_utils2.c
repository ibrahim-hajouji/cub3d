/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajouji <ihajouji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 13:22:21 by ihajouji          #+#    #+#             */
/*   Updated: 2024/10/28 12:30:56 by ihajouji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../cub.h"

int	draw(t_data *data, float ray_x, float ray_y, int *hit)
{
	int	map_x;
	int	map_y;

	map_x = (data->minimap_xp - 144 + (int)ray_x) / 32;
	map_y = (data->minimap_yp - 80 + (int)ray_y) / 32;
	if (map_x < 0 || map_y < 0 || map_x >= data->nmbr_of_columns
		|| map_y >= data->nmbr_of_lines || !data->minimap[map_y])
	{
		*hit = 1;
		return (1);
	}
	if (data->minimap[map_y][map_x] == '1'
		|| data->minimap[map_y][map_x] == 'D')
	{
		*hit = 1;
		return (1);
	}
	else
		mlx_put_pixel(data->mlx->mlx_img, ray_x + 10, ray_y + 10,
			get_color(RAYS_COLOR));
	return (0);
}

void	draw_ray(float ray_angle, t_data *data)
{
	float	ray_x;
	float	ray_y;
	float	ray_dir_x;
	float	ray_dir_y;
	int		hit;

	ray_x = 144;
	ray_y = 80;
	ray_dir_x = cos(ray_angle);
	ray_dir_y = sin(ray_angle);
	hit = 0;
	while (!hit)
	{
		ray_x += ray_dir_x * 0.01;
		ray_y += ray_dir_y * 0.01;
		if (ray_x < 0 || ray_x >= 288 || ray_y < 0 || ray_y >= 160)
		{
			hit = 1;
			break ;
		}
		if (draw(data, ray_x, ray_y, &hit))
			break ;
	}
}

void	redraw_player_border(t_data *data)
{
	int	x;
	int	y;
	int	player_minimap_x;
	int	player_minimap_y;

	player_minimap_x = 144;
	player_minimap_y = 80;
	y = player_minimap_y - 4;
	while (y < player_minimap_y + 4)
	{
		x = player_minimap_x - 4;
		while (x < player_minimap_x + 4)
		{
			mlx_put_pixel(data->mlx->mlx_img, x + 10, y + 10,
				get_color(PLAYER_C));
			x++;
		}
		y++;
	}
	draw_border(data);
}

void	set_shifts(t_data *data)
{
	if ((int)data->xp % 32 < 16)
		data->shift_x = -1;
	else if ((int)data->xp % 32 > 16)
		data->shift_x = 1;
	else
		data->shift_x = 0;
	if ((int)data->yp % 32 < 16)
		data->shift_y = -1;
	else if ((int)data->yp % 32 > 16)
		data->shift_y = 1;
	else
		data->shift_y = 0;
}
