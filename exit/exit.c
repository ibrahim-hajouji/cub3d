/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajouji <ihajouji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/28 14:35:14 by ihajouji          #+#    #+#             */
/*   Updated: 2024/10/30 16:32:02 by ihajouji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../cub.h"

void	ft_err(char *str, t_parser *parser)
{
	int	i;

	i = 0;
	while (str[i])
		write(2, &str[i++], 1);
	free_all(parser);
}

void	end_game(t_data *data)
{
	mlx_close_window(data->mlx->mlx_ptr);
	exit(0);
}
