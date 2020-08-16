[![Bash Shell](https://imgur.com/gallery/mM2cYtX)](https://github.com/ellerbrock/open-source-badges/)
[![GitHub contributors](https://github.com/ctj01/simple_shell/graphs/contributors)

<img src="https://imgur.com/VChdlIb"
     alt="shell_holberton_cali"
     style="float: left; margin-right: 10px;">

# Simple shell
In this project we'll create a simple UNIX command interpreter in C programming language.

## Table of Contents
* [Introduction](#Introduction)
  * What is Shell
  * What is it for
* [Project Information](#Project-Information)
    * General requirements
    * Allowed functions
* [Documentation](#Documentation)
    * Download
    * Compilation
    * Testing
    * Files
    * Show flowchart
* [Extra Information](#Extra-Information)
    * Resources
* [Authors](#Authors)
  
  ---
  
  
## Introduction
  
### What is Shell 
A **shell** is a command-line interpreter, it is the computer program that provides a user interface to access the services of the operating system. Depending on the type of interface they use, shells can be of various types, in this case, a shell program of the type **`sh`** ([Bourne Shell](https://en.wikipedia.org/wiki/Bourne_shell)) will be developed. Users typically interact with a shell using a [terminal emulator](https://en.wikipedia.org/wiki/Terminal_emulator) that is used for entering data into and displaying or printing data from, a computer or a computing system.

### What is it for
This consists of interpreting orders. It incorporates features such as process control, input/output redirection, law listing and reading, protection, communications, and a command language for writing batch programs or scripts. All Unix-type systems have at least one interpreter compatible with the Bourne shell. The Bourne shell program is found within the Unix file hierarchy at **`/bin/sh`**.



## Project Information

### General requirements
 * Allowed editors: vi, vim, emacs
 * All your files will be compiled on `Ubuntu 14.04 LTS`
 * Your C programs and functions will be compiled with `gcc 4.8.4` using the flags `-Wall` `-Werror` `-Wextra` and `-pedantic`
 * Your code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl
 * No more than 5 functions per file
 * All your header files should be include guarded
 * This shell should not have any memory leaks
 * Unless specified otherwise, your program must have the exact same output as `sh` (`/bin/sh`) as well as the exact same error output.

### Allowed functions
* `access` (man 2 access)
* `chdir` (man 2 chdir)
* `close` (man 2 close)
* `closedir` (man 3 closedir)
* `execve` (man 2 execve)
* `exit` (man 3 exit)
* `_exit` (man 2 _exit)
* `fflush` (man 3 fflush)
* `fork` (man 2 fork)
* `free` (man 3 free)
* `getcwd` (man 3 getcwd)
* `getline` (man 3 getline)
* `isatty` (man 3 isatty)
* `kill` (man 2 kill)
* `malloc` (man 3 malloc)
* `open` (man 2 open)
* `opendir` (man 3 opendir)
* `perror`(man 3 perror)
* `read` (man 2 read)
* `readdir` (man 3 readdir)
* `signal` (man 2 signal)
* `stat` (__ xstat) (man 2 stat)
* `lstat` (__ lxstat) (man 2 lstat)
* `fstat` (__ fxstat) (man 2 fstat)
* `strtok` (man 3 strtok)
* `wait` (man 2 wait)
* `waitpid` (man 2 waitpid)
* `wait3` (man 2 wait3)
* `wait4` (man 2 wait4)
* `write` (man 2 write)

## Documentation

### Download
You can clone this repository this way:
`git clone https://github.com/ctj01/simple_shell.git`

### Compilation
Your shell will be compiled this way:

`gcc -Wall -Werror -Wextra -pedantic *.c -o hsh`

### Testing

Your shell should work like this in interactive mode:

```
$ ./hsh
($) /bin/ls
hsh main.c shell.c
($)
($) exit
$
```


Also in non-interactive mode:

```
$ echo "/bin/ls" | ./hsh
hsh main.c shell.c test_ls_2
$
$ cat test_ls_2
/bin/ls
/bin/ls
$
$ cat test_ls_2 | ./hsh
hsh main.c shell.c test_ls_2
hsh main.c shell.c test_ls_2
$
```

### Invocation

Usage: **RTFM** 
RTFM is started with the standard input connected to the terminal. To start, compile all .c located in this repository by using this command: 
```
gcc -Wall -Werror -Wextra -pedantic *.c -o RTFM
./RTFM
```

**RTFM** is allowed to be invoked interactively and non-interactively. If **RTFM** is invoked with standard input not connected to a terminal, it reads and executes received commands in order.

Example:
```
$ echo "echo 'holberton'" | ./RTFM
'holberton'
$
```

When **RTFM** is invoked with standard input connected to a terminal (determined by isatty(3), the interactive mode is opened. **RTFM** Will be using the following prompt `RTFM'-' `.

Example:
```
$./RTFM
RTFM'-'
```

If a command line argument is invoked, **RTFM** will take that first argument as a file from which to read commands.

Example:
```
$ cat text
echo 'holberton'
$ ./RTFM text
'holberton'
$
```

### Environment

Upon invocation, **RTFM** receives and copies the environment of the parent process in which it was executed. This environment is an array of *name-value* strings describing variables in the format *NAME=VALUE*. A few key environmental variables are:

#### HOME
The home directory of the current user and the default directory argument for the **cd** builtin command.

```
$ echo "echo $HOME" | ./RTFM
/home/vagrant
```

#### PWD
The current working directory as set by the **cd** command.

```
$ echo "echo $PWD" | ./RTFM
/home/vagrant/holberton/simple_shell
```

#### OLDPWD
The previous working directory as set by the **cd** command.

```
$ echo "echo $OLDPWD" | ./RTFM
/home/vagrant/holberton/bog-062019-test_suite
```

#### PATH
A colon-separated list of directories in which the shell looks for commands. A null directory name in the path (represented by any of two adjacent colons, an initial colon, or a trailing colon) indicates the current directory.

```
$ echo "echo $PATH" | ./RTFM
/home/vagrant/.cargo/bin:/home/vagrant/.local/bin:/home/vagrant/.rbenv/plugins/ruby-build/bin:/home/vagrant/.rbenv/shims:/home/vagrant/.rbenv/bin:/home/vagrant/.nvm/versions/node/v10.15.3/bin:/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin:/home/vagrant/.cargo/bin:/home/vagrant/workflow:/home/vagrant/.local/bin
```

### Command Execution

After receiving a command, **RTFM** tokenizes it into words using `" "` as a delimiter. The first word is considered the command and all remaining words are considered arguments to that command. **RTFM** then proceeds with the following actions:
1. If the first character of the command is neither a slash (`\`) nor dot (`.`), the shell searches for it in the list of shell builtins. If there exists a builtin by that name, the builtin is invoked.
2. If the first character of the command is none of a slash (`\`), dot (`.`), nor builtin, **RTFM** searches each element of the **PATH** environmental variable for a directory containing an executable file by that name.
3. If the first character of the command is a slash (`\`) or dot (`.`) or either of the above searches was successful, the shell executes the named program with any remaining given arguments in a separate execution environment.

### Exit Status 

**RTFM** returns the exit status of the last command executed, with zero indicating success and non-zero indicating failure.
If a command is not found, the return status is 127; if a command is found but is not executable, the return status is 126.
All builtins return zero on success and one or two on incorrect usage (indicated by a corresponding error message).

### Signals

While running in interactive mode, **RTFM** ignores the keyboard input ctrl+c. Alternatively, an input of End-Of-File ctrl+d will exit the program.

User hits ctrl+d in the foutrh command.
```
$ ./RTFM
RTFM'-' ^C
RTFM'-' ^C
RTFM'-' ^C
RTFM'-'
```

### Variable Replacement

**RTFM** interprets the `$` character for variable replacement.

#### $ENV_VARIABLE
`ENV_VARIABLE` is substituted with its value.

Example:
```
$ echo "echo $PWD" | ./RTFM
/home/vagrant/holberton/simple_shell
```

#### $?
`?` is substitued with the return value of the last program executed.

Example:
```
$ echo "echo $?" | ./RTFM
0
```

#### $$
The second `$` is substitued with the current process ID.

Example:
```
$ echo "echo $$" | ./RTFM
3855
```

### Comments

**RTFM** ignores all words and characters preceeded by a `#` character on a line.

Example:
```
$ echo "echo 'holberton' #this will be ignored!" | ./RTFM
'holberton'
```

### Operators

**RTFM** specially interprets the following operator characters:

#### ; - Command separator
Commands separated by a `;` are executed sequentially.

Example:
```
$ echo "echo 'hello' ; echo 'world'" | ./RTFM
'hello'
'world'
```

#### && - AND logical operator
`command1 && command2`: `command2` is executed if, and only if, `command1` returns an exit status of zero.

Example:
```
$ echo "error! && echo 'holberton'" | ./RTFM
./shellby: 1: error!: not found
$ echo "echo 'my name is' && echo 'holberton'" | ./RTFM
'my name is'
'holberton'
```

#### || - OR logical operator
`command1 || command2`: `command2` is executed if, and only if, `command1` returns a non-zero exit status.

Example:
```
$ echo "error! || echo 'wait for it'" | ./RTFM
./RTFM: 1: error!: not found
'wait for it'
```

The operators `&&` and `||` have equal precedence, followed by `;`.

### Builtin Commands

#### cd
  * Usage: `cd [DIRECTORY]`
  * Changes the current directory of the process to `DIRECTORY`.
  * If no argument is given, the command is interpreted as `cd $HOME`.
  * If the argument `-` is given, the command is interpreted as `cd $OLDPWD` and the pathname of the new working directory is printed to standad output.
  * If the argument, `--` is given, the command is interpreted as `cd $OLDPWD` but the pathname of the new working directory is not printed.
  * The environment variables `PWD` and `OLDPWD` are updated after a change of directory.

Example:
```
$ ./RTFM
RTFM'-' pwd
/home/vagrant/holberton/simple_shell
$ cd ../
RTFM'-' pwd
/home/vagrant/holberton
RTFM'-' cd -
RTFM'-' pwd
/home/vagrant/holberton/simple_shell
```

#### exit
  * Usage: `exit [STATUS]`
  * Exits the shell.
  * The `STATUS` argument is the integer used to exit the shell.
  * If no argument is given, the command is interpreted as `exit 0`.

Example:
```
$ ./RTFM
$ exit
```

#### env
  * Usage: `env`
  * Prints the current environment.

Example:
```
$ ./RTFM
$ env
NVM_DIR=/home/vagrant/.nvm
...
```

#### setenv
  * Usage: `setenv [VARIABLE] [VALUE]`
  * Initializes a new environment variable, or modifies an existing one.
  * Upon failure, prints a message to `stderr`.

Example:
```
$ ./RTFM
$ setenv NAME Holberton
$ echo $NAME
Holberton
```

#### unsetenv
  * Usage: `unsetenv [VARIABLE]`
  * Removes an environmental variable.
  * Upon failure, prints a message to `stderr`.

Example:
```
$ ./RTFM
$ setenv NAME Holberton
$ unsetenv NAME
$ echo $NAME

$
```


## Authors

* [Cristian Mendoza](https://github.com/ctj01)
