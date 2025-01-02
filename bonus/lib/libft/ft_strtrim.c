/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 23:09:20 by matprod           #+#    #+#             */
/*   Updated: 2023/11/16 23:09:20 by matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static	int	ft_charset_in(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	i;
	size_t	start;
	size_t	end;

	start = 0;
	while (s1[start] && ft_charset_in(s1[start], set))
		start++;
	end = ft_strlen(s1);
	while (end > start && ft_charset_in(s1[end - 1], set))
		end--;
	str = (char *)malloc(sizeof(*s1) * (end - start + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (start < end)
		str[i++] = s1[start++];
	str[i] = 0;
	return (str);
}

/*#include <stdio.h>
#include <stdlib.h>

int main()
{
	// Test : Supprimer les espaces au début et à la fin d'une chaîne
	const char str1[] = "lolluol de lollol";
	const char set1[] = "lol";
	char *result1 = ft_strtrim(str1, set1);

	printf("Test 1:\n");
	printf("Chaîne d'origine : \"%s\"\n", str1);
	printf("Ensemble de caractères à supprimer : \"%s\"\n", set1);
	printf("Résultat : \"%s\"\n", result1);

	free(result1);

	const char str2[] = "xxdragon xdex metalxx";
	const char set2[] = "x";
	char *result2 = ft_strtrim(str2, set2);

	printf("\nTest 2:\n");
	printf("Chaîne d'origine : \"%s\"\n", str2);
	printf("Ensemble de caractères à supprimer : \"%s\"\n", set2);
	printf("Résultat : \"%s\"\n", result2);

	free(result2);

	return 0;
}*/