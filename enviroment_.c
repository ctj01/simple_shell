#include "holberton.h"

/**
 * copy_info - copies info to create
 * a new env or alias
 * @name: name (env or alias)
 * @value: value (env or alias)
 *
 * Return: new env or alias.
 */
char *copy_info(char *name, char *value)
{
	char *new;
	int len_name, len_value, len;

	len_name = _strlen(name);
	len_value = _strlen(value);
	len = len_name + len_value + 2;
	new = malloc(sizeof(char) * (len));
	_strcpy(new, name);
	_strcat(new, "=");
	_strcat(new, value);
	_strcat(new, "\0");

	return (new);
}

/**
 * set_env - sets an environment variable
 *
 * @name: name of the environment variable
 * @value: value of the environment variable
 * @cmd: data structure (environ)
 * Return: no return
 */
void set_env(char *name, char *value, _unix *cmd)
{
	int i;
	char *var_env, *name_env;

	for (i = 0; cmd->_environ[i]; i++)
	{
		var_env = _strdup(cmd->_environ[i]);
		name_env = _strtok(var_env, "=");
		if (_strcmp(name_env, name) == 0)
		{
			free(cmd->_environ[i]);
			cmd->_environ[i] = copy_info(name_env, value);
			free(var_env);
			return;
		}
		free(var_env);
	}

	cmd->_environ = _reallocdp(cmd->_environ, i, sizeof(char *) * (i + 2));
	cmd->_environ[i] = copy_info(name, value);
	cmd->_environ[i + 1] = NULL;
}

/**
 * _setenv - compares env variables names
 * with the name passed.
 * @cmd: data relevant (env name and env value)
 *
 * Return: 1 on success.
 */
int _setenv(_unix *cmd)
{

	if (cmd->args[1] == NULL || cmd->args[2] == NULL)
	{
		get_error(cmd, -1);
		return (-1);
	}

	set_env(cmd->args[1], cmd->args[2], cmd);

	return (0);
}

/**
 * _unsetenv - deletes a environment variable
 *
 * @cmd: data relevant (env name)
 *
 * Return: 1 on success.
 */
int _unsetenv(_unix *cmd)
{
	char **realloc_environ;
	char *var_env, *name_env;
	int i, j, k;

	if (cmd->args[1] == NULL)
	{
		get_error(cmd, -1);
		return (-1);
	}
	k = -1;
	for (i = 0; cmd->_environ[i]; i++)
	{
		var_env = _strdup(cmd->_environ[i]);
		name_env = _strtok(var_env, "=");
		if (_strcmp(name_env, cmd->args[1]) == 0)
		{
			k = i;
		}
		free(var_env);
	}
	if (k == -1)
	{
		get_error(cmd, -1);
		return (-1);
	}
	realloc_environ = malloc(sizeof(char *) * (i));
	for (i = j = 0; cmd->_environ[i]; i++)
	{
		if (i != k)
		{
			realloc_environ[j] = cmd->_environ[i];
			j++;
		}
	}
	realloc_environ[j] = NULL;
	free(cmd->_environ[k]);
	free(cmd->_environ);
	cmd->_environ = realloc_environ;
	return (0);
}
