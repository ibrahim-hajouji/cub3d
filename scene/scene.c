/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajouji <ihajouji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 13:07:51 by ihajouji          #+#    #+#             */
/*   Updated: 2024/11/03 01:24:56 by ihajouji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../cub.h"

void	animate_ghost(t_data *data)
{
	if (data->light_off->animation_ghost >= 100
		&& data->light_off->animation_ghost <= 130)
		draw_img(data->light_off->ghost_1, data);
	if (data->light_off->animation_ghost == 130)
		data->light_off->animation_ghost = 0;
	data->light_off->animation_ghost++;
}

void	scene(t_data *data, int option)
{
	if (option == 0)
	{
		draw_ceiling_floor(data);
		cast_rays_walls(data);
		cast_rays_doors(data);
		animate_player(data, 1);
		data->player_off->animation = 0;
	}
	else
	{
		cast_rays_doors(data);
		animate_background(data);
		animate_player(data, 0);
		animate_ghost(data);
	}
}

void	dark_mode(t_data *data, int *space_pressed)
{
	*space_pressed = 1;
	data->light = !data->light;
}
