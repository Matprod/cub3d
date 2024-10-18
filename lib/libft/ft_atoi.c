/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:52:21 by matprod           #+#    #+#             */
/*   Updated: 2023/11/14 14:52:21 by matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	result;
	int	sign;

	result = 0;
	sign = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
		result = (result * 10) + *str++ - '0';
	return (result * sign);
}

/*#include <stdio.h>

int main() {
	const char *str0 = "123";
	const char *str1 = "   234abc";
	const char *str2 = "2147483648";
	const char *str3 = "";

	printf("%d\n", ft_atoi(str0));  // Devrait afficher 123
	printf("%d\n", ft_atoi(str1));  // Devrait afficher 234
	printf("%d\n", ft_atoi(str2));  // Devrait afficher INT_MAX + 1
	printf("%d\n", ft_atoi(str3));  // Devrait afficher 0

	const char *str4 = "+";
	const char *str5 = "-";

	printf("%d\n", ft_atoi(str4));  // Devrait afficher 0
	printf("%d\n", ft_atoi(str5));  // Devrait afficher 0

	return 0;
}*/