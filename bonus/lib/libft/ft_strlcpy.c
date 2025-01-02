/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 17:27:34 by matprod           #+#    #+#             */
/*   Updated: 2023/11/14 17:27:34 by matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size > 0)
	{
		while (src[i] && i < (size - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = 0;
	}
	while (src[i])
		i++;
	return (i);
}

/*#include <stdio.h> 


int main()
{
    // Test : Copier une chaîne avec une taille de destination grande
    char dest1[20];
    const char src1[] = "Dragon de metal";
    size_t result1 = ft_strlcpy(dest1, src1, sizeof(dest1));

    printf("Test 1:\n");
    printf("Chaîne copiée : %s\n", dest1);
    printf("Taille totale : %zu\n", result1);

    // Test : Copier une chaîne avec une taille de destination insuffisante
    char dest2[10];
    const char src2[] = "Bonjour";
    size_t result2 = ft_strlcpy(dest2, src2, sizeof(dest2));

    printf("\nTest 2:\n");
    printf("Chaîne copiée : %s\n", dest2);
    printf("Taille totale : %zu\n", result2);

    return 0;
}*/
