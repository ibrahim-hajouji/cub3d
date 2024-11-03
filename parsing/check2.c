/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajouji <ihajouji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 16:46:00 by ihajouji          #+#    #+#             */
/*   Updated: 2024/10/23 18:22:37 by ihajouji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../cub.h"

void	init_player_index(t_parser *parser, char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (is_space(map[i][j]))
			j++;
		while (map[i][j] && map[i][j] != '\n')
		{
			if (map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'W'
				|| map[i][j] == 'E')
			{
				parser->x_player = j;
				parser->y_player = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

int	check_(char c, int *d_count, int *count)
{
	if (c == '1' || c == '0' || c == ' ')
		return (1);
	else if (c == 'D')
	{
		(*d_count)++;
		return (1);
	}
	else if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
	{
		(*count)++;
		return (1);
	}
	return (0);
}

int	inv_char(char **map, t_parser *parser)
{
	int	i;
	int	j;
	int	count;
	int	d_count;

	count = 0;
	i = 0;
	d_count = 0;
	while (map[i])
	{
		j = 0;
		while (is_space(map[i][j]))
			j++;
		while (map[i][j] && map[i][j] != '\n')
		{
			if (check_(map[i][j], &d_count, &count) == 1)
				j++;
			else
				return (1);
		}
		i++;
	}
	if (count != 1)
		return (1);
	return (init_player_index(parser, map), parser->d_count = d_count, 0);
}
