/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajouji <ihajouji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 18:39:26 by ihajouji          #+#    #+#             */
/*   Updated: 2024/10/23 19:21:29 by ihajouji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../cub.h"

int	is_player(char c)
{
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E')
		return (1);
	return (0);
}

int	check_first_line(char **str)
{
	int	j;

	j = 0;
	while (str[0][j] != '\n')
	{
		if (!is_space(str[0][j]) && str[0][j] != '1')
			return (1);
		j++;
	}
	return (0);
}

int	check_last_line(char **str, int len)
{
	int	j;

	j = 0;
	while (str[len - 1][j] != '\n' && str[len - 1][j] != '\0')
	{
		if (!is_space(str[len - 1][j]) && str[len - 1][j] != '1')
			return (1);
		j++;
	}
	return (0);
}

int	surrounded_by_walls(char **str, int len)
{
	int	i;
	int	j;

	i = 0;
	if (check_first_line(str))
		return (1);
	if (check_last_line(str, len))
		return (1);
	while (i < len)
	{
		j = 0;
		while (is_space(str[i][j]))
			j++;
		if (str[i][j] != '1')
			return (1);
		while (str[i][j] != '\n' && str[i][j] != '\0')
			j++;
		j--;
		while (is_space(str[i][j]))
			j--;
		if (str[i][j] != '1')
			return (1);
		i++;
	}
	return (0);
}

int	check_spaces(char **map, int len)
{
	int	i;
	int	j;

	i = 1;
	while (i < len)
	{
		j = 0;
		while (map[i][j] != '\n' && map[i][j] != '\0')
		{
			if (map[i][j] != '1' && !is_space(map[i][j]))
			{
				if (is_space(map[i][j - 1]) || is_space(map[i][j + 1]) 
					|| is_space(map[i + 1][j]) || is_space(map[i - 1][j]))
					return (1);
				if ((j > ft_strlen(map[i + 1]) - 1) 
					|| (j > ft_strlen(map[i - 1]) - 1))
					return (1);
				if (map[i + 1][j] == '\n' || map[i - 1][j] == '\n')
					return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}
