/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 22:45:24 by matprod           #+#    #+#             */
/*   Updated: 2023/11/16 22:45:24 by matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*ret;

	ret = NULL;
	while (*s)
	{
		if (*s == (char)c)
			ret = (char *)s;
		s ++;
	}
	if (*s == (char)c)
		ret = (char *)s;
	return (ret);
}

/*#include <stdio.h> 


int main() {
    // Test 1 : Recherche du caractère 'o' dans une chaîne
    const char str1[] = "Dragon de metal";
    int char1 = 'm';
    char *result1 = ft_strrchr(str1, char1);

    printf("Test 1:\n");
    printf("Chaîne : %s\n", str1);
    printf("Caractère recherché : %c\n", char1);
    printf("Résultat : %s\n", result1);

    // Test 2 : Recherche d'un caractère inexistant
    const char str2[] = "dragon de metal";
    int char2 = 'x';
    char *result2 = ft_strrchr(str2, char2);

    printf("\nTest 2:\n");
    printf("Chaîne : %s\n", str2);
    printf("Caractère recherché : %c\n", char2);
    printf("Résultat : %s\n", result2);

    return 0;
}*/