/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajouji <ihajouji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 13:11:25 by ihajouji          #+#    #+#             */
/*   Updated: 2024/11/02 11:28:20 by ihajouji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../cub.h"

void	mouse_click(t_data *data, int *door_pressed)
{
	int	x;
	int	y;
	int	i;

	*door_pressed = 1;
	x = data->door_x;
	y = data->door_y;
	i = 0;
	if ((int)data->xp / 32 == x && (int)data->yp / 32 == y)
		return ;
	while (i < data->parser->d_count)
	{
		if (data->parser->doors[i].x == x && data->parser->doors[i].y == y)
		{
			data->parser->doors[i].open = !data->parser->doors[i].open;
			break ;
		}
		i++;
	}
}

void	handle_mouse_rotation(t_data *data)
{
	int	current_mouse_x;
	int	current_mouse_y;
	int	delta_x;

	mlx_get_mouse_pos(data->mlx->mlx_ptr, &current_mouse_x, &current_mouse_y);
	if (current_mouse_x < 0 || current_mouse_y < 0
		|| current_mouse_x > WINDOW_WIDTH || current_mouse_y > WINDOW_HEIGHT)
		return ;
	delta_x = current_mouse_x - data->last_mouse_x;
	if (delta_x != 0)
	{
		data->player_rotation_angle += delta_x * 0.0035;
		if (data->player_rotation_angle < 0)
			data->player_rotation_angle += 2 * M_PI;
		else if (data->player_rotation_angle > 2 * M_PI)
			data->player_rotation_angle -= 2 * M_PI;
	}
	data->last_mouse_x = current_mouse_x;
}
