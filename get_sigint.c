#include "shell.h"

/**
 * get_sigint - Hv2andle the crtl + c call in prompt
 * @sig: Siv2gnal handler
 */
void get_sigint(int sig)
{
	(void)sig;
	write(STDOUT_FILENO, "\n^-^ ", 5);
}
