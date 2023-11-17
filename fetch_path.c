#include "shell.h"

/**
 *fetchPath - fetchesthe value of the PATH  variable.
 *
 * Return: A pointer to the value of the PATH variable.
 */
char *retrievePath(void)
{
    return _getenv("PATH");
}
