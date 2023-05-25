#include "main.h"

/**
 * add_rvars_node - add a variable at the end
 * of a r_vars list
 * @head: head of linked lists
 * @lvars: length of the variables
 * @vals: value of the variables
 * @lvals: length of the values
 * Return: address of head
 */

r_vars *add_rvars_node(r_vars **head, int lvars, char *vals, int lvals)
{
	r_vars *newer, *temps;

	newer = malloc(sizeof(r_vars));
	if (newer == NULL)
		return (NULL);

	newer->len_vars = lvars;
	newer->vals = vals;
	newer->len_vals = lvals;
	newer->next = NULL;
	temps = *head;

	if (temps == NULL)
	{
		*head = newer;
	}
	else
	{
		while (temps->next != NULL)
			temps = temps->next;
		temps->next = newer;
	}
	return (*head);
}

/**
 * free_rvars_list - frees a r_vars list
 * @head: head of linked liss
 *
 * Return: NO return
 */

void free_rvars_list(r_vars **head)
{
	r_vars *temps;
	r_vars *cur;

	if (head != NULL)
	{
		cur = *head;
		while ((temps = cur) != NULL)
		{
			cur = cur->next;
			free(temps);
		}
		*head = NULL;
	}
}
