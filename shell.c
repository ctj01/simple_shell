#include "holberton.h"

/**
 * shell - simple shell
 * @cmd: input cmd
 */
void shell(_unix *cmd)
{
	while (true)
	{
		_getline(cmd);
		if (splitString(cmd) == false)
			continue;
		if (_builtins(cmd) == true)
			continue;
		pathChecker(cmd);
		forkAndExecute(cmd);
	}
}

/**
 * _getline - check stdin and retrieves next line; handles
 * prompt display
 * @cmd: input cmd
 */
void _getline(_unix *cmd)
{
	register int len;
	size_t bufferSize = 0;
	char *ptr, *ptr2;

	cmd->args = NULL;
	cmd->envList = NULL;
	cmd->lineCounter++;
	if (isatty(STDIN_FILENO))
		displayPrompt();
	len = getline(&cmd->buffer, &bufferSize, stdin);
	if (len == EOF)
	{
		freeData(cmd);
		if (isatty(STDIN_FILENO))
			displayNewLine();
		if (cmd->errorStatus)
			exit(cmd->errorStatus);
		exit(EXIT_SUCCESS);

	}
	ptr = _strchr(cmd->buffer, '\n');
	ptr2 = _strchr(cmd->buffer, '\t');
	if (ptr || ptr2)
		insertNullByte(cmd->buffer, len - 1);
	stripComments(cmd->buffer);
}

/**
 * stripComments - remove comments from input string
 * @str: input string
 * Return: length of remaining string
 */
void stripComments(char *str)
{
	register int i = 0;
	_Bool notFirst = false;

	while (str[i])
	{
		if (i == 0 && str[i] == '#')
		{
			insertNullByte(str, i);
			return;
		}
		if (notFirst)
		{
			if (str[i] == '#' && str[i - 1] == ' ')
			{
				insertNullByte(str, i);
				return;
			}
		}
		i++;
		notFirst = true;
	}
}

/**
 * forkAndExecute - fork current cmd and execute processes
 * @cmd: input cmd
 */
void forkAndExecute(_unix *cmd)
{
	int status;
	pid_t f1 = fork();

	convertLLtoArr(cmd);
	if (f1 == -1)
	{
		perror("error\n");
		freeData(cmd);
		freeArgs(cmd->envList);
		exit(1);
	}
	if (f1 == 0)
	{
		if (execve(cmd->fullPath, cmd->args, cmd->envList) == -1)
		{
			_getError(cmd);
			freeData(cmd);
			freeArgs(cmd->envList);
			if (errno == ENOENT)
				exit(127);
			if (errno == EACCES)
				exit(126);
		}
	} else
	{
		wait(&status);
		if (WIFEXITED(status))
			cmd->errorStatus = WEXITSTATUS(status);
		freeBuffer(cmd);
		freeArgs(cmd->envList);
	}
}

/**
 * convertLLtoArr - convert linked list to array
 * @cmd: input cmd
 */
void convertLLtoArr(_unix *cmd)
{
	register int i = 0;
	size_t count = 0;
	char **envList = NULL;
	node_l *tmp = cmd->env;

	count = list_len(cmd->env);
	envList = malloc(sizeof(char *) * (count + 1));
	if (!envList)
	{
		perror("Malloc failed\n");
		exit(1);
	}
	while (tmp)
	{
		envList[i] = _strdup(tmp->string);
		tmp = tmp->next;
		i++;
	}
	envList[i] = NULL;
	cmd->envList = envList;
}
