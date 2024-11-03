/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check7.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajouji <ihajouji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 19:06:05 by ihajouji          #+#    #+#             */
/*   Updated: 2024/10/29 12:08:40 by ihajouji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../cub.h"

void	check_name(char *name)
{
	int	len;

	len = 0;
	while (name[len])
		len++;
	if (len < 4)
	{
		write(2, "Error\nInvalid file\n", 19);
		exit(1);
	}
	if (name[len - 1] == 'b' && name[len - 2] == 'u' && name[len - 3] == 'c'
		&& name[len - 4] == '.')
		return ;
	write(2, "Error\nInvalid file\n", 19);
	exit(1);
}

int	file_len(char *name)
{
	int		len;
	int		fd;
	char	*tmp;

	len = 0;
	fd = open(name, O_RDONLY);
	if (fd < 0)
	{
		write(2, "Error\nInvalid file\n", 19);
		exit(1);
	}
	while (1)
	{
		tmp = get_next_line(fd);
		if (!tmp)
			break ;
		free(tmp);
		len++;
	}
	close(fd);
	return (len);
}

char	**get_content(char *name)
{
	char	**res;
	int		i;
	int		fd;

	check_name(name);
	i = file_len(name);
	res = malloc(sizeof(char *) * i + 1);
	if (!res)
		(write(2, "Error\nMalloc failed\n", 20), exit(1));
	fd = open(name, O_RDONLY);
	if (fd < 0)
	{
		(free(res), write(2, "Error\nInvalid file\n", 19));
		exit(1);
	}
	i = 0;
	while (1)
	{
		res[i] = get_next_line(fd);
		if (!res[i])
			break ;
		i++;
	}
	close(fd);
	return (res);
}

int	is_valid_color_component(char *str)
{
	int	nbr;

	nbr = ft_atoi(str);
	if (nbr >= 0 && nbr <= 255)
		return (1);
	return (0);
}

int	skip_space(char *str)
{
	int	i;

	i = 0;
	while (is_space(str[i]))
		i++;
	return (i);
}
