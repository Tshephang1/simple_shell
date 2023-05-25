#include "main.h"

/**
 * _memcpy - copies info between pointers
 * @nptr: destination to new pointer
 * @ptr: our pointer
 * @siz: size of new pointer
 *
 * Return: NO return
 */

void _memcpy(void *nptr, const void *ptr, unsigned int siz)
{
	char *charec_ptr = (char *)ptr;
	char *char_nptr = (char *)nptr;
	unsigned int a;

	for (a = 0; a < size; a++)
		char_nptr[a] = charec_ptr[a];
}

/**
 * _reallocs - reallocates memory blocks
 * @ptr: pointer to memory previously allocated
 * @old_siz: size in bytes of allocated space of pointer
 * @new_siz: new size in bytes of new memory blocks
 *
 * Return: pointer
 * if new_siz equals old_siz, returns pointer without changes
 * but if malloc fails, returns NULL
 */

void *_reallocs(void *ptr, unsigned int old_siz, unsigned int new_siz)
{
	void *nptr;

	if (ptr == NULL)
		return (malloc(new_siz));

	if (new_siz == 0)
	{
		free(ptr);
		return (NULL);
	}

	if (new_siz == old_siz)
		return (ptr);

	nptr = malloc(new_siz);
	if (nptr == NULL)
		return (NULL);

	if (new_siz < old_siz)
		_memcpy(nptr, ptr, new_siz);
	else
		_memcpy(nptr, ptr, old_siz);

	free(ptr);
	return (nptr);
}

/**
 * _reallocdps - reallocate a memory block of double pointer
 * @ptr: double pointer to memory previously allocate
 * @old_siz: size, in bytes, of allocated space of ptr
 * @new_siz: size, in bytes, of new memory block
 *
 * Return: ptr ,but,
 * if new_siz equals old_siz, return ptr without no changes
 * if malloc fail then return NULL
 */

char **_reallocdps(char **ptr, unsigned int old_siz, unsigned int new_siz)
{
	char **nptr;
	unsigned int a;

	if (ptr == NULL)
		return (malloc(sizeof(char *) * new_siz));

	if (new_siz == old_siz)
		return (ptr);

	nptr = malloc(sizeof(char *) * new_siz);
	if (nptr == NULL)
		return (NULL);

	for (a = 0; a < old_siz; a++)
		nptr[a] = ptr[a];

	free(ptr);

	return (nptr);
}
