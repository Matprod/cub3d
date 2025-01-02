/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 18:03:49 by matprod           #+#    #+#             */
/*   Updated: 2023/11/14 18:03:49 by matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char			*dup_str;
	unsigned int	index;
	unsigned int	length;

	length = ft_strlen(s);
	dup_str = malloc((length + 1) * sizeof(char));
	if (!dup_str)
		return (NULL);
	index = 0;
	while (index < length)
	{
		dup_str[index] = s[index];
		index ++;
	}
	dup_str[index] = '\0';
	return (dup_str);
}

/*#include <stdio.h> // Pour la fonction printf
#include <stdlib.h> // Pour la fonction free
#include <string.h> // Pour la fonction strcmp

int main()
{
    // Test : Dupliquer une chaîne non vide
    const char str1[] = "Dragon de metal!";
    char *dup_str1 = ft_strdup(str1);

    printf("Test 1:\n");
    printf("Chaîne source : %s\n", str1);
    printf("Chaîne dupliquée : %s\n", dup_str1);

    if (strcmp(str1, dup_str1) == 0)
        printf("Le test a réussi.\n");
    else
        printf("Le test a échoué.\n");

    free(dup_str1); 

    // Test : Dupliquer une chaîne vide
    const char str2[] = "";
    char *dup_str2 = ft_strdup(str2);

    printf("\nTest 2:\n");
    printf("Chaîne source : %s\n", str2);
    printf("Chaîne dupliquée : %s\n", dup_str2);


    if (strcmp(str2, dup_str2) == 0)
        printf("Le test a réussi.\n");
    else
        printf("Le test a échoué.\n");

    free(dup_str2);

    return 0;
}*/