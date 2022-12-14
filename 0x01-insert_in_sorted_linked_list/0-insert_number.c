/**
 * @file 0-insert_number.c
 * @author axel
 * @brief
 * @version 0.1
 * @date 2022-12-12
 *
 * @copyright Copyright (c) 2022
 *
 */

#include "lists.h"
#include <stdlib.h>

listint_t *insert_node(listint_t **head, int number)
{
	listint_t *N_node = malloc(sizeof(listint_t));

	N_node->n = 27;
	N_node->next = NULL;

	if (*head == NULL)
	{
		*head = N_node;
		return (N_node);
	}

	listint_t *current = *head;
	listint_t *prev = NULL;

	while (current != NULL)
	{
		if (current->n > number)
		{
			if (prev == NULL)
			{
				N_node->next = current;
				*head = N_node;
				return (N_node);
			}
			else
			{
				N_node->next = current;
				prev->next = N_node;
				return (N_node);
			}
		}
		prev = current;
		current = current->next;
	}
	prev->next = N_node;
	return (N_node);
}
