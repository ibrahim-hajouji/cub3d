/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doors.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajouji <ihajouji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 14:28:43 by ihajouji          #+#    #+#             */
/*   Updated: 2024/11/01 11:24:06 by ihajouji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../cub.h"

void	set_values(t_data *data, t_rays *rays, int option)
{
	if (option == 0)
	{
		rays->wall_hit_x = rays->wall_hit_x_h;
		rays->wall_hit_y = rays->wall_hit_y_h;
		if (!data->door_x && !data->door_y)
		{
			data->door_x = rays->x_door_h;
			data->door_y = rays->y_door_h;
		}
		rays->distance = rays->distance_h;
	}
	else
	{
		rays->wall_hit_x = rays->wall_hit_x_v;
		rays->wall_hit_y = rays->wall_hit_y_v;
		if (!data->door_x && !data->door_y)
		{
			data->door_x = rays->x_door_v;
			data->door_y = rays->y_door_v;
		}
		rays->distance = rays->distance_v;
	}
}

static void	calculate_distance(t_data *data, t_rays *rays, int *is_door)
{
	if (rays->distance_h <= rays->distance_v)
		set_values(data, rays, 0);
	else
		set_values(data, rays, 1);
	if (data->parser->map[(int)rays->wall_hit_y / SQUARE][(int)rays->wall_hit_x
		/ SQUARE] == 'D')
		*is_door = 1;
	else
		*is_door = 0;
	rays->ray_angle = normalize_angle(rays->ray_angle);
	rays->distance *= cos(rays->ray_angle - data->player_rotation_angle);
}

static void	door_hit_info(t_rays *rays, t_data *data, int x, int y)
{
	if (rays->distance_v < rays->distance_h)
		rays->wall_hit = 1;
	else
		rays->wall_hit = 0;
	if (data->parser->map[y][x] == 'D')
		rays->direction = 'D';
	return ;
}

void	_init(t_data *data, t_rays *rays)
{
	data->door_x = 0;
	data->door_y = 0;
	rays->x_door_h = 0;
	rays->y_door_h = 0;
	rays->x_door_v = 0;
	rays->y_door_v = 0;
	rays->ray_angle = data->player_rotation_angle - (FOV_ANGLE / 2);
}

void	cast_rays_doors(t_data *data)
{
	t_rays	*rays;
	int		is_door;
	int		i;

	i = -1;
	is_door = 0;
	rays = malloc(sizeof(t_rays));
	if (!rays)
		(write(2, "Error\nMalloc failed\n", 20), end_game(data));
	_init(data, rays);
	while (++i < NUM_RAYS)
	{
		normalize_angle(rays->ray_angle);
		doors_h_intersections(data, rays);
		doors_v_intersections(data, rays);
		calculate_distance(data, rays, &is_door);
		if (is_door)
		{
			door_hit_info(rays, data, rays->wall_hit_x / SQUARE,
				rays->wall_hit_y / SQUARE);
			draw_doors_to_image(data, rays, i);
		}
		rays->ray_angle += FOV_ANGLE / NUM_RAYS;
	}
	free(rays);
}
