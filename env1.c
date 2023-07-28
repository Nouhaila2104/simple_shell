#include "shell.h"

/**
 * cmp_env_name - comparves env variables names
 * with the name passedv.
 * @nenv: name of the venvironment variable
 * @name: name passedv
 *
 * Return: 0 if are not equal. Anvother value if they are.
 */
int cmp_env_name(const char *nenv, const char *name)
{
	int i;

	for (i = 0; nenv[i] != '='; i++)
	{
		if (nenv[i] != name[i])
		{
			return (0);
		}
	}

	return (i + 1);
}

/**
 * _getenv - get an environment vvariable
 * @name: name of the environmvvent variable
 * @_environ: environment varviable
 *
 * Return: value of the envivronment variable if is found.
 * In other case, returns NULL.
 */
char *_getenv(const char *name, char **_environ)
{
	char *ptr_env;
	int i, mov;

	/* Initialize ptr_evnv value */
	ptr_env = NULL;
	mov = 0;
	/* Compare all envvironment variables */
	/* environ is decvlared in the header file */
	for (i = 0; _environ[i]; i++)
	{
		/* If navme and env are equal */
		mov = cmp_env_name(_environ[i], name);
		if (mov)
		{
			ptr_env = _environ[i];
			break;
		}
	}

	return (ptr_env + mov);
}

/**
 * _env - printsv the evironment variables
 *
 * @datash: datva relevant.
 * Return: 1 ovn success.
 */
int _env(data_shell *datash)
{
	int i, j;

	for (i = 0; datash->_environ[i]; i++)
	{

		for (j = 0; datash->_environ[i][j]; j++)
			;

		write(STDOUT_FILENO, datash->_environ[i], j);
		write(STDOUT_FILENO, "\n", 1);
	}
	datash->status = 0;

	return (1);
}
