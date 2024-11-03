/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   horizontal_intersections.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajouji <ihajouji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 16:58:56 by ihaffout          #+#    #+#             */
/*   Updated: 2024/10/30 21:56:17 by ihajouji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../cub.h"

void	init_horizontal_intersection(t_rays *rays)
{
	rays->is_ray_facing_down = rays->ray_angle > 0 && rays->ray_angle < M_PI;
	rays->is_ray_facing_up = !rays->is_ray_facing_down;
	rays->is_ray_facing_right = rays->ray_angle < 0.5 * M_PI
		|| rays->ray_angle > 1.5 * M_PI;
	rays->is_ray_facing_left = !rays->is_ray_facing_right;
}

static void	calculate_intersection(t_data *data, t_rays *rays)
{
	rays->y_intercept_h = floor(data->yp / SQUARE) * SQUARE;
	if (rays->is_ray_facing_down)
		rays->y_intercept_h += SQUARE;
	else
		rays->y_intercept_h -= EPSILON;
	rays->x_intercept_h = data->xp + (rays->y_intercept_h - data->yp)
		/ tan(rays->ray_angle);
}

static void	calculate_dx_dy(t_rays *rays)
{
	rays->dy = SQUARE;
	if (rays->is_ray_facing_up)
		rays->dy *= -1;
	rays->dx = SQUARE / tan(rays->ray_angle);
	if ((rays->is_ray_facing_left && rays->dx > 0) || (rays->is_ray_facing_right
			&& rays->dx < 0))
		rays->dx *= -1;
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

void	horizontal_intersections(t_data *data, t_rays *rays)
{
	float	next_horz_touch_x;
	float	next_horz_touch_y;

	init_horizontal_intersection(rays);
	calculate_intersection(data, rays);
	calculate_dx_dy(rays);
	next_horz_touch_x = rays->x_intercept_h;
	next_horz_touch_y = rays->y_intercept_h;
	while (1)
	{
		if (is_wall(next_horz_touch_x, next_horz_touch_y, data))
		{
			rays->wall_hit_x_h = next_horz_touch_x;
			rays->wall_hit_y_h = next_horz_touch_y;
			break ;
		}
		else
		{
			next_horz_touch_x += rays->dx;
			next_horz_touch_y += rays->dy;
		}
	}
	rays->distance_h = sqrt(pow(data->xp - next_horz_touch_x, 2) + pow(data->yp
				- next_horz_touch_y, 2));
}
