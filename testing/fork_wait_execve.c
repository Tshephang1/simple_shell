#include "main.h"

/**
*main - Create 5 child processes that execute "ls -l /tmp"
* Return: 0 on success and 1 on error
*/

int main(void)
{
	pid_t ch_pid;
	char *file_name = "/bin/ls";
	char *new_argv[] = { "-l", "/tmp", NULL };
	char *new_environ[] = { NULL };
	int _status = 0;
	unsigned int a;

	a = 0;
	while (a < 5)
	{
		ch_pid = fork();
		if (ch_pid == -1)
		{
			perror("Error:");
			return (1);
		}
		if (ch_pid == 0)
		{
			execve(file_name, new_argv, new_environ);
		}	wait(&_status);
		a++;
	}
	return (0);
}
