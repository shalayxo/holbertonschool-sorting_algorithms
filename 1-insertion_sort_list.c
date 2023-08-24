#include "sort.h"

/**
 * swap_nodes - swap node elements in doubly linked list
 * @node1: listint_t node
 * @node2: listint_t node
 * Return: nthing
*/

void swap_nodes(listint_t **node1, listint_t **node2)
{
listint_t *next, *prev;

next = (*node2)->next;
prev = (*node1)->prev;
(*node2)->next = *node1;
(*node2)->prev = prev;
if (prev)
	prev->next = *node2;
(*node1)->next = next;
if (next)
	next->prev = *node1;
(*node1)->prev = *node2;
}

/**
 * insertion_sort_list - sorts a doubly linked list of
 * integers in ascending order
 * @list: head of the list
*/

void insertion_sort_list(listint_t **list)
{
listint_t *current, *first, *second, *temp;

if (list == NULL || *list == NULL)
	return;
current = *list;
while (current)
{
first = current;
second = current->next;
if (first && second && first->n > second->n)
{
swap_nodes(&first, &second);
if (second && second->prev == NULL)
	*list = second;
print_list(*list);
while (second && second->prev && second->n < second->prev->n)
{
temp = second->prev;
swap_nodes(&temp, &second);
if (second->prev == NULL)
	*list = second;
print_list(*list);
}
}
else
current = current->next;
}
}
