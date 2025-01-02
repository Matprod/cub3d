/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 16:34:31 by matprod           #+#    #+#             */
/*   Updated: 2023/11/14 16:34:31 by matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

/*#include <stdio.h> 

int main()
{
    const char str1[] = "four";
    size_t result1 = ft_strlen(str1);

    printf("Chaîne : %s\n", str1);
    printf("Longueur : %zu\n", result1);
}*/