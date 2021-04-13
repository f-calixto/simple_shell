#include "holberton.h"

/**
* free_grid - Entry point
* @grid: matrix
*
* Description: Free a matrix
* Return: Nothing
*/
void free_grid(char **grid)
{
	int i = 0, size = 0;

	for (size = 0 ; grid[size] != '\0' ; size++)
	{
	}
	for (i = 0 ; i < size ; i++)
		free(grid[i]);
	free(grid);
}


/**
 * _which - entry point
 * @cmd: command to find full path
 * @env: enviroment array
 * Return: full path on success
 *
 */

char *_which(char *cmd, char **env)
{
	int i = 0, size = 0;
	struct stat st;
	char *buff;
	char **path = NULL;

	path = findpath(env);
	for (i = 1; path[i]; i++)
	{
		if (cmd[0] == '.')
		{
			buff = malloc(sizeof(*cmd));
			if (!buff)
			{
				free(path);
				return NULL;
			}
			_strcpy(buff, cmd);
		}
		else
		{
			size = (_strlen(path[i]) + 2 + _strlen(cmd));
			buff = malloc(sizeof(char) * size);
			if (!buff)
			{
				free(path);
				return NULL;
			}
			_strcpy(buff, path[i]);
			_strcat(buff, "/");
			_strcat(buff, cmd);
		}
		if (stat(buff, &st) == 0)
		{
			free(path);
			return (buff);
		}
	}
	free(path);
	return (cmd);
}

/**
 * special_char_finder - entry point
 * @str: string to search special character
 * @ch: char to search for (its a string)
 * Return: changed string (or not)
 */
char *special_char_finder(char *str, char *ch)
{
	char *res = NULL;

	if (str[0] == '#')
		return ("");
	res = strtok(str, ch);
	if (res)
		return (res);
	else
		return (str);
}


/**
* array_copy - Entry point
* @arr: Array of chars* to copy
* @extra: count of extra spaces
*
* Description: Copp an array of char*
* Return: The copy of arr
*/
char **array_copy(char **arr, int extra)
{
	int i = 0, len = 0;
	char **new_arr;

	for (i = 0 ; arr[i] != '\0' ; i++)
	{
	}
	new_arr = malloc(sizeof(char *) * (i + extra + 1));
	for (i = 0 ; arr[i] != '\0' ; i++)
	{
		len = _strlen(arr[i]);
		new_arr[i] = malloc(sizeof(char) * (len + 1));
		_strcpy(new_arr[i], arr[i]);
		new_arr[i][len] = '\0';
	}
	new_arr[i] = NULL;
	return (new_arr);
}
/**
* _setenv - Entry point
* @name: name for variable
* @value: value for variable
* @overwrite: is ow or not
* @env: enviroment array
* @envi: pointer to enviromnet array
*
* Description: Add or replace a enviroment variable
* Return: 0 Success
*/
int _setenv(char *name, char *value, int overwrite, char **env, char ***envi)
{
	int i = 0, j = 0;
	char *word;

	for (i = 0; env[i] != '\0'; i++)
	{
		word = env[i];
		for (j = 0; name[j] != '\0'; j++)
		{
			if (name[j] != word[j])
				break;
		}
		if ((name[j] == '\0') && (word[j] == '='))
		{
			if (overwrite != 0)
			{
				return (replace_env_val(name, value, i, env));
			}
			else
				return (0);
		}
	}
	if (env[i] == '\0')
	{
		add_env_val(name, value, i, env, envi);
	}
	return (0);
}
