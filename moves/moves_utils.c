/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajouji <ihajouji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 13:47:09 by ihajouji          #+#    #+#             */
/*   Updated: 2024/10/28 10:46:29 by ihajouji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../cub.h"

int	can_move(t_data *data, int new_x, int new_y)
{
	if (((data->parser->map[(new_y + 4) / 32][(new_x + 4) / 32] != '1')
		&& (data->parser->map[(new_y) / 32][(new_x) / 32] != '1')
		&& (data->parser->map[(new_y) / 32][(new_x + 4) / 32] != '1')
		&& (data->parser->map[(new_y + 4) / 32][(new_x) / 32] != '1')
		&& (data->parser->map[(new_y - 4) / 32][(new_x - 4) / 32] != '1')
		&& (data->parser->map[(new_y - 4) / 32][new_x / 32] != '1')
		&& (data->parser->map[new_y / 32][(new_x - 4) / 32] != '1')
		&& (data->parser->map[(new_y + 4) / 32][(new_x - 4) / 32] != '1')
		&& (data->parser->map[(new_y - 4) / 32][(new_x + 4) / 32] != '1')))
		return (1);
	else
		return (0);
}

int	locked(t_data *data, int new_x, int new_y)
{
	if (is_closed((new_x + 4) / 32, (new_y + 4) / 32, data) 
		|| is_closed(new_x / 32, new_y / 32, data) 
		|| is_closed(new_x / 32, (new_y + 4) / 32, data) 
		|| is_closed((new_x + 4) / 32, new_y / 32, data)
		|| is_closed((new_x - 4) / 32, (new_y - 4) / 32, data)
		|| is_closed((new_x - 4) / 32, new_y / 32, data) 
		|| is_closed(new_x / 32, (new_y - 4) / 32, data) 
		|| is_closed((new_x + 4) / 32, (new_y - 4) / 32, data))
		return (1);
	return (0);
}
