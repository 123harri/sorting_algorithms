#include "sort.h"
#include <stdbool.h>

void swap_node_ahead(listint_t **list, listint_t **tail, listint_t **current);
void swap_node_behind(listint_t **list, listint_t **tail, listint_t **current);
void cocktail_sort_list(listint_t **list);

/**
 * swap_node_ahead - Swap a node with the next node in a doubly-linked list.
 * @list: A pointer to the head of the list.
 * @tail: A pointer to the tail of the list.
 * @current: A pointer to the current node to swap.
 */
void swap_node_ahead(listint_t **list, listint_t **tail, listint_t **current)
{
	listint_t *tmp = (*current)->next;

	if ((*current)->prev != NULL)
		(*current)->prev->next = tmp;
	else
		*list = tmp;
	tmp->prev = (*current)->prev;
	(*current)->next = tmp->next;
	if (tmp->next != NULL)
		tmp->next->prev = *current;
	else
		*tail = *current;
	(*current)->prev = tmp;
	tmp->next = *current;
	*current = tmp;
}

/**
 * swap_node_behind - Swap a node with the
 * previous node in a doubly-linked list.
 * @list: A pointer to the head of the list.
 * @tail: A pointer to the tail of the list.
 * @current: A pointer to the current node to swap.
 */
void swap_node_behind(listint_t **list, listint_t **tail, listint_t **current)
{
	listint_t *tmp = (*current)->prev;

	if ((*current)->next != NULL)
		(*current)->next->prev = tmp;
	else
		*tail = tmp;
	tmp->next = (*current)->next;
	(*current)->prev = tmp->prev;
	if (tmp->prev != NULL)
		tmp->prev->next = *current;
	else
		*list = *current;
	(*current)->next = tmp;
	tmp->prev = *current;
	*current = tmp;
}

/**
 * cocktail_sort_list - Sort a doubly-linked list of integers using the
 *                     cocktail shaker sort algorithm.
 * @list: A pointer to the head of the list.
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *tail, *current;
	bool stirred = false;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (tail = *list; tail->next != NULL;)
		tail = tail->next;

	while (!stirred)
	{
		stirred = true;
		for (current = *list; current != tail; current = current->next)
		{
			if (current->n > current->next->n)
			{
				swap_node_ahead(list, &tail, &current);
				print_list((const listint_t *)*list);
				stirred = false;
			}
		}
		for (current = current->prev; current != *list; current = current->prev)
		{
			if (current->n < current->prev->n)
			{
				swap_node_behind(list, &tail, &current);
				print_list((const listint_t *)*list);
				stirred = false;
			}
		}
	}
}
