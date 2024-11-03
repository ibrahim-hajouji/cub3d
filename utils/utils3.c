/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajouji <ihajouji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 14:45:38 by ihajouji          #+#    #+#             */
/*   Updated: 2024/10/23 19:39:28 by ihajouji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../cub.h"

int	get_the_len(char **str, int x)
{
	int	i;
	int	x_len;
	int	y_len;

	i = 0;
	x_len = 0;
	y_len = 0;
	while (str[y_len])
	{
		i = 0;
		while (str[y_len][i] != '\0' && str[y_len][i] != '\n')
			i++;
		if (i > x_len)
			x_len = i;
		y_len++;
	}
	if (x == 1)
		return (x_len);
	return (y_len);
}

float	normalize_angle(float angle)
{
	angle = fmod(angle, 2 * M_PI);
	if (angle < 0)
		angle += 2 * M_PI;
	return (angle);
}

int	skip_spaces(char *str, int i)
{
	while (is_space(str[i]) || str[i] == '\n')
		i++;
	return (i);
}
