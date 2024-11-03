/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajouji <ihajouji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 14:28:43 by ihajouji          #+#    #+#             */
/*   Updated: 2024/10/31 19:01:31 by ihajouji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../cub.h"

static void	calculate_distance(t_data *data, t_rays *rays)
{
	if (rays->distance_h <= rays->distance_v)
	{
		rays->wall_hit_x = rays->wall_hit_x_h;
		rays->wall_hit_y = rays->wall_hit_y_h;
		rays->distance = rays->distance_h;
	}
	else
	{
		rays->wall_hit_x = rays->wall_hit_x_v;
		rays->wall_hit_y = rays->wall_hit_y_v;
		rays->distance = rays->distance_v;
	}
	rays->ray_angle = normalize_angle(rays->ray_angle);
	rays->distance *= cos(rays->ray_angle - data->player_rotation_angle);
}

static void	wall_hit_info(t_rays *rays)
{
	if (rays->distance_v < rays->distance_h)
	{
		rays->wall_hit = 1;
		if (cos(rays->ray_angle) > 0)
			rays->direction = 'W';
		else
			rays->direction = 'E';
	}
	else
	{
		rays->wall_hit = 0;
		if (sin(rays->ray_angle) > 0)
			rays->direction = 'N';
		else
			rays->direction = 'S';
	}
}

void	cast_rays_walls(t_data *data)
{
	int		i;
	t_rays	*rays;

	i = -1;
	rays = malloc(sizeof(t_rays));
	if (!rays)
		(write(2, "Error\nMalloc failed\n", 20), end_game(data));
	rays->ray_angle = data->player_rotation_angle - (FOV_ANGLE / 2);
	while (++i < NUM_RAYS)
	{
		normalize_angle(rays->ray_angle);
		horizontal_intersections(data, rays);
		vertical_intersections(data, rays);
		calculate_distance(data, rays);
		wall_hit_info(rays);
		draw_ray_to_image(data, rays, i);
		rays->ray_angle += FOV_ANGLE / NUM_RAYS;
	}
	free(rays);
}
