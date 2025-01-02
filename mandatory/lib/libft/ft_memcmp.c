/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 18:29:54 by matprod           #+#    #+#             */
/*   Updated: 2023/11/15 18:29:54 by matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n && *(unsigned char *)(s1 + i) == *(unsigned char *)(s2 + i))
		i++;
	if (i < n)
		return (*(unsigned char *)(s1 + i) - *(unsigned char *)(s2 + i));
	return (0);
}

/*#include <string.h>
#include <stdio.h>
#include <stdlib.h>

int ft_memcmp(const void *s1, const void *s2, size_t n);

int main() {
    // Test 1 : Comparer deux chaînes identiques
    char str1[] = "Hello, World!";
    char str2[] = "Hello, World!";
    int result1 = ft_memcmp(str1, str2, strlen(str1));

    // Vérifier si le résultat est égal à 0 (chaînes identiques)
    if (result1 != 0) {
        printf("Test 1 a échoué\n");
        return 1;
    }

    // Test 2 : Comparer deux chaînes différentes
    char str3[] = "Hello, World!";
    char str4[] = "Hello, Universe!";
    int result2 = ft_memcmp(str3, str4, strlen(str3));

    // Vérifier si le résultat est différent de 0 (chaînes différentes)
    if (result2 == 0) {
        printf("Test 2 a échoué \n");
        return 1;
    }

    printf("Tous les tests ont réussi.\n");
    return 0;
}*/