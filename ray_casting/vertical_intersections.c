/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vertical_intersections.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajouji <ihajouji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 16:59:52 by ihaffout          #+#    #+#             */
/*   Updated: 2024/10/30 21:56:12 by ihajouji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../cub.h"

void	init_vertical_intersection(t_data *data, t_rays *rays)
{
	(void)data;
	rays->is_ray_facing_right = rays->ray_angle < 0.5 * M_PI
		|| rays->ray_angle > 1.5 * M_PI;
	rays->is_ray_facing_left = !rays->is_ray_facing_right;
	rays->is_ray_facing_down = rays->ray_angle > 0 && rays->ray_angle < M_PI;
	rays->is_ray_facing_up = !rays->is_ray_facing_down;
}

void	calculate_intersection(t_data *data, t_rays *rays)
{
	rays->x_intercept_v = floor(data->xp / SQUARE) * SQUARE;
	if (rays->is_ray_facing_right)
		rays->x_intercept_v += SQUARE;
	else
		rays->x_intercept_v -= EPSILON;
	rays->y_intercept_v = data->yp + (rays->x_intercept_v - data->xp)
		* tan(rays->ray_angle);
}

static void	calculate_dx_dy(t_rays *rays)
{
	rays->dx = SQUARE;
	if (rays->is_ray_facing_left)
		rays->dx *= -1;
	rays->dy = SQUARE * tan(rays->ray_angle);
	if ((rays->is_ray_facing_up && rays->dy > 0) || (rays->is_ray_facing_down
			&& rays->dy < 0))
		rays->dy *= -1;
}

static int	is_wall(float x, float y, t_data *data)
{
	int	map_x;
	int	map_y;

	map_x = floor(x / SQUARE);
	map_y = floor(y / SQUARE);
	if (map_x < 0 || map_x >= data->size_x || map_y < 0
		|| map_y >= data->size_y)
		return (-1);
	if (data->parser->map[map_y][map_x] == '1')
	{
		return (1);
	}
	return (0);
}

void	vertical_intersections(t_data *data, t_rays *rays)
{
	float	next_vert_touch_x;
	float	next_vert_touch_y;

	init_vertical_intersection(data, rays);
	calculate_intersection(data, rays);
	calculate_dx_dy(rays);
	next_vert_touch_x = rays->x_intercept_v;
	next_vert_touch_y = rays->y_intercept_v;
	while (1)
	{
		if (is_wall(next_vert_touch_x, next_vert_touch_y, data))
		{
			rays->wall_hit_x_v = next_vert_touch_x;
			rays->wall_hit_y_v = next_vert_touch_y;
			break ;
		}
		else
		{
			next_vert_touch_x += rays->dx;
			next_vert_touch_y += rays->dy;
		}
	}
	rays->distance_v = sqrt(pow(data->xp - next_vert_touch_x, 2) + pow(data->yp
				- next_vert_touch_y, 2));
}
