#include "shell.h"

/**
 * fetchInput - Read user input from the standard input.
 *
 * Return: Dynamically allocated string containing user input.
 */
void *fetchInput(void)
{
    static char buffer[BUFFER_SIZE];
    static int bufferPosition, bufferSize;
    char *inputString = NULL;
    char currentCharacter;
    int inputLength = 0;

    while (1)
    {
        if (bufferPosition >= bufferSize)
        {
            bufferSize = read(STDIN_FILENO, buffer, BUFFER_SIZE);
            bufferPosition = 0;
            if (bufferSize == 0)
                return inputString;
            else if (bufferSize < 0)
            {
                perror("read");
                return NULL;
            }
        }

        currentCharacter = buffer[bufferPosition];
        bufferPosition++;

        if (currentCharacter == '\n')
        {
            inputString = realloc(inputString, inputLength + 1);
            if (inputString == NULL)
            {
                perror("realloc");
                return NULL;
            }
            inputString[inputLength] = '\0';
            return inputString;
        }
        else
        {
            inputString = realloc(inputString, inputLength + 1);
            if (inputString == NULL)
            {
                perror("realloc");
                return NULL;
            }
            inputString[inputLength] = currentCharacter;
            inputLength++;
        }
    }
}
