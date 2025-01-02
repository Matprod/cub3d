/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 16:54:42 by matprod           #+#    #+#             */
/*   Updated: 2023/12/04 21:10:29 by Matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*new;
	unsigned int	i;

	if (start >= ft_strlen(s))
		len = 0;
	else if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	new = malloc(sizeof(char) * (len + 1));
	if (!new)
		return (NULL);
	i = 0;
	while (start + i < ft_strlen(s) && i < len)
	{
		new[i] = s[start + i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

/*#include <stdio.h>
#include <stdlib.h>

char	*ft_substr(const char *s, unsigned int start, size_t len);

int main(void) {
    const char *original = "Hello, World!";
    unsigned int i = 7;
    size_t len = 5;

    char *substr = ft_substr(original, i, len);

    if (substr) {
        printf("Original String: %s\n", original);
        printf("substr (i=%u, len=%zu): %s\n", i, len, substr);

        // Remember to free the allocated memory
        free(substr);
    } else {
        printf("Error: Unable to create substr.\n");
    }

    return 0;
}*/
