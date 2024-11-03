/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajouji <ihajouji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 13:18:01 by ihaffout          #+#    #+#             */
/*   Updated: 2024/10/31 20:19:52 by ihajouji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../cub.h"

int	details(char **content, t_parser *parser, int i, int j)
{
	if (content[i][j] == 'N' && content[i][j + 1] == 'O')
		handle_north(content, parser, i, j);
	else if (content[i][j] == 'S' && content[i][j + 1] == 'O')
		handle_south(content, parser, i, j);
	else if (content[i][j] == 'E' && content[i][j + 1] == 'A')
		handle_east(content, parser, i, j);
	else if (content[i][j] == 'W' && content[i][j + 1] == 'E')
		handle_west(content, parser, i, j);
	else if (content[i][j] == 'F')
		handle_floor(content, parser, i, j);
	else if (content[i][j] == 'C')
		handle_ceiling(content, parser, i, j);
	else if ((ft_strcmp(content[i] + j, "\n") != 0) && missing_detail(parser))
		(write(2, "Error\nInvalid detail\n", 21), free_all(parser));
	else if (!missing_detail(parser))
		return (1);
	return (0);
}

int	check_details(char **content, t_parser *parser)
{
	int	i;
	int	j;

	i = 0;
	while (ft_strcmp(content[i], "\n") == 0)
		i++;
	while (content[i])
	{
		j = skip_space(content[i]);
		if (details(content, parser, i, j))
			break ;
		i++;
	}
	if (missing_detail(parser))
		(write(2, "Error\nMissing detail\n", 21), free_all(parser));
	if (!valid_details(parser))
		(write(2, "Error\nInvalid detail\n", 21), free_all(parser));
	return (i);
}

void	check_map(t_parser *parser)
{
	int		len;
	t_door	*doors;

	len = 0;
	while (parser->map[len])
		len++;
	len = end_of_map(parser->map, len);
	if (inv_char(parser->map, parser))
		ft_err("Error\nInvalid character in map\n", parser);
	if (surrounded_by_walls(parser->map, len))
		ft_err("Error\nThe map must be surrounded by walls\n", parser);
	if (check_spaces(parser->map, len))
		ft_err("Error\nThe map must be surrounded by walls\n", parser);
	if (check_path(parser->map, parser->x_player, parser->y_player, len))
		ft_err("Error\nThe map must be surrounded by walls\n", parser);
	doors = malloc(sizeof(t_door) * parser->d_count);
	if (!doors)
		ft_err("Error\nMalloc failed\n", parser);
	if (check_doors(parser, doors))
		ft_err("Error\nInvalid placement of doors\n", parser);
	parser->doors = doors;
}

void	check_valid(char **content, t_parser *parser)
{
	int	map_start;

	map_start = check_details(content, parser);
	fill_map(content, parser, map_start);
	check_map(parser);
	parser->player_dir = parser->map[parser->y_player][parser->x_player];
}
