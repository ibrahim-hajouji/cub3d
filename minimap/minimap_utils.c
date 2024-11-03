/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajouji <ihajouji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 13:15:47 by ihajouji          #+#    #+#             */
/*   Updated: 2024/10/28 12:28:15 by ihajouji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../cub.h"

int	is_out_of_horizontal_bounds(t_data *data, int *i, int *j)
{
	if (((int)data->yp) / 32 + (*i) - (data->nmbr_of_lines / 2) 
		+ data->shift_y < 0 || ((int)data->yp) / 32 + (*i) 
		- (data->nmbr_of_lines / 2) + data->shift_y > data->size_y)
	{
		while ((*j) < data->nmbr_of_columns)
		{
			data->minimap[(*i)][(*j)] = 'X';
			(*j)++;
		}
		data->minimap[(*i)][(*j)] = '\0';
		(*i)++;
		return (1);
	}
	return (0);
}

void	fill_player(t_data *data, int i, int j)
{
	data->minimap[i][j] = 'P';
	data->minimap_xp = (j * 32) + ((int)data->xp % 32);
	data->minimap_yp = (i * 32) + ((int)data->yp % 32);
}

void	fill_index(t_data *data, int i, int j)
{
	int	map_x;
	int	map_y;

	map_x = (((int)data->xp) / 32) + j - (data->nmbr_of_columns / 2)
		+ data->shift_x;
	map_y = (((int)data->yp) / 32) + i - (data->nmbr_of_lines / 2)
		+ data->shift_y;
	if (map_x < 0 || map_y < 0 || !data->parser->map[map_y]
		|| data->parser->map[map_y][map_x] == '\0'
		|| data->parser->map[map_y][map_x] == '\n'
		|| map_x >= (int)ft_strlen(data->parser->map[map_y]))
		data->minimap[i][j] = 'X';
	else
	{
		if (((map_y) == (int)data->yp / 32) && ((map_x) == (int)data->xp / 32))
			fill_player(data, i, j);
		else if (is_player(data->parser->map[map_y][map_x]))
			data->minimap[i][j] = '0';
		else if (data->parser->map[map_y][map_x] == 'D' 
			&& !is_closed(map_x, map_y, data))
			data->minimap[i][j] = 'd';
		else
			data->minimap[i][j] = data->parser->map[map_y][map_x];
	}
}

void	draw_pixel(t_data *data, int x, int y)
{
	int	map_x;
	int	map_y;

	map_x = (data->minimap_x_start + x) / 32;
	map_y = (data->minimap_y_start + y) / 32;
	if (map_y < 0 || map_y >= data->nmbr_of_lines || map_x < 0
		|| map_x >= data->nmbr_of_columns || !data->minimap[map_y])
		mlx_put_pixel(data->mlx->mlx_img, x + 10, y + 10, get_color(_X));
	else if (data->minimap[map_y][map_x] == '1')
		mlx_put_pixel(data->mlx->mlx_img, x + 10, y + 10, get_color(WALL_C));
	else if (x > PLAYER_MINIMAP_X - 2 && x < PLAYER_MINIMAP_X + 2
		&& y > PLAYER_MINIMAP_Y - 2 && y < PLAYER_MINIMAP_Y + 2 
		&& data->minimap[map_y][map_x] == 'P')
		mlx_put_pixel(data->mlx->mlx_img, x + 10, y + 10, get_color(PLAYER_C));
	else if (data->minimap[map_y][map_x] == 'X'
			|| is_space(data->minimap[map_y][map_x]))
		mlx_put_pixel(data->mlx->mlx_img, x + 10, y + 10, get_color(_X));
	else if (data->minimap[map_y][map_x] == 'D')
		mlx_put_pixel(data->mlx->mlx_img, x + 10, y + 10, get_color(ORANGE));
	else
		mlx_put_pixel(data->mlx->mlx_img, x + 10, y + 10, get_color(PATH_C));
}

int	is_closed(int x, int y, t_data *data)
{
	int	i;

	i = 0;
	while (i < data->parser->d_count)
	{
		if (data->parser->doors[i].x == x && data->parser->doors[i].y == y)
		{
			if (data->parser->doors[i].open == 0)
				return (1);
			else
				return (0);
		}
		i++;
	}
	return (0);
}
