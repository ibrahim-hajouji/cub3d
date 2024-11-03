/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajouji <ihajouji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 11:02:28 by ihajouji          #+#    #+#             */
/*   Updated: 2024/10/24 12:46:38 by ihajouji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../cub.h"
#define MOVE_SPEED 5 // Speed of movement

void	move_player(t_data *data, double direction)
{
	int	new_x;
	int	new_y;

	new_x = round(data->xp + cos(data->player_rotation_angle) * MOVE_SPEED
			* direction);
	new_y = round(data->yp + sin(data->player_rotation_angle) * MOVE_SPEED
			* direction);
	if (can_move(data, new_x, new_y))
	{
		if (locked(data, new_x, new_y))
			return ;
		data->xp = new_x;
		data->yp = new_y;
	}
}

void	move_forward(t_data *data)
{
	move_player(data, 1);
}

void	move_backward(t_data *data)
{
	move_player(data, -1);
}

void	move_left(t_data *data)
{
	int	new_x;
	int	new_y;

	new_x = round(data->xp - cos(data->player_rotation_angle + M_PI / 2)
			* MOVE_SPEED);
	new_y = round(data->yp - sin(data->player_rotation_angle + M_PI / 2)
			* MOVE_SPEED);
	if (can_move(data, new_x, new_y))
	{
		if (locked(data, new_x, new_y))
			return ;
		data->xp = new_x;
		data->yp = new_y;
	}
}

void	move_right(t_data *data)
{
	int	new_x;
	int	new_y;

	new_x = round(data->xp + cos(data->player_rotation_angle + M_PI / 2)
			* MOVE_SPEED);
	new_y = round(data->yp + sin(data->player_rotation_angle + M_PI / 2)
			* MOVE_SPEED);
	if (can_move(data, new_x, new_y))
	{
		if (locked(data, new_x, new_y))
			return ;
		data->xp = new_x;
		data->yp = new_y;
	}
}
