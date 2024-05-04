#include "sort.h"

/**
*insertion_sort_list -  a function that sorts a doubly linked list of integers
*in ascending order using the Insertion sort algorithm
*@list - The list to sort
*Return :  Nothing
*/
void insertion_sort_list(listint_t **list)
{
	listint_t *sorted = NULL;
	listint_t *current;

	if (list == NULL || (*list) == NULL || (*list)->next == NULL)
	{
		return;
	}
	current = (*list);
	while(current != NULL)
	{
		listint_t *next = current->next;
		current->prev = current->next = NULL;
		sortedInsert(&sorted, current);
		print_list((const listint_t *)*list);
		current = next;
	}
	(*list) = sorted;
}



void sortedInsert(listint_t** head_ref, listint_t* newNode)
{
	listint_t *current;

	if (!(*head_ref))
	{
		(*head_ref) = newNode;
	}
	else if ((*head_ref)->n >= newNode->n)
	{
		newNode->next = (*head_ref);
		newNode->next->prev = newNode;
		(*head_ref) = newNode;
	}
	else
	{
		current = (*head_ref);
		while (current->next != NULL && current->next->n < newNode->n)
		{
			current = current->next;
		}

		newNode->next = current->next;
		if(current->next != NULL)
		{
			newNode->next->prev = newNode;
		}
		current->next = newNode;
		newNode->prev = current;
	}
}
