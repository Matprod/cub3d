/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 11:53:31 by matprod           #+#    #+#             */
/*   Updated: 2024/10/03 17:23:11 by Matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (NULL);
}
/*#include <stdio.h>

int main(void)
{
	const char *str = "Hello, World!";
	int search_char = 'W';

	// Appel de la fonction ft_strchr
	char *result = ft_strchr(str, search_char);

	// Affichage du résultat
	if (result != NULL)
		printf("Caractère trouvé : %c\n", *result);
	else
		printf("Caractère non trouvé.\n");

	return 0;
}*/
