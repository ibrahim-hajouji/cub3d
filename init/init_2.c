/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajouji <ihajouji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 12:36:46 by ihaffout          #+#    #+#             */
/*   Updated: 2024/10/30 15:40:29 by ihajouji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../cub.h"

int	get_floor_color(char *f)
{
	int		r;
	int		g;
	int		b;
	char	**rgb;

	rgb = ft_split(f, ',');
	if (!rgb)
		(write(2, "Error\nMalloc failed\n", 20), exit(1));
	r = ft_atoi(rgb[0]);
	g = ft_atoi(rgb[1]);
	b = ft_atoi(rgb[2]);
	ft_free(rgb);
	return (r << 24 | g << 16 | b << 8 | 255);
}

int	get_ceiling_color(char *c)
{
	int		r;
	int		g;
	int		b;
	char	**rgb;

	rgb = ft_split(c, ',');
	if (!rgb)
		(write(2, "Error\nMalloc failed\n", 20), exit(1));
	r = ft_atoi(rgb[0]);
	g = ft_atoi(rgb[1]);
	b = ft_atoi(rgb[2]);
	ft_free(rgb);
	return (r << 24 | g << 16 | b << 8 | 255);
}

t_mlx	*init_mlx(t_data *data)
{
	t_mlx	*mlx;

	mlx = malloc(sizeof(t_mlx));
	if (!mlx)
		(write(2, "Error\nMalloc failed\n", 20), exit(1));
	mlx->mlx_ptr = mlx_init(WINDOW_WIDTH, WINDOW_HEIGHT, "cub3D", false);
	if (!mlx->mlx_ptr)
		(write(2, "Error\nMLX failed\n", 17), exit(1));
	mlx->mlx_img = mlx_new_image(mlx->mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	if (!mlx->mlx_img)
		(write(2, "Error\nMLX failed\n", 17), exit(1));
	mlx_image_to_window(mlx->mlx_ptr, mlx->mlx_img, 0, 0);
	mlx->fc = get_floor_color(data->parser->f);
	mlx->cc = get_ceiling_color(data->parser->c);
	return (mlx);
}

t_textures	*init_textures(t_data *data)
{
	t_textures	*textures;

	textures = malloc(sizeof(t_textures));
	if (!textures)
		exit(1);
	textures->door_img = mlx_load_png("./_textures/door.png");
	textures->north_img = mlx_load_png(data->parser->no);
	textures->south_img = mlx_load_png(data->parser->so);
	textures->west_img = mlx_load_png(data->parser->we);
	textures->east_img = mlx_load_png(data->parser->ea);
	if (!textures->north_img || !textures->south_img || !textures->west_img
		|| !textures->east_img || !textures->door_img)
		exit(1);
	return (textures);
}
