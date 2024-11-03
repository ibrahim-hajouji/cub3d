/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajouji <ihajouji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 14:33:15 by ihajouji          #+#    #+#             */
/*   Updated: 2024/10/29 11:35:10 by ihajouji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../cub.h"

void	handle_north(char **content, t_parser *parser, int i, int j)
{
	if (!is_space(content[i][j + 2]))
		(write(2, "Error\nWrong detail\n", 20), free_all(parser));
	if (!parser->no)
	{
		j += 2;
		while (is_space(content[i][j]))
			j++;
		parser->no = ft_strdup(content[i] + j);
		parser->no[ft_strlen(parser->no) - 1] = '\0';
	}
	else
		(write(2, "Error\nRepeated detail\n", 23), free_all(parser));
}

void	handle_south(char **content, t_parser *parser, int i, int j)
{
	if (!is_space(content[i][j + 2]))
		(write(2, "Error\nWrong detail\n", 20), free_all(parser));
	if (!parser->so)
	{
		j += 2;
		while (is_space(content[i][j]))
			j++;
		parser->so = ft_strdup(content[i] + j);
		parser->so[ft_strlen(parser->so) - 1] = '\0';
	}
	else
		(write(2, "Error\nRepeated detail\n", 23), free_all(parser));
}

void	handle_east(char **content, t_parser *parser, int i, int j)
{
	if (!is_space(content[i][j + 2]))
		(write(2, "Error\nWrong detail\n", 20), free_all(parser));
	if (!parser->ea)
	{
		j += 2;
		while (is_space(content[i][j]))
			j++;
		parser->ea = ft_strdup(content[i] + j);
		parser->ea[ft_strlen(parser->ea) - 1] = '\0';
	}
	else
		(write(2, "Error\nRepeated detail\n", 23), free_all(parser));
}

void	handle_west(char **content, t_parser *parser, int i, int j)
{
	if (!is_space(content[i][j + 2]))
		(write(2, "Error\nWrong detail\n", 20), free_all(parser));
	if (!parser->we)
	{
		j += 2;
		while (is_space(content[i][j]))
			j++;
		parser->we = ft_strdup(content[i] + j);
		parser->we[ft_strlen(parser->we) - 1] = '\0';
	}
	else
		(write(2, "Error\nRepeated detail\n", 23), free_all(parser));
}
