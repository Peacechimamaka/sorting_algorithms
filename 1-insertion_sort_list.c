#include "sort.h"
#include <stdio.h>

void swap_node(listint_t **head, listint_t *node1, listint_t *node2)
{
	listint_t *temp = NULL;

	if (node1 == *head)
		*head = node2;

	temp = node1->prev;
	printf("%p\n", (void *)temp);
	if (temp != NULL)
		temp->next = node2;
	node1->next = node2->next;
	node2->next = node1;
	node2->prev = temp;
	node1->prev = node2;
}

void insertion_sort_list(listint_t **list)
{
	listint_t *node = NULL, *next_node = NULL;
	listint_t *swapped_node = NULL, *prev_node = NULL;

	if (*list != NULL)
	{
		node = *list;
		while (node->next != NULL)
		{
			next_node = node->next;
			if (node->n > next_node->n)
			{
				swap_node(list, node, next_node);
				print_list(*list);
				node = node->prev;
				swapped_node = node->prev;
				while (swapped_node != NULL &&
						swapped_node->prev != NULL)
				{
					prev_node = swapped_node->prev;
					if (swapped_node->n < prev_node->n)
					{
						swap_node(list, prev_node, swapped_node);
						print_list(*list);
						printf("INNER LOOP -> %d\n", node->n);
					}
					else
					{
						break;
					}
				}
			}
			printf("OUTER LOOP -> %d\n", node->n);
			node = node->next;
		}
	}
}
