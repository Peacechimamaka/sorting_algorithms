#include "sort.h"

/**
 *swap_node - a function that swaps node
 *@head: pointer to tue first node
 *@node1: a node
 *@node2: a second node
 */

void swap_node(listint_t **head, listint_t *node1, listint_t *node2)
{
	/*If node1 is the head, update the head to node2*/
	if (node1->prev == NULL)
		*head = node2;

	/*Update the previous node's next pointer to node2*/
	if (node1->prev != NULL)
		node1->prev->next = node2;

	/*Update node2's previous pointer to node1's previous*/
	node2->prev = node1->prev;
	/*Update node1's next pointer to node2's next*/
	node1->next = node2->next;
	/*Update node1's previous pointer to node2*/
	node1->prev = node2;
	/*If node2 has a next node, update the next node's*/
	/* previous pointer to node1*/
	if (node2->next != NULL)
		node2->next->prev = node1;
	/*Update node2's next pointer to node1*/
	node2->next = node1;
}

void insertion_sort_list(listint_t **list)
{
	listint_t *node = NULL, *prev_node = NULL, *next_node = NULL;

	/*If the list is empty or has only one element, no sorting needed*/
	if (!list || !(*list) || !(*list)->next)
		return;

	node = (*list)->next;
	while (node != NULL)
	{
		prev_node = node->prev;
		next_node = node->next;
		/*Iterate backwards to find the correct position for the current node*/
		while (prev_node != NULL && node->n < prev_node->n)
		{
			swap_node(list, prev_node, node);
			print_list(*list);
			/*Update prev_node to continue checking for correct position*/
			prev_node = node->prev;
		}
		node = next_node;
	}
}
