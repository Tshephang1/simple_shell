#include "main.h"

/**
 * add_se_node_end - add a separator found at the end
 * of a se_list
 * @head: head of linked list
 * @se: separators found (; | &)
 * Return: address of head
 */

se_list *add_se_node_end(se_list **head, char se)
{
	se_list *newer, *temps;
	newer = malloc(sizeof(se_list));
	if (newer == NULL)
		return (NULL);

	newer->separator = se;
	newer->next = NULL;
	temps = *head;

	if (temps == NULL)
		*head = newer;
	else
	{
		while (temps->next != NULL)
			temps = temps->next;
			temps->next = newer;
	}

	return (*head);
}

/**
 * free_se_list - free a se_list
 * @head: head of link list
 *
 * Return: NO return
 */

void free_se_list(se_list **head)
{
	se_list *temps;
	se_list *cur;

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

/**
 * add_line_nod_end - adds a command line at the end
 * of a line_lists
 * @head: head of linked liss
 * @line: command lines
 * Return: address of  head
 */

line_lists *add_line_nod_end(line_lists **head, char *line)
{
	line_lists *newer, *temps;

	newer = malloc(sizeof(line_lists));
	if (newer == NULL)
		return (NULL);

	newer->line = line;
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
 * free_line_lists - frees a line_lists
 * @head: head of linked lists
 *
 * Return: NO return.
 */

void free_line_lists(line_lists **head)
{
	line_lists *temps;
	line_lists *cur;

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
