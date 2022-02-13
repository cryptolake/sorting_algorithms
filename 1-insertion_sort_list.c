#include "sort.h"
#include <stdio.h>

/**
 * swap_list - swap two adjacent linked list elements
 * @prevnode: previous node
 * @node: current node
 *
 * Return: 1 if head has changed, 0 if not
 **/
int swap_list(listint_t *prevnode, listint_t *node)
{
	listint_t *prev = prevnode->prev, *next = node->next;

	node->prev = prev;
	node->next = prevnode;

	prevnode->prev = node;
	prevnode->next = next;

	if (next != NULL)
	{
		next->prev = prevnode;
	}

	if (prev != NULL)
	{
		prev->next = node;
		return (0);
	}
	else
		return (1);
}

/**
 * insertion_sort_list - sort doubly linked list with insertion algorithm.
 * @list: head of list
 **/
void insertion_sort_list(listint_t **list)
{
	listint_t *head = *list;
	listint_t *node;

	while (head)
	{
		node = head;
		while (node->prev && node->prev->n > node->n)
		{
			if (swap_list(node->prev, node))
				*list = node;
			print_list(*list);
		}

		head = head->next;
	}
}
