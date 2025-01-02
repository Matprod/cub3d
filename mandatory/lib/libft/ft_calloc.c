/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 11:42:23 by matprod           #+#    #+#             */
/*   Updated: 2023/11/20 11:42:23 by matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
//4 4
//
void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if (nmemb == 0 || size == 0)
		return (NULL);
	if (size > __SIZE_MAX__ / nmemb)
		return (NULL);
	ptr = malloc(nmemb * size);
	if (ptr == (NULL))
		return (NULL);
	ft_memset(ptr, 0, nmemb * size);
	return (ptr);
}

/*#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int main()
{
	// Test 1 : Allouer et initialiser un tableau de 5 entiers à zéro
	int *arr1 = (int *)ft_calloc(5, sizeof(int));

	// Vérifier si tous les éléments du tableau sont à zéro
	size_t i = 0;
	while (i < 5)
	{
		if (arr1[i] != 0)
		{
			printf("Test 1 a échoué : arr1[%zu] n'est pas égal à zéro\n", i);
			free(arr1);
			return 1; // Indiquer une erreur
		}
		i++;
	}

	free(arr1);

	// Test 2 : Allouer et initialiser une chaîne de caractères à zéro
	char *str = (char *)ft_calloc(10, sizeof(char));

	// Vérifier si tous les caractères de la chaîne sont à zéro
	i = 0;
	while (i < 10)
	{
		if (str[i] != 0)
		{
			printf("Test 2 a échoué : str[%zu] n'est pas égal à zéro\n", i);
			free(str);
			return 1; // Indiquer une erreur
		}
		i++;
	}

	free(str);

	printf("Tous les tests ont réussi.\n");
	return 0;
}*/