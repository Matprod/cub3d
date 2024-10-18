/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 18:23:14 by matprod           #+#    #+#             */
/*   Updated: 2023/11/15 18:23:14 by matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0 || dst == src)
		return (dst);
	while (i < n)
	{
		*(unsigned char *)(dst + i) = *(unsigned char *)(src + i);
		i++;
	}
	return (dst);
}

/*#include <string.h> 
#include <stdlib.h> 
#include <stdio.h>

void *ft_memcpy(void *dst, const void *src, size_t n);

int main() {
    // Test 1 : Copier une chaîne de caractères dans une autre
    char src1[] = "Hello, World!";
    char dst1[20];
    ft_memcpy(dst1, src1, strlen(src1) + 1); // Copie également le caractère nul

    // Vérifier si la chaîne copiée est égale à la chaîne source
    if (strcmp(dst1, src1) != 0) {
        printf(" 1 la chaîne copiée n'est pas égale à la chaîne source.\n");
        return 1;
    }

    // Test 2 : Copier une partie d'un tableau d'entiers
    int src2[] = {1, 2, 3, 4, 5};
    int dst2[5];
    ft_memcpy(dst2, src2, 3 * sizeof(int)); // Copie les trois premiers éléments

    // Vérifier si la partie copiée est égale à la partie source
    if (memcmp(dst2, src2, 3 * sizeof(int)) != 0) {
        printf("2 la partie copiée n'est pas égale à la partie source.\n");
        return 1; 
    }

    printf("Tous les tests ont réussi.\n");
    return 0;
}*/