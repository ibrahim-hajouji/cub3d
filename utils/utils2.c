/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ihajouji <ihajouji@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 17:26:08 by ihaffout          #+#    #+#             */
/*   Updated: 2024/10/23 19:39:34 by ihajouji         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../cub.h"

int	ft_atoi(char *str)
{
	unsigned long long	number;
	int					sign;
	int					i;

	sign = 1;
	number = 0;
	i = skip_spaces(str, 0);
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign -= 2;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		number = number * 10 + str[i++] - 48;
		if (number > 9223372036854775807 && sign == 1)
			return (-1);
		else if (number > 9223372036854775807 && sign == -1)
			return (0);
	}
	i = skip_spaces(str, i);
	if (str[i])
		return (-1);
	return (number * sign);
}

int	is_space(char c)
{
	if (c == ' ' || c == '\t' || c == '\v' || c == '\f' || c == '\r')
		return (1);
	return (0);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (haystack[i])
	{
		j = 0;
		while (needle[j] == haystack[i + j] && i + j < len)
		{
			j++;
			if (needle[j] == '\0')
				return ((char *)haystack + i);
		}
		i++;
	}
	return (NULL);
}

int	ft_strcmp(char *s1, char *s2)
{
	size_t	i;

	i = 0;
	if (!s1 || !s2)
		return (-10);
	while ((s1[i] || s2[i]))
	{
		if (s1[i] > s2[i])
			return (1);
		else if (s1[i] < s2[i])
			return (-1);
		i++;
	}
	return (0);
}

char	*ft_strdup(char *s1)
{
	char	*s2;
	size_t	len;
	size_t	i;

	i = 0;
	len = ft_strlen(s1);
	s2 = malloc(len + 1);
	if (s2 == NULL)
		return (NULL);
	while (i < len)
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}
