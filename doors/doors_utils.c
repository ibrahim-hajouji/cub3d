/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doors_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajouji <ihajouji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 15:34:17 by ihaffout          #+#    #+#             */
/*   Updated: 2024/11/01 12:22:25 by ihajouji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../cub.h"

int	check_if_door_open_v(int map_x, int map_y, t_data *data, t_rays *rays)
{
	int	i;

	i = 0;
	while (i < data->parser->d_count)
	{
		if (data->parser->doors[i].x == map_x
			&& data->parser->doors[i].y == map_y)
		{
			if (!data->parser->doors[i].open)
			{
				if (!rays->x_door_v && !rays->y_door_v)
					return (rays->x_door_v = map_x, rays->y_door_v = map_y, 1);
				return (1);
			}
			else
			{
				if (!rays->x_door_v && !rays->y_door_v)
					return (rays->x_door_v = map_x, rays->y_door_v = map_y, 0);
				return (0);
			}
		}
		i++;
	}
	return (0);
}

int	check_if_door_open_h(int map_x, int map_y, t_data *data, t_rays *rays)
{
	int	i;

	i = 0;
	while (i < data->parser->d_count)
	{
		if (data->parser->doors[i].x == map_x
			&& data->parser->doors[i].y == map_y)
		{
			if (!data->parser->doors[i].open)
			{
				if (!rays->x_door_h && !rays->y_door_h)
					return (rays->x_door_h = map_x, rays->y_door_h = map_y, 1);
				return (1);
			}
			else
			{
				if (!rays->x_door_h && !rays->y_door_h)
					return (rays->x_door_h = map_x, rays->y_door_h = map_y, 0);
				return (0);
			}
		}
		i++;
	}
	return (0);
}

int	check_if_door_exists(t_data *data, int map_x, int map_y)
{
	if (map_x < 0 || map_x >= data->size_x || map_y < 0
		|| map_y >= data->size_y)
		return (-1);
	if (data->parser->map[map_y][map_x] == '1'
		|| data->parser->map[map_y][map_x] == 'D')
		return (1);
	return (0);
}

int	is_door_v(float x, float y, t_data *data, t_rays *rays)
{
	int	map_x;
	int	map_y;
	int	result;

	map_x = floor(x / SQUARE);
	map_y = floor(y / SQUARE);
	result = check_if_door_exists(data, map_x, map_y);
	if (result == -1 || result == 0)
		return (result);
	if (data->parser->map[map_y][map_x] == 'D')
		return (check_if_door_open_v(map_x, map_y, data, rays));
	return (1);
}

int	is_door_h(float x, float y, t_data *data, t_rays *rays)
{
	int	map_x;
	int	map_y;
	int	result;

	map_x = floor(x / SQUARE);
	map_y = floor(y / SQUARE);
	result = check_if_door_exists(data, map_x, map_y);
	if (result == -1 || result == 0)
		return (result);
	if (data->parser->map[map_y][map_x] == 'D')
	{
		return (check_if_door_open_h(map_x, map_y, data, rays));
	}
	return (1);
}
