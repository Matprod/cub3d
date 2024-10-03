/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 16:14:01 by Matprod           #+#    #+#             */
/*   Updated: 2024/10/03 17:44:01 by Matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	*ft_strjoin_gnl(char *s1, char const *s2)
{
	char	*dest;
	size_t	i;
	size_t	destlen;

	i = 0;
	destlen = ft_strlen(s1) + ft_strlen(s2);
	dest = malloc(destlen + 1 * sizeof(char));
	if (!dest)
		return (NULL);
	while (*(s1 + i))
	{
		*(dest + i) = *(s1 + i);
		i++;
	}
	while (*s2)
	{
		*(dest + i) = *s2++;
		i++;
	}
	*(dest + i) = '\0';
	free(s1);
	return (dest);
}

static char	*before_endline(char *stack)
{
	char			*line;
	unsigned int	len_before;
	unsigned int	i;

	len_before = 0;
	i = 0;
	if (!(*stack))
		return (NULL);
	while (stack[len_before] && stack[len_before] != '\n')
		len_before++;
	if (stack[len_before] == '\n')
		len_before++;
	line = malloc(sizeof(char) * (len_before + 1));
	if (!line)
		return (NULL);
	while (i < len_before)
	{
		line[i] = stack[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

static char	*after_endline(char *stack)
{
	char			*save;
	unsigned int	len_after;
	unsigned int	i;

	len_after = 0;
	i = 0;
	while (stack[len_after] && stack[len_after] != '\n')
		len_after++;
	if (!stack[len_after])
	{
		free(stack);
		return (NULL);
	}
	len_after++;
	save = malloc((ft_strlen(stack) - len_after + 1) * sizeof(char));
	if (!save)
		return (NULL);
	while (stack[len_after])
		save[i++] = stack[len_after++];
	save[i] = '\0';
	free(stack);
	return (save);
}

static char	*read_and_stock(int fd, char *stack)
{
	char	*buffer;
	int		readed;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	readed = 1;
	while (!ft_strchr(stack, '\n') && readed != 0)
	{
		readed = read(fd, buffer, BUFFER_SIZE);
		if (readed == -1)
		{
			free(buffer);
			free(stack);
			return (NULL);
		}
		buffer[readed] = '\0';
		if (stack != NULL)
			stack = ft_strjoin_gnl(stack, buffer);
		else
			stack = ft_strdup(buffer);
	}
	free(buffer);
	return (stack);
}

char	*get_next_line(int fd)
{
	static char	*stack;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stack = read_and_stock(fd, stack);
	if (!stack)
		return (NULL);
	line = before_endline(stack);
	stack = after_endline(stack);
	return (line);
}
/*#include <stdio.h>

 int main()
{
    int fd;
    char *line;
	int		nbline = 0;
    fd = open("text.txt", O_RDONLY);
    while ((line = get_next_line(fd)))
    {
        printf("Line %d :%s",nbline, line);
		nbline++;
        free(line);
    }

    close(fd);
    return (0);
}*/