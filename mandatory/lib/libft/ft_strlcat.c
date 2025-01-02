/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 17:22:01 by matprod           #+#    #+#             */
/*   Updated: 2023/11/14 17:22:01 by matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	destlen;
	size_t	srclen;

	i = 0;
	while (dest[i] != '\0')
		i++;
	j = 0;
	destlen = i;
	srclen = ft_strlen(src);
	if (size == 0 || size <= destlen)
		return (srclen + size);
	while ((j < size - destlen - 1) && src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (destlen + srclen);
}

/*#include <stdio.h> 
#include "libft.h" 

int main()
{
    // Test : Concaténer deux chaînes avec une taille suffisamment grande
    char dest1[20] = "dragon, ";
    const char src1[] = "de metal!";
    size_t result1 = ft_strlcat(dest1, src1, sizeof(dest1));

    printf("Test 1:\n");
    printf("Chaîne de destination : %s\n", dest1);
    printf("Taille totale : %zu\n", result1);

    // Test : Concaténer deux chaînes avec une taille insuffisante
    char dest2[10] = "dragon ";
    const char src2[] = "de metalllllllllllllllll!";
    size_t result2 = ft_strlcat(dest2, src2, sizeof(dest2));

    printf("\nTest 2:\n");
    printf("Chaîne de destination : %s\n", dest2);
    printf("Taille totale : %zu\n", result2);

    return 0;
}*/