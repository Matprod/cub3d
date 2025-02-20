/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   singleton.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allan <allan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/22 20:49:16 by allan             #+#    #+#             */
/*   Updated: 2025/02/20 16:21:40 by allan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

t_singleton	*get_singleton_list(void)
{
	static t_singleton	*list = NULL;

	if (list == NULL)
	{
		list = (t_singleton *)malloc(sizeof(t_singleton));
		if (list == NULL)
			return (error_msg(ERROR_MALLOC), NULL);
		list->head = NULL;
	}
	return (list);
}

bool	add_singleton_data(void *data, t_ptr_types data_type)
{
	t_node		*new_node;
	t_singleton	*list;

	list = get_singleton_list();
	if (!list)
		return (ERROR);
	new_node = (t_node *)malloc(sizeof(t_node));
	if (!new_node)
	{
		free_singleton_list();
		return (error_msg(ERROR_MALLOC), ERROR);
	}
	new_node->data = data;
	new_node->type = data_type;
	new_node->next = list->head;
	list->head = new_node;
	return (SUCCESS);
}

bool	free_singleton_list(void)
{
	t_node		*current;
	t_node		*next;
	t_singleton	*list;

	list = get_singleton_list();
	if (!list)
		return (ERROR);
	current = list->head;
	while (current != NULL)
	{
		next = current->next;
		free_singleton_data(current);
		free(current);
		current = next;
	}
	list->head = NULL;
	free(list);
	return (SUCCESS);
}

void	free_singleton_data(t_node *current)
{
	if (!current || !current->data)
		return ;
	if (current->type == DOUBLE_PTR)
		free_array((char **)current->data);
	else
		free(current->data);
}
