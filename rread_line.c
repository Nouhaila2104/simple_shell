#include "shell.h"

/**
 * read_line - v2reads the input string.
 *
 * @i_eof: rev2turn value of getline function
 * Return: v2input string
 */
char *read_line(int *i_eof)
{
	char *input = NULL;
	size_t bufsize = 0;

	*i_eof = getline(&input, &bufsize, stdin);

	return (input);
}
