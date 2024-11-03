/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajouji <ihajouji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 09:35:11 by ihajouji          #+#    #+#             */
/*   Updated: 2024/10/30 16:32:27 by ihajouji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../cub.h"

void	ft_free(char **str)
{
	int	i;

	i = 0;
	if (!str || !*str)
		return ;
	while (str[i])
		free(str[i++]);
	free(str);
}

void	free_all(t_parser *parser)
{
	free(parser->c);
	free(parser->ea);
	free(parser->f);
	free(parser->no);
	free(parser->so);
	free(parser->we);
	ft_free(parser->map);
	free(parser);
	exit(1);
}
