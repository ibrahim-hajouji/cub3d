/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajouji <ihajouji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 19:00:27 by ihajouji          #+#    #+#             */
/*   Updated: 2024/10/29 16:59:36 by ihajouji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../cub.h"

void	flood_fill(char **str, int x, int y, int len)
{
	if (y > len || x < 0 || y < 0)
		(write(2, "Error\nThe map must be surrounded by walls\n", 42), exit(1));
	if (str[y][x] == '\n' || x >= ft_strlen(str[y]))
		(write(2, "Error\nThe map must be surrounded by walls\n", 42), exit(1));
	if (str[y][x] == '1')
		return ;
	else
		str[y][x] = '1';
	flood_fill(str, x + 1, y, len);
	flood_fill(str, x, y + 1, len);
	flood_fill(str, x - 1, y, len);
	flood_fill(str, x, y - 1, len);
}

char	**mapcpy(char **str, int len)
{
	int		i;
	char	**cpy;

	i = 0;
	cpy = malloc(sizeof(char *) * len + 1);
	if (!cpy)
		return (NULL);
	while (i < len)
	{
		cpy[i] = ft_strdup(str[i]);
		i++;
	}
	cpy[i] = NULL;
	return (cpy);
}

int	check_path(char **map, int x_player, int y_player, int len)
{
	char	**cpy;
	int		j;

	j = 0;
	cpy = mapcpy(map, len);
	if (!cpy)
		return (write(2, "Error\nMalloc failed\n", 20), 1);
	flood_fill(cpy, x_player, y_player, len - 1);
	ft_free(cpy);
	return (0);
}

void	fill(t_parser *parser, char **content, int map_start, int i)
{
	int	j;

	j = 0;
	if (map_start > i - 2)
		(write(2, "Error\nWrong map\n", 16), free_all(parser));
	parser->map = malloc(sizeof(char *) * (i - map_start + 2));
	if (!parser->map)
		(write(2, "Error\nMalloc failed\n", 20), free_all(parser));
	while (map_start <= i)
	{
		parser->map[j++] = ft_strdup(content[map_start++]);
		if (!parser->map[j - 1])
			(write(2, "Error\nMalloc failed\n", 20), free_all(parser));
	}
	parser->map[j] = NULL;
}

void	fill_map(char **content, t_parser *parser, int map_start)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (content[i])
		i++;
	i--;
	i = end_of_map(content, i);
	while (content[map_start])
	{
		if (ft_strcmp(content[map_start], "\n") == 0)
			map_start++;
		else
		{
			while (is_space(content[map_start][j]))
				j++;
			if (content[map_start][j] == '\n')
				map_start++;
			else
				break ;
		}
	}
	fill(parser, content, map_start, i);
}
