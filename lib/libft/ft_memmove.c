/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 13:13:13 by matprod           #+#    #+#             */
/*   Updated: 2023/11/16 13:13:13 by matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	if (src < dest)
	{
		while (n)
		{
			((unsigned char *)dest)[n - 1] = ((unsigned char *)src)[n - 1];
			n --;
		}
	}
	else
		ft_memcpy(dest, src, n);
	return (dest);
}
/*#include <string.h> 
#include <stdlib.h> 
#include <stdio.h>

void *ft_memmove(void *dst, const void *src, size_t len);

int main() {
    // Test 1 : Déplacer une chaîne de caractères vers la droite
    char str1[] = "Hello, World!";
    char buffer1[20];
    ft_memmove(buffer1 + 5, str1, strlen(str1) + 1);

    // Vérifier si la chaîne déplacée est égale à la chaîne source
    if (strcmp(buffer1 + 5, str1) != 0) {
        printf("Test 1 a échoué ");
        return 1; 
    }

    // Test 2 : Déplacer une partie d'un tableau d'entiers vers la gauche
    int arr2[] = {1, 2, 3, 4, 5};
    int buffer2[5];
    ft_memmove(buffer2, arr2 + 2, 3 * sizeof(int)); 

    // Vérifier si la partie déplacée est égale à la partie source
    if (memcmp(buffer2, arr2 + 2, 3 * sizeof(int)) != 0) {
        printf("Test 2 a échoué : la partie déplacée n'est pas égale .\n");
        return 1; 
    }

    printf("Tous les tests ont réussi.\n");
    return 0;
}*/