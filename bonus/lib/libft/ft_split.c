/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvoisin <mvoisin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:52:56 by mvoisin           #+#    #+#             */
/*   Updated: 2023/11/23 14:52:56 by mvoisin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_charset_in(char c, char charset)
{
	if (c == charset)
		return (1);
	return (0);
}

static int	count_words(const char *str, char charset)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	while (str[i])
	{
		while (str[i] != '\0' && ft_charset_in(str[i], charset) == 1)
			i++;
		if (str[i] != '\0')
			words++;
		while (str[i] != '\0' && ft_charset_in(str[i], charset) == 0)
			i++;
	}
	return (words);
}

static char	*ft_strdup_charset(const char *str, char charset)
{
	int		len;
	int		i;
	char	*string;

	len = 0;
	while (str[len] != '\0' && ft_charset_in(str[len], charset) == 0)
		len++;
	string = (char *)malloc(sizeof(char) * len + 1);
	if (!string)
		return (NULL);
	i = 0;
	while (i < len)
	{
		string[i] = str[i];
		i++;
	}
	string[i] = '\0';
	return (string);
}

static void	free_split(char **array)
{
	int	i;

	i = -1;
	while (array[++i])
		free(array[i]);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	int		i;

	i = -1;
	array = (char **)malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!array)
		return (NULL);
	while (*s)
	{
		while (*s && ft_charset_in(*s, c) == 1)
			s++;
		if (*s)
		{
			array[++i] = ft_strdup_charset(s, c);
			if (!array[i])
				return (free_split(array), NULL);
		}
		while (*s && ft_charset_in(*s, c) == 0)
			s++;
	}
	return (array[++i] = NULL, array);
}
