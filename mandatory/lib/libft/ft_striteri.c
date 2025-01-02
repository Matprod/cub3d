/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 13:40:24 by matprod           #+#    #+#             */
/*   Updated: 2023/11/20 13:40:24 by matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	i = -1;
	if (!s || !f)
		return (NULL);
	while (s[++i])
		f(i, &s[i]);
	return (s);
}

/*#include <stdio.h>

void print_char_and_index(unsigned int index, char *c) {
	printf("Caractère à l'indice %u : %c\n", index, *c);
}

int main()
{

	char str[] = "Dragon de metal";
	printf("Chaîne originale : %s\n", str);

	ft_striteri(str, print_char_and_index);

	return 0;
}*/