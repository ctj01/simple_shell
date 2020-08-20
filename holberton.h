#ifndef _HOLBERTON_H_
#define _HOLBERTON_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <signal.h>
#include <limits.h>

/* ERRORS */
#define BUFSIZE 256
#define ENO 1106
#define RALLOC 227
#define ESIZE 410
#define EBUILT 415
#define HCD 726

extern char **environ;

/**
 * struct list - linked list data structure
 * @string: environ variable path name
 * @next: pointer to next node
 */
typedef struct list
{
	char *string;
	struct list *next;
} node_l;

/**
 * struct xsh - configuration of ssh settings
 * @env: linked list of local env variables
 * @envList: array of env variables to put into execve
 * @args: array of argument strings
 * @buffer: string buffer of user input
 * @path: array of $PATH locations
 * @fullPath: string of path with correct prepended $PATH
 * @shellName: name of shell (argv[0])
 * @lineCounter: counter of lines users have entered
 * @errorStatus: error status of last child process
 */
typedef struct xsh
{
	node_l *env;
	char **envList;
	char **args;
	char *buffer;
	char *path;
	char *fullPath;
	char *shellName;
	unsigned int lineCounter;
	int errorStatus;
} _unix;

/**
 * struct Commands - commands and functions associated with it
 * @command: input command
 * @func: output function
 */
typedef struct Commands
{
	char *command;
	int (*func)(_unix *ssh);
} cmd;

/* main */
_unix *configInit(_unix *ssh);

/* built_ins */
_Bool _builtins(_unix *ssh);
int _exitsv(_unix *ssh);
int _hFunc(_unix *ssh);
int _alias(_unix *ssh);

/* cd */
int _cd(_unix *);
_Bool _cdDirectory(_unix *ssh);
_Bool _cdBefore(_unix *ssh);
_Bool _cdUser(_unix *ssh);
_Bool Uenviron(_unix *ssh);

/* cd2 */
int uDirectory(_unix *ssh);
_Bool current(_unix *ssh, int index);

/* env */
int _enviroment(_unix *ssh);
int setenvFunc(_unix *ssh);
int unsetenvFunc(_unix *ssh);
int _isalpha(int c);

/* help */
int helpFunc(_unix *ssh);
int displayHelpMenu(void);
int hExit(_unix *ssh);
int hEnv(_unix *ssh);
int hHistory(_unix *ssh);

/* _help*/
int _Halias(_unix *ssh);
int hCd(_unix *biuld);
int hSetenv(_unix *ssh);
int hUnsetenv(_unix *ssh);
int _Help(_unix *ssh);

/* _built_ins*/
int Arguments(char **args);
int _atoi(char *string);

/* shell */
void shell(_unix *ssh);
void _getline(_unix *ssh);
void forkAndExecute(_unix *ssh);
void stripComments(char *str);
void convertLLtoArr(_unix *ssh);

/* _getenv */
char *_getenv(char *input, char **environ);

/* get_Error */
void _getError(_unix *ssh);
unsigned int countDigits(int num);
char *itoa(unsigned int num);
char *OutError();

/* shell_*/
void insertNullByte(char *str, unsigned int index);
void displayPrompt(void);
void displayNewLine(void);
void sigintHandler(int sigint);

/* path_checker */
_Bool pathChecker(_unix *);
_Bool _eCases(_unix *ssh);

/* split_string */
_Bool splitString(_unix *ssh);
unsigned int countWords(char *s);
_Bool isSpace(char c);

/* string_*/
int _strlen(char *s);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *_strdup(char *str);
char *_strcpy(char *dest, char *src);

/* string_ */
char *_strtok(char *str, char *delim);
int _strcspn(char *string, char *chars);
char *_strchr(char *s, char c);

/* node_list */
node_l *addNode(node_l **head, char *str);
node_l *addNodeEnd(node_l **head, char *str);
size_t printList(const node_l *h);
int searchNode(node_l *head, char *str);
size_t list_len(node_l *h);

/* node_func */
int deleteNodeAtIndex(node_l **head, unsigned int index);
node_l *generateLinkedList(char **array);
node_l *addNodeAtIndex(node_l **head, int index, char *str);
char *getNodeAtIndex(node_l *head, unsigned int index);

/* _realloc */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char *_memcpy(char *dest, char *src, unsigned int n);

/* free */
void freeData(_unix *ssh);
void freeBuffer(_unix *ssh);
void freeArgs(char **args);
void freeList(node_l *head);

#endif
