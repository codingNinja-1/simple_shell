#include "shell.h"

/**
 * fetchInput - Read  input from the input.
 *
 * Return:  allocated string containing  input.
 *
 * initializeBufferIfNeeded -  responsible for initializing the buffer if needed before reading user input.
 *
 * finalizeInputString - This function is called when the input string is complete, and it finalizes the dynamically allocated memory for the input string.
 *
 * appendToInputString - It returns the updated pointer to the input string.
 */
void *fetchInput(void)
{
static char buffer[BUFFER_SIZE];
static int bufferPosition, bufferSize;
char *inputString = NULL;

initializeBufferIfNeeded();

while (1)
{
if (bufferPosition >= bufferSize)
{

bufferSize = read(STDIN_FILENO, buffer, BUFFER_SIZE);
bufferPosition = 0;

if (bufferSize == 0)
{
return (inputString);
}
else if (bufferSize < 0)
{
perror("read");
return (NULL);
}
}

char currentCharacter = buffer[bufferPosition];

bufferPosition++;

if (currentCharacter == '\n')
{
inputString = finalizeInputString(inputString);
return (inputString);
}
else
{
inputString = appendToInputString(inputString, currentCharacter);
}
}
}

void *initializeBufferIfNeeded(void)
{
/**Add any necessary initialization code for the buffer here*/
}

char *finalizeInputString(char *inputString)
{
inputString = realloc(inputString, inputLength + 1);
if (inputString == NULL)
{
perror("realloc");
return (NULL);
}
inputString[inputLength] = '\0';
return (inputString);
}

char *appendToInputString(char *inputString, char currentCharacter)
{
inputString = realloc(inputString, inputLength + 1);
if (inputString == NULL)
{
perror("realloc");
return (NULL);
}
inputString[inputLength] = currentCharacter;
inputLength++;
return (inputString);
}
