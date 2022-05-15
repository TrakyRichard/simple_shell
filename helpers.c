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

/**
 * displayHelpMenu - displays available help options
 * Return: Always 1
 */
int displayHelpMenu(void)
{
  char str[81] = "Type help [built-in]\n\nIncluded built-ins:";
  char *str2 = "\n\n\texit\n\tenv\n\tcd\n\tsetenv\n\tunsetenv\n\thelp\n";

  _strcat(str, str2);
  write(STDOUT_FILENO, str, _strlen(str));
  return (1);
}

/**
 * helpExit - instructions on how to exit
 * @build: input build
 * Return: Always 1
 */
int helpExit(config *build)
{
  char str[82] = "exit: exit [n]\n\tExit the shell.\n\n\t";
  char *str2 = "Exit with a status of n, or if n is omitted, 0.\n";

  (void)build;
  _strcat(str, str2);
  write(STDOUT_FILENO, str, _strlen(str));
  return (1);
}

/**
 * helpEnv - instructions on how to exit
 * @build: input build
 * Return: Always 1
 */
int helpEnv(config *build)
{
  char str[] = "env: env\n\tPrint the environment.\n";

  (void)build;
  write(STDOUT_FILENO, str, _strlen(str));
  return (1);
}

/**
 * helpHistory - instructions on how to exit
 * @build: input build
 * Return: Always 1
 */
int helpHistory(config *build)
{
  char str[] = "history: history\n\tNot supported in this version.\n";

  (void)build;
  write(STDOUT_FILENO, str, _strlen(str));
  return (1);
}

/**
 * helpAlias - instructions on how to exit
 * @build: input build
 * Return: Always 1
 */
int helpAlias(config *build)
{
  char str[] = "alias: alias\n\tNot supported in this version.\n";

  (void)build;
  write(STDOUT_FILENO, str, _strlen(str));
  return (1);
}

/**
 * helpCd - instructions on how to exit
 * @build: input build
 * Return: Always 1
 */
int helpCd(config *build)
{
  char str[192] = "cd: cd [destination]\n\t";
  char *str2 = "Change directory to target destination.\n\t";
  char *str3 = "If [destination] is ommitted, user will taken to home.\n\t";
  char *str4 = "If \"-\" is used as second argument, user will be taken to ";
  char *str5 = "last directory.\n";

  (void)build;
  _strcat(str, str2);
  _strcat(str, str3);
  _strcat(str, str4);
  _strcat(str, str5);
  write(STDOUT_FILENO, str, _strlen(str));
  return (1);
}

/**
 * helpSetenv - instructions on how to exit
 * @build: input build
 * Return: Always 1
 */
int helpSetenv(config *build)
{
  char str[186] = "setenv: setenv [var] [value]\n\t";
  char *str2 = "Set or update a variable in the environment.\n\n\t";
  char *str3 = "Creates a variable [var] with [value]. ";
  char *str4 = "If the [var] already exists in the environment, ";
  char *str5 = "the value is updated.\n";

  (void)build;
  _strcat(str, str2);
  _strcat(str, str3);
  _strcat(str, str4);
  _strcat(str, str5);
  write(STDOUT_FILENO, str, _strlen(str));
  return (1);
}

/**
 * helpUnsetenv - instructions on how to exit
 * @build: input build
 * Return: Always 1
 */
int helpUnsetenv(config *build)
{
  char str[116] = "unsetenv: unsetenv [var]\n\t";
  char *str2 = "Unset a variable in the environment.\n\n\t";
  char *str3 = "[var] is an existing variable in the environment.\n";

  (void)build;
  _strcat(str, str2);
  _strcat(str, str3);
  write(STDOUT_FILENO, str, _strlen(str));
  return (1);
}

/**
 * helpHelp - instructions on how to exit
 * @build: input build
 * Return: Always 1
 */
int helpHelp(config *build)
{
  char str[129] = "help: help [built-in]\n\t";
  char *str2 = "Display information about built-in commands.\n\n\t";
  char *str3 = "If [built-in] is not specified, print a list of built-ins.\n";

  (void)build;
  _strcat(str, str2);
  _strcat(str, str3);
  write(STDOUT_FILENO, str, _strlen(str));
  return (1);
}
