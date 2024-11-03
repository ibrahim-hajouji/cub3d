/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajouji <ihajouji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 14:41:28 by ihajouji          #+#    #+#             */
/*   Updated: 2024/10/23 18:23:40 by ihajouji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../cub.h"

void	handle_floor(char **content, t_parser *parser, int i, int j)
{
	if (!parser->f)
	{
		j += 1;
		while (is_space(content[i][j]))
			j++;
		parser->f = ft_strdup(content[i] + j);
	}
	else
		(write(2, "Error\nRepeated detail\n", 26), free_all(parser));
}

void	handle_ceiling(char **content, t_parser *parser, int i, int j)
{
	if (!parser->c)
	{
		j += 1;
		while (is_space(content[i][j]))
			j++;
		parser->c = ft_strdup(content[i] + j);
	}
	else
		(write(2, "Error\nRepeated detail\n", 26), free_all(parser));
}
