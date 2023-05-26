#include "main.h"

/**
 * errors - print error based on case
 * @errorr: errorss number associated with perror statement
 *
 * Return: void
 */

void errors(int error)
{
	switch (error)
	{
	case 1: /* write a fork err to stderr */
		write(STDERR_FILENO, ERR_FORK, _strlens(ERR_FORK));
		perror("Error");
		break;

	case 2: /* write an execve err to stderr */
		perror("Error");
		break;

	case 3: /* write a malloc err to stderr */
		write(STDERR_FILENO, ERR_MALLOC, _strlens(ERR_MALLOC));
		break;

	case 4: /* write an empty path err to stderr */
		write(STDERR_FILENO, ERR_PATH, _strlens(ERR_PATH));
		break;

	default:
		return;
	}
}
