#ifndef LIST_H
#define LIST_H

/* INCLUDED LIBRARIES */
#include <stdio.h>
#include <stdlib.h>

/* DEFINITIONS AND STRUCTS */
/**
 * struct List - Doubly linked list node
 * @str: The string stored in the node (malloc'ed string)
 * @prev: Pointer to the previous node
 * @next: Pointer to the next node
 *
 * Description: Structure for a doubly linked list node.
 */
typedef struct List
{
	char *str;
	struct List *prev;
	struct List *next;
} List;

/**
 * string_length - Finds the length of a string.
 * @str: The string to find the length of.
 *
 * Return: The length of the string as an integer.
 */
int string_length(char *str);

/**
 * add_node_end - Adds a new node to the end of a double circular linked list.
 * @list: Pointer to the double circular linked list to modify.
 * @str: The string to copy into the new node.
 *
 * Return: The address of the new node or NULL on failure.
 */
List *add_node_end(List **list, char *str);

/**
 * add_node_begin - Adds a new node to the start of a d2 circular linked list.
 * @list: Pointer to the double circular linked list to modify.
 * @str: The string to copy into the new node.
 *
 * Return: The address of the new node or NULL on failure.
 */
List *add_node_begin(List **list, char *str);

#endif /* LIST_H */
