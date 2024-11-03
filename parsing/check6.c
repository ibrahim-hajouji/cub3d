/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check6.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajouji <ihajouji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 19:04:50 by ihajouji          #+#    #+#             */
/*   Updated: 2024/10/29 13:22:19 by ihajouji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../cub.h"

int	check_f(char *str, t_parser *parser, int k, int i)
{
	int	j;

	while (k < 3)
	{
		j = 0;
		if (k != 2)
		{
			while (parser->f[i] && parser->f[i] != ',')
				str[j++] = parser->f[i++];
		}
		else
		{
			while (parser->f[i] && parser->f[i] != '\n')
				str[j++] = parser->f[i++];
		}
		str[j] = '\0';
		if (j == 0)
			return (0);
		i++;
		if (!is_valid_color_component(str))
			return (0);
		k++;
	}
	return (1);
}

int	check_c(char *str, t_parser *parser, int k, int i)
{
	int	j;

	while (k < 3)
	{
		j = 0;
		if (k != 2)
		{
			while (parser->c[i] && parser->c[i] != ',')
				str[j++] = parser->c[i++];
		}
		else
		{
			while (parser->c[i] && parser->c[i] != '\n')
				str[j++] = parser->c[i++];
		}
		str[j] = '\0';
		if (j == 0)
			return (0);
		i++;
		if (!is_valid_color_component(str))
			return (0);
		k++;
	}
	return (1);
}

void	open_check(char *path, t_parser *parser, int option)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
	{
		if (option == 1)
			write(2, "Error\nInvalid path\n", 20);
		else
			write(2, "Error\nStop touching my files stupid !!!\n", 40);
		free_all(parser);
	}
}

void	check_files(t_parser *parser)
{
	open_check(parser->no, parser, 1);
	open_check(parser->so, parser, 1);
	open_check(parser->we, parser, 1);
	open_check(parser->ea, parser, 1);
	open_check("./_textures/door.png", parser, 2);
	open_check("./_textures/intro1.png", parser, 2);
	open_check("./_textures/intro2.png", parser, 2);
	open_check("./_textures/controllers.png", parser, 2);
	open_check("./_textures/light_off/1.png", parser, 2);
	open_check("./_textures/light_off/2.png", parser, 2);
	open_check("./_textures/light_off/3.png", parser, 2);
	open_check("./_textures/player_off/1.png", parser, 2);
	open_check("./_textures/player_off/2.png", parser, 2);
	open_check("./_textures/player_off/3.png", parser, 2);
	open_check("./_textures/player_off/4.png", parser, 2);
	open_check("./_textures/player/player_1.png", parser, 2);
	open_check("./_textures/player/player_2.png", parser, 2);
	open_check("./_textures/player/player_3.png", parser, 2);
	open_check("./_textures/player/player_4.png", parser, 2);
	open_check("./_textures/player/player_5.png", parser, 2);
}

int	valid_details(t_parser *parser)
{
	int		i;
	char	str[4];
	int		k;

	k = 0;
	i = 0;
	if (check_f(str, parser, k, i) == 0)
		return (0);
	i = 0;
	k = 0;
	if (check_c(str, parser, k, i) == 0)
		return (0);
	check_files(parser);
	return (1);
}
