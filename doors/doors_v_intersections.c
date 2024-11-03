/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doors_v_intersections.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajouji <ihajouji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 16:59:52 by ihaffout          #+#    #+#             */
/*   Updated: 2024/10/31 18:55:24 by ihajouji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../cub.h"

static void	init_vertical_intersection(t_rays *rays)
{
	rays->is_ray_facing_right = rays->ray_angle < 0.5 * M_PI
		|| rays->ray_angle > 1.5 * M_PI;
	rays->is_ray_facing_left = !rays->is_ray_facing_right;
	rays->is_ray_facing_down = rays->ray_angle > 0 && rays->ray_angle < M_PI;
	rays->is_ray_facing_up = !rays->is_ray_facing_down;
}

static void	calculate_intersection(t_data *data, t_rays *rays)
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

void	doors_v_intersections(t_data *data, t_rays *rays)
{
	float	next_vert_touch_x;
	float	next_vert_touch_y;

	init_vertical_intersection(rays);
	calculate_intersection(data, rays);
	calculate_dx_dy(rays);
	next_vert_touch_x = rays->x_intercept_v;
	next_vert_touch_y = rays->y_intercept_v;
	while (1)
	{
		if (is_door_v(next_vert_touch_x, next_vert_touch_y, data, rays))
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
