#include "list.h"

/**
 * string_length - Finds the length of a string.
 * @str: The string to find the length of.
 *
 * Return: The length of the string as an integer.
 */
int string_length(char *str)
{
	int count = 0;

	for (count = 0; str[count]; count++)
		continue;
	return (count);
}

/**
 * add_node_end - Adds a new node to the end of a double circular linked list.
 * @list: Pointer to the double circular linked list to modify.
 * @str: The string to copy into the new node.
 *
 * Return: The address of the new node or NULL on failure.
 */
List *add_node_end(List **list, char *str)
{
	List *new_node = NULL;
	int i = 0;

	if (list == NULL)
		return (NULL);

	new_node = malloc(sizeof(List));
	if (new_node == NULL)
		return (NULL);

	new_node->str = malloc(sizeof(char) * (string_length(str) + 1));
	if (new_node->str == NULL)
	{
		free(new_node);
		return (NULL);
	}
	for (i = 0; str[i]; i++)
		new_node->str[i] = str[i];
	new_node->str[i] = '\0';

	if (*list == NULL)
	{
		new_node->prev = new_node;
		new_node->next = new_node;
		*list = new_node;
	}
	else
	{
		new_node->prev = (*list)->prev;
		(*list)->prev->next = new_node;
		(*list)->prev = new_node;
		new_node->next = *list;
	}

	return (new_node);
}

/**
 * add_node_begin - Adds a new node to the start of a d2 circular linked list.
 * @list: Pointer to the double circular linked list to modify.
 * @str: The string to copy into the new node.
 *
 * Return: The address of the new node or NULL on failure.
 */
List *add_node_begin(List **list, char *str)
{
	List *new_node = NULL;
	int i = 0;

	if (list == NULL)
		return (NULL);

	new_node = malloc(sizeof(List));
	if (new_node == NULL)
		return (NULL);

	new_node->str = malloc(sizeof(char) * (string_length(str) + 1));
	if (new_node->str == NULL)
	{
		free(new_node);
		return (NULL);
	}
	for (i = 0; str[i]; i++)
		new_node->str[i] = str[i];
	new_node->str[i] = '\0';

	if (*list == NULL)
	{
		new_node->prev = new_node;
		new_node->next = new_node;
	}
	else
	{
		new_node->prev = (*list)->prev;
		(*list)->prev->next = new_node;
		(*list)->prev = new_node;
		new_node->next = *list;
	}
	*list = new_node;

	return (new_node);
}
