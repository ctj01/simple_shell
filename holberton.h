#ifndef _HOLBERTON_
#define _HOLBERTON_
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <limits.h>
#define _BUFSIZE 128
#define _DELIMITERS " \t\r\n\a"
#if !(defined _POSIX_C_SOURCE)
typedef long int ssize_t;
#endif
#if !(defined _POSIX_C_SOURCE) || _POSIX_C_SOURCE < 200809L
#if !(defined SSIZE_MAX)
#define SSIZE_MAX (SIZE_MAX >> 1)
#endif
#endif
extern char **environ;


/**
 * struct Arguments - struct that contains all relevant Arguments on runtime
 * @av: argument vector
 * @input: command line written by the user
 * @args: tokens of the command line
 * @status: last status of the shell
 * @counter: lines counter
 * @_environ: environment variable
 * @pid: process ID of the shell
 */
typedef struct Arguments
{
	char **av;
	char *input;
	char **args;
	int status;
	int counter;
	char **_environ;
	char *pid;
} _unix;

/**
 * struct sep_list_s - single linked list
 * @separator: ; | &
 * @next: next node
 * Description: single linked list to store separators
 */
typedef struct sep_list_s
{
	char separator;
	struct sep_list_s *next;
} sep_list;

/**
 * struct _listnode - single linked list
 * @line: command line
 * @next: next node
 * Description: single linked list to store command lines
 */
typedef struct _listnode
{
	char *line;
	struct _listnode *next;
} nodelist_;

/**
 * struct variable_list - single linked list
 * @len_var: length of the variable
 * @val: value of the variable
 * @_val: length of the value
 * @next: next node
 * Description: single linked list to store variables
 */
typedef struct variable_list
{
	int len_var;
	char *val;
	int _val;
	struct variable_list *next;
} _var;

/**
 * struct build_ - Build struct for command args.
 * @name: The name of the command builtin i.e cd, exit, env
 * @f: Arguments type pointer function.
 */
typedef struct build_
{
	char *name;
	int (*f)(_unix *cmd);
} _build_;

ssize_t aux_getline(char **lineptr, size_t *n, FILE *stream);
sep_list *add_sep_node_end(sep_list **head, char sep);
void free_sep_list(sep_list **head);
nodelist_ *add_line_node_end(nodelist_ **head, char *line);
void free_nodelist_(nodelist_ **head);
_var *add_rvar_node(_var **head, int lvar, char *var, int lval);
void free_rvar_list(_var **head);
char *_strcat(char *dest, const char *src);
char *_strcpy(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *_strchr(char *s, char c);
int _strspn(char *s, char *accept);
void _memcpy(void *newptr, const void *ptr, unsigned int size);
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
char **_reallocdp(char **ptr, unsigned int old_size, unsigned int new_size);
char *_strdup(const char *s);
int _strlen(const char *s);
int cmp_chars(char str[], const char *delim);
char *_strtok(char str[], const char *delim);
int _isdigit(const char *s);
void rev_string(char *s);
int repeated_char(char *input, int i);
int error_sep_op(char *input, int i, char last);
int first_char(char *input, int *i);
void print_syntax_error(_unix *cmd, char *input, int i, int bool);
int check_syntax_error(_unix *cmd, char *input);
char *without_comment(char *in);
void shell_(_unix *cmd);
char *read_line(int *_EOF);
char *swap_char(char *input, int bool);
void add_nodes(sep_list **head_s, nodelist_ **head_l, char *input);
void go_next(sep_list **list_s, nodelist_ **list_l, _unix *cmd);
int split_commands(_unix *cmd, char *input);
char **split_line(char *input);
void check_env(_var **h, char *in, _unix *Arguments);
int check_vars(_var **h, char *in, char *st, _unix *Arguments);
char *replaced_input(_var **head, char *input, char *new_input, int nlen);
char *rep_var(char *input, _unix *cmd);
ssize_t _getline(char **lineptr, size_t *n, FILE *stream);
int exec_line(_unix *cmd);
int is_cdir(char *path, int *i);
char *_which(char *cmd, char **_environ);
int is_executable(_unix *cmd);
int check_error_cmd(char *dir, _unix *cmd);
int cmd_exec(_unix *cmd);
char *_getenv(const char *name, char **_environ);
int _env(_unix *cmd);
char *copy_info(char *name, char *value);
void set_env(char *name, char *value, _unix *cmd);
void free_(_unix *cmd);
int _setenv(_unix *cmd);
int _unsetenv(_unix *cmd);
void cd_dot(_unix *cmd);
void cd_to(_unix *cmd);
void cd_previous(_unix *cmd);
void cd_to_home(_unix *cmd);
int cd_shell(_unix *cmd);
void set_(_unix *cmd, char **av);
int (*_build_command(char *cmd))(_unix *command);
int exit_shell(_unix *cmd);
int _len(int n);
char *_atoiAux(int n);
int _atoi(char *string);
char *strcat_cd(_unix *, char *, char *, char *);
char *error_get_cd(_unix *cmd);
char *error_not_found(_unix *cmd);
char *error_exit_shell(_unix *cmd);
char *error_get_alias(char **args);
char *error_env(_unix *cmd);
char *error_syntax(char **args);
char *error_permission(char **args);
char *error_path_126(_unix *cmd);
int get_error(_unix *cmd, int eval);
void get_sigint(int sig);
void aux_help_env(void);
void aux_help_setenv(void);
void aux_help_unsetenv(void);
void aux_help_general(void);
void aux_help_exit(void);
void aux_help(void);
void aux_help_alias(void);
void aux_help_cd(void);
int get_help(_unix *cmd);

#endif
