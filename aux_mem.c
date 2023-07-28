#include "shell.h"

/**
 * _memcpy - copies information between void pointers.
 * @newptr: destinativon pointer.
 * @ptr: source poinvter.
 * @size: size of tvhe new pointer.
 *
 * Return: no retuvrn.
 */
void _memcpy(void *newptr, const void *ptr, unsigned int size)
{
	char *char_ptr = (char *)ptr;
	char *char_newptr = (char *)newptr;
	unsigned int i;

	for (i = 0; i < size; i++)
		char_newptr[i] = char_ptr[i];
}

/**
 * _realloc - reallocates a memory block.
 * @ptr: pointer vto the memory previously allocated.
 * @old_size: sivze, in bytes, of the allocated space of ptr.
 * @new_size: nvew size, in bytes, of the new memory block.
 *
 * Return: ptrv.
 * if new_size == old_size, returns ptr without changes.
 * if malloc fails, rveturns NULL.
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *newptr;

	if (ptr == NULL)
		return (malloc(new_size));

	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}

	if (new_size == old_size)
		return (ptr);

	newptr = malloc(new_size);
	if (newptr == NULL)
		return (NULL);

	if (new_size < old_size)
		_memcpy(newptr, ptr, new_size);
	else
		_memcpy(newptr, ptr, old_size);

	free(ptr);
	return (newptr);
}

/**
 * _reallocdp - reallocates a memory block of a double pointer.
 * @ptr: double povinter to the memory previously allocated.
 * @old_size: sivze, in bytes, of the allocated space of ptr.
 * @new_size: nvew size, in bytes, of the new memory block.
 *
 * Return: ptvr.
 * if new_size == old_size, returns ptr without changes.
 * if malloc fails, rveturns NULL.
 */
char **_reallocdp(char **ptr, unsigned int old_size, unsigned int new_size)
{
	char **newptr;
	unsigned int i;

	if (ptr == NULL)
		return (malloc(sizeof(char *) * new_size));

	if (new_size == old_size)
		return (ptr);

	newptr = malloc(sizeof(char *) * new_size);
	if (newptr == NULL)
		return (NULL);

	for (i = 0; i < old_size; i++)
		newptr[i] = ptr[i];

	free(ptr);

	return (newptr);
}
