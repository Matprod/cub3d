/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:56:47 by matprod           #+#    #+#             */
/*   Updated: 2023/11/14 14:56:47 by matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;

	i = 0;
	while (i < len)
	{
		*(unsigned char *)(b + i) = c;
		i++;
	}
	return (b);
}

/*#include <string.h> 
#include <stdlib.h> 
#include <stdio.h>
#include <stdlib.h>

void *ft_memset(void *b, int c, size_t len);

#include <stdio.h>
#include <string.h> // Pour utiliser la fonction memset

// Déclaration de la fonction ft_memset
void	*ft_memset(void *b, int c, size_t len);

int main() {
    // Données de test
    char str1[20];
    char str2[20];
    int value = 'A';
    size_t size = 10;

    // Utilisation de ft_memset
    ft_memset(str1, value, size);

    // Utilisation de memset pour la comparaison
    memset(str2, value, size);

    // Comparaison des résultats
    if (memcmp(str1, str2, size) == 0) {
        printf("ft_memset a produit le même résultat que memset.\n");
    } else {
        printf("ft_memset n'a pas produit le même résultat que memset.\n");
    }

    return 0;
}*/