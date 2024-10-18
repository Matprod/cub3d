/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matprod <matprod@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 22:24:59 by matprod           #+#    #+#             */
/*   Updated: 2023/11/21 22:24:59 by matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		*(unsigned char *)(s + i) = 0;
		i++;
	}
}

/*#include <stdio.h>

int main() {
	// Test 1 : Initialiser un tableau de 5 entiers à zéro
	int arr1[5] = {1, 2, 3, 4, 5};
	ft_bzero(arr1, sizeof(int) * 5);

	// Vérifier si tous les éléments du tableau sont maintenant à zéro
	size_t i = 0;
	while (i < 5) {
		if (arr1[i] != 0) {
			printf("Test 1 a échoué : arr1[%zu] n'est pas égal à zéro\n", i);
			return 1; // Indiquer une erreur
		}
		i++;
	}

	// Test 2 : Initialiser une chaîne de caractères à zéro
	char str[10] = "Hello";
	ft_bzero(str, 5);

	// Vérifier si tous les caractères de la chaîne sont maintenant à zéro
	i = 0;
	while (i < 5) {
		if (str[i] != 0) {
			printf("Test 2 a échoué : str[%zu] n'est pas égal à zéro\n", i);
			return 1; // Indiquer une erreur
		}
		i++;
	}

	printf("Tous les tests ont réussi.\n");
	return 0;
}*/