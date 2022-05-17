#include "alx.h"

/**
 * errorHandler - prints error message for shell
 * @build: the build config
 */
void errorHandler(config *build)
{
	register int len;
	static char error[BUFSIZE];
	char *ptr, *alpha;

<<<<<<< HEAD
	alpha = itoa(build->lineCounter);
	_strcat(error, build->shellName);
	_strcat(error, ": ");
	_strcat(error, alpha);
	_strcat(error, ": ");
	_strcat(error, build->args[0]);
	_strcat(error, getErrorMessage());
	if (build->args[1])
	{
		if (errno != EBADCD)
			_strcat(error, ": ");
		_strcat(error, build->args[1]);
	}
	_strcat(error, "\n");
	ptr = _strchr(error, '\n');
	len = ptr - error;
	write(STDERR_FILENO, error, len + 1);
	free(alpha);
	insertNullByte(error, 0);
=======
  alpha = ownItoa(build->lineCounter);
  _strcat(error, build->shellName);
  _strcat(error, ": ");
  _strcat(error, alpha);
  _strcat(error, ": ");
  _strcat(error, build->args[0]);
  _strcat(error, getErrorMessage());
  if (build->args[1])
  {
    if (errno != EBADCD)
      _strcat(error, ": ");
    _strcat(error, build->args[1]);
  }
  _strcat(error, "\n");
  ptr = _strchr(error, '\n');
  len = ptr - error;
  write(STDERR_FILENO, error, len + 1);
  free(alpha);
  insertNullByte(error, 0);
>>>>>>> 1a61726838a9c52f4ebf7918737dcf946822205a
}

/**
 * getErrorMessage - matches errno to corresponding string
 * Return: string of error message
 */
char *getErrorMessage(void)
{
	char *str;

	switch (errno)
	{
		case EBADCD:
			str = ": can't cd to ";
			break;
		case ENOENT:
			str = ": not found";
			break;
		case ENOSTRING:
			str = ": bad variable name";
			break;
		case EILLEGAL:
			str = ": Illegal number";
			break;
		case EWSIZE:
			str = ": invalid number of arguments";
			break;
		case ENOBUILTIN:
			str = ": type help for a list of built-ins";
			break;
		case EACCES:
			str = ": Permission denied";
			break;
		default:
			str = ": no error number assigned";
	}
	return (str);
}
