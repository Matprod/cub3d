/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 11:26:44 by matprod           #+#    #+#             */
/*   Updated: 2023/11/20 11:26:44 by matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (*(unsigned char *)(s + i) == (unsigned char)c)
			return ((void *)s + i);
		i++;
	}
	return (NULL);
}

/*#include <string.h> 
#include <stdio.h>

int main() {
    // Test 1 : Rechercher un caractère présent dans la chaîne
    char str1[] = "Hello, World!";
    char *result1 = (char *)ft_memchr(str1, 'W', strlen(str1));

    // Vérifier si le pointeur résultat est égal au pointeur attendu
    if (result1 != strchr(str1, 'W')) {
        printf("Test 1 a échoué : le caractère 'W' n'a pas été trouvé.\n");
        return 1;
    }

    // Test 2 : Rechercher un caractère non présent dans la chaîne
    char str2[] = "Hello, World!";
    char *result2 = (char *)ft_memchr(str2, 'X', strlen(str2));

    // Vérifier si le pointeur résultat est égal au pointeur attendu
    if (result2 != NULL) {
        printf("Test 2 a échoué \n");
        return 1;
    }

    // Test 3 : Rechercher un caractère dans une chaîne vide
    char str3[] = "";
    char *result3 = (char *)ft_memchr(str3, 'A', 0);

    // Vérifier si le pointeur résultat est égal à NULL (chaîne vide)
    if (result3 != NULL) {
        printf("Test 3 a échoué : la recherche n'a pas renvoyé NULL.\n");
        return 1; 
    }

    printf("Tous les tests ont réussi.\n");
    return 0;
}*/