#include "lists.h"
#include <stdlib.h>

/**
 * insert_node - inserts a number into a sorted singly linked list.
 * @head: pointer to the head of the list
 * @number: number to insert
 * Return: the address of the new node, or NULL if it failed
 */

listint_t *insert_node(listint_t **head, int number)
{
	listint_t *N_node = malloc(sizeof(listint_t));

	N_node->n = number;
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
