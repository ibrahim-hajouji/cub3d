/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajouji <ihajouji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 19:02:05 by ihajouji          #+#    #+#             */
/*   Updated: 2024/11/01 12:01:17 by ihajouji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../cub.h"

void	fill_door_infos(t_door *doors, int *k, int i, int j)
{
	doors[*k].x = j;
	doors[*k].y = i;
	doors[*k].open = 0;
	(*k)++;
}

int	valid_place_for_door(t_parser *parser, int i, int j)
{
	if (parser->map[i][j + 1] == 'D' || parser->map[i][j - 1] == 'D'
		|| parser->map[i + 1][j] == 'D' || parser->map[i - 1][j] == 'D')
		return (0);
	if ((parser->map[i][j + 1] == '1' && parser->map[i][j - 1] == '1')
		|| (parser->map[i + 1][j] == '1' && parser->map[i - 1][j] == '1'))
		return (1);
	return (0);
}

int	check_doors(t_parser *parser, t_door *doors)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (parser->map[i])
	{
		j = 0;
		while (is_space(parser->map[i][j]))
			j++;
		while (parser->map[i][j] && parser->map[i][j] != '\n')
		{
			if (parser->map[i][j] == 'D')
			{
				if (valid_place_for_door(parser, i, j))
					fill_door_infos(doors, &k, i, j);
				else
					return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	missing_detail(t_parser *parser)
{
	if (!parser->c || !parser->ea || !parser->f || !parser->no || !parser->so
		|| !parser->we || !*parser->c || !*parser->ea || !*parser->f 
		|| !*parser->no || !*parser->so || !*parser->we)
		return (1);
	else if ((ft_strcmp(parser->c, "\n") == 0) 
		|| (ft_strcmp(parser->ea, "\n") == 0)
		|| (ft_strcmp(parser->f, "\n") == 0) 
		|| (ft_strcmp(parser->no, "\n") == 0) 
		|| (ft_strcmp(parser->so, "\n") == 0) 
		|| (ft_strcmp(parser->we, "\n") == 0))
		return (1);
	else
		return (0);
}

int	end_of_map(char **content, int i)
{
	int	j;

	while (content[i])
	{
		j = 0;
		if (ft_strcmp(content[i], "\n") == 0)
			i--;
		else
		{
			while (is_space(content[i][j]))
				j++;
			if (content[i][j] == '\n')
				i--;
			else
				break ;
		}
	}
	return (i);
}
