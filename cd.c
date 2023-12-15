#include "main.h"
/**
 * cmd_if - Changes the current directory and updates 
 * @argv: Array of arguments, where args[1] represents the directory path
 * Return: Void
 */
void cmd_if(char **argv)
{
	if (chdir(argv[1]) == -1)
		perror("cd");
	else
	{
		char cwd[PATH_MAX];

		if (getcwd(cwd, sizeof(cwd)) != NULL)
		{
			if (setenv("PWD", cwd, 1) == -1)
				perror("setenv");
			if (setenv("OLDPWD", argv[1], 1) == -1)
				perror("setenv");
		}
		else
		{
			perror("getcwd");
		}
	}
}

/**
 * cmd_cd - changes the current directory of the process
 * @args: Array of arguments
 * Return: Void
 */
void cmd_cd(char **args)
{
	char *path;

	if (args[1] == NULL || (_strcmp(args[1], "~") == 0))
	{
		path = _getenv("HOME");
		if (path == NULL)
		{
			perror("cd");
			return;
		}
	}
	else if (_strcmp(args[1], "-") == 0)
	{
		path = _getenv("OLDPWD");
		if (path == NULL)
		{
			perror("cd");
			return;
		}
		printf("%s\n", path);
	}
	else
	{
		path = args[1];
	}

	 cmd_if(args);

}
