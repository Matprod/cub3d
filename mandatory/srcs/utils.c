/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 00:49:29 by Matprod           #+#    #+#             */
/*   Updated: 2025/02/21 00:49:48 by Matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int ft_isspace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' ||
			c == '\v' || c == '\f' || c == '\r');
}

void trim_leading_spaces(char *str)
{
    int i = 0;
    int j = 0;

    while (str[i] && ft_isspace((unsigned char)str[i]))
        i++;

    while (str[i])
        str[j++] = str[i++];

    str[j] = '\0';
}