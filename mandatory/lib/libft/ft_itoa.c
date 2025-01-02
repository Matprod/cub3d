/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:05:52 by matprod           #+#    #+#             */
/*   Updated: 2023/11/16 14:05:52 by matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_len(long nb)
{
	size_t	len;

	len = 0;
	if (nb < 0)
	{
		nb = nb * (-1);
		len = 1;
	}
	if (nb == 0)
		len = 1;
	else
	{
		while (nb)
		{
			nb = nb / 10;
			len++;
		}
	}
	return (len);
}

char	*ft_itoa(int n)
{
	size_t		len;
	long		nb;
	char		*str;
	size_t		is_negative;

	len = ft_len((long) n);
	str = (char *) malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	nb = (long) n;
	is_negative = 0;
	if (nb < 0)
	{
		nb = nb * (-1);
		str[0] = '-';
		is_negative = 1;
	}
	str[len] = '\0';
	while (len > is_negative)
	{
		str[len - 1] = nb % 10 + '0';
		nb = nb / 10;
		len--;
	}
	return (str);
}

/*#include <stdlib.h> 
#include <string.h> 
#include <stdio.h>

size_t ft_len(long nb);
char *ft_itoa(int n);

int main() {
    // Test 1 : Convertir un nombre positif en chaîne de caractères
    int num1 = 00000;
    char *str1 = ft_itoa(num1);

    if (strcmp(str1, "0") != 0) {
        printf("Test 1 a échoué \n", num1);
        free(str1);
        return 1; 
    }

    free(str1);

    // Test 2 : Convertir un nombre négatif en chaîne de caractères
    int num2 = -9876;
    char *str2 = ft_itoa(num2);

    // Vérifier si la chaîne de caractères est égale à la représentation attendue
    if (strcmp(str2, "-9876") != 0) {
        printf("Test 2 a échoué \n", num2);
        free(str2);
        return 1; 
    }

    free(str2);

    // Test 3 : Convertir le nombre zéro en chaîne de caractères
    int num3 = 0;
    char *str3 = ft_itoa(num3);

    // Vérifier si la chaîne de caractères est égale à la représentation attendue
    if (strcmp(str3, "0") != 0) {
        printf("Test 3 a échoué \n", num3);
        free(str3);
        return 1; // Indiquer une erreur
    }

    free(str3);

    printf("Tous les tests ont réussi.\n");
    return 0;
}*/