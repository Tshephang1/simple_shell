#include "main.h"

/**
 * main - use path_list to put PATH directories in linked list
 *
 * Return: 0
 */

int main(void)
{
	char *_path;
	list_s *_list = NULL;
	list_s *_current;

	_path = _getenv("PATH");
	_list = path_list(_path, _list);
	_current = _list;

	while (_current->next != NULL)
	{
		printf("%s\n", _current->value);
		_current = _current->next;
	}

	free_list(_list);

	return (0);
}
