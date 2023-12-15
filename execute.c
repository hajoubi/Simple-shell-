#include "main.h"

/**
 * _fork - Function to create a child process 
 * @av: Array of arguments
 * @argv: Array of arguments associated with the command
 * @envp: Array of environment variables
 * @full_path: Full path of the command
 * Return: Integer
 */
int _fork(char **av, char **argv, char **envp, char *full_path)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == -1)
	{
		perror(av[0]);
		free(full_path);
		return (-1);
	}
	else if (pid == 0)
	{
		if (execve(full_path, argv, envp) == -1)
		{
			perror(av[0]);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		if (waitpid(pid, &status, 0) == -1)
		{
			perror(av[0]);
			free(full_path);
			return (-1);
		}
	}

	if (full_path != NULL)
		free(full_path);
	return (0);
}

/**
 * _else - Function to handle non-builtin cmd
 * @cmd: The command to be executed
 * @full_path: Full path of the command
 * Return: Integer
 */
int _else(char *cmd, char **full_path)
{
	if (!path(cmd, full_path))
	{
		char error_message[100];

		_snprintf(error_message, sizeof(error_message),
			"%s: command not found\n", cmd);
		write(STDERR_FILENO, error_message, strlen(error_message));
		return (COMMAND_NOT_FOUND);
	}
	return (0);
}

/**
 * builts - Executes built-in commands
 * @cmd: The command to be executed
 * @argv: Array of arguments associated with the command
 * Return: 1 if the command is a built-in command, 0 otherwise
 */
int builts(char *cmd, char **argv)
{
	if (_strcmp(cmd, "setenv") == 0)
	{
		cmd_setenv(argv);
		return (1);
	}
	else if (_strcmp(cmd, "unsetenv") == 0)
	{
		cmd_unsetenv(argv);
		return (1);
	}
	else if (_strcmp(cmd, "cd") == 0)
	{
		cmd_cd(argv);
		return (1);
	}
	return (0);
}

/**
 * execute - Function that executes the cmd
 * @cmd: Pointer to the cmd
 * @argv: Pointer to command's arguments
 * @av: Pointer to arguments
 * @envp: Pointer to environment variables
 * Return: Integer
 */
int execute(char *cmd, char **argv, char **av, char **envp)
{
	char *full_path = NULL;

	if (builts(cmd, argv))
		return (0);

	if (cmd[0] == '/')
	{
		if (access(cmd, X_OK) == 0)
		{
			full_path = malloc((strlen(cmd) + 1) * sizeof(char));
			if (full_path == NULL)
			{
				perror("Failed to allocate memory");
				return (-1);
			}
			_strcpy(full_path, cmd);
		}
		else
		{
			char error_message[100];

			_snprintf(error_message, sizeof(error_message),
				"%s: command not found\n", cmd);
			write(STDERR_FILENO, error_message, _strlen(error_message));
			return (COMMAND_NOT_FOUND);
		}
	}
	else
		_else(cmd, &full_path);

	_fork(av, argv, envp, full_path);
	return (0);
}

