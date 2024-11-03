/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrows.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajouji <ihajouji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 13:12:54 by ihajouji          #+#    #+#             */
/*   Updated: 2024/10/28 13:13:31 by ihajouji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../cub.h"

void	look_left(t_data *data)
{
	data->player_rotation_angle -= 0.18;
	if (data->player_rotation_angle < 0)
		data->player_rotation_angle += 2 * M_PI;
}

void	look_right(t_data *data)
{
	data->player_rotation_angle += 0.18;
	if (data->player_rotation_angle > 2 * M_PI)
		data->player_rotation_angle -= 2 * M_PI;
}
