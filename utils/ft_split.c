/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihaffout <ihaffout@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 19:39:54 by ihajouji          #+#    #+#             */
/*   Updated: 2024/10/03 13:54:16 by ihaffout         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../cub.h"

static char	*allocation(char *str, char c, int index)
{
	char	*result;
	int		i;
	int		j;
	int		count;

	i = 0;
	count = 0;
	j = index;
	while (str[j] && (str[j] != c))
	{
		count++;
		j++;
	}
	result = malloc(sizeof(char) * (count + 1));
	if (!result)
		return (NULL);
	while (i < count)
	{
		result[i] = str[index];
		i++;
		index++;
	}
	result[i] = '\0';
	return (result);
}

static char	**clear_arr(char **result, int j)
{
	while (j)
	{
		j--;
		free(result[j]);
	}
	free(result);
	return (NULL);
}

static int	string_count(char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] && (str[i] == c))
		i++;
	while (str[i])
	{
		count++;
		while (str[i] && (str[i] != c))
			i++;
		while (str[i] && str[i] == c)
			i++;
	}
	return (count);
}

static char	**process_string(char *s, char c, char **result)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			result[j] = allocation((char *)s, c, i);
			if (!result[j])
				return (clear_arr(result, j));
			while (s[i] && (s[i] != c))
				i++;
			j++;
		}
		else
			i++;
	}
	result[j] = NULL;
	return (result);
}

char	**ft_split(char *s, char c)
{
	char	**result;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!s)
		return (NULL);
	result = malloc(sizeof(char *) * (string_count((char *)s, c) + 1));
	if (!result)
		return (NULL);
	result = process_string(s, c, result);
	return (result);
}
