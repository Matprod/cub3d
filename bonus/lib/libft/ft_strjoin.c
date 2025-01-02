/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 17:23:05 by matprod           #+#    #+#             */
/*   Updated: 2023/11/14 17:23:05 by matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*dest;
	size_t	len_s1;
	size_t	len_s2;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	dest = (char *)malloc(len_s1 + len_s2 + 1);
	if (dest == NULL)
		return (NULL);
	ft_strlcpy(dest, s1, len_s1 + len_s2 + 1);
	ft_strlcat(dest, s2, len_s1 + len_s2 + 1);
	return (dest);
}

/*#include <stdio.h>
#include <stdlib.h>

int main()
{

	const char str1[] = "Hello, ";
	const char str2[] = "World!";
	char *result = ft_strjoin(str1, str2);

	printf("Chaîne 1 : %s\n", str1);
	printf("Chaîne 2 : %s\n", str2);
	printf("Résultat de la concaténation : %s\n", result);

	free(result);

	return 0;
}*/