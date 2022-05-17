#include "alx.h"

/**
 * insertNullByte - inserts null byte at given index
 * @str: input string
 * @index: index to insert null byte
 */
void insertNullByte(char *str, unsigned int index)
{
  str[index] = '\0';
}

/**
 * displayPrompt - displays shell prompt
 */
void displayPrompt(void)
{
  write(STDERR_FILENO, "$ ", 2);
}

/**
 * displayNewLine - displays new line
 */
void displayNewLine(void)
{
  write(STDOUT_FILENO, "\n", 1);
}

/**
 * sigintHandler - catches SIGINT signal and reset signal
 * @sigint: signal from stdint
 */
void sigintHandler(int sigint)
{
  (void)sigint;
  signal(SIGINT, sigintHandler);
  displayNewLine();
  displayPrompt();
  fflush(stdout);
}

/**
 * helpFunc - retrieves instruction on how to use builtin
 * @build: input build
 * Return: Always 1
 */
int helpFunc(config *build)
{
  type_b help_arr[] = {
      {"exit", helpExit},
      {"env", helpEnv},
      {"history", helpHistory},
      {"alias", helpAlias},
      {"cd", helpCd},
      {"setenv", helpSetenv},
      {"unsetenv", helpUnsetenv},
      {"help", helpHelp},
      {NULL, NULL}};
  register int i = 0, j = 1, argCount = countArgs(build->args);
  _Bool foundCommand = false;

  if (argCount == 1)
    return (displayHelpMenu());
  while (j < argCount)
  {
    i = 0;
    while (help_arr[i].command)
    {
      if (_strcmp(build->args[j], help_arr[i].command) == 0)
      {
        foundCommand = true;
        help_arr[i].func(build);
        break;
      }
      i++;
    }
    j++;
  }
  if (foundCommand == false)
  {
    errno = ENOBUILTIN;
    errorHandler(build);
  }
  return (1);
}
