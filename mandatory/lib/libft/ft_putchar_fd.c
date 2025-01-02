/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pucharfd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 12:53:23 by matprod           #+#    #+#             */
/*   Updated: 2023/11/16 12:53:23 by matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

/*#include <unistd.h> // Pour la fonction write

void ft_putchar_fd(char c, int fd);

int main() 
{

    char ch = 'A';
    ft_putchar_fd(ch, 1);


}*/