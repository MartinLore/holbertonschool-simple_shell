<h1 align="center" style="color:#FFFFFF"> C - Simple Shell<h1>

<br>

<p align="center">
  <img src="https://blog.holbertonschool.com/wp-content/uploads/2019/04/instagram_feed180.jpg" width="500" />
</p>

<h3 align="right">by Hernán Alegresa and Martin Morales<h3>

# Project Simple Shell 

## Table of contents

- [Description](#description)
- [Learning Objectives](#learning-objectives)
- [Requirements](#requirements)
- [File Structure](#file-structure)
- [Usage](#usage)
- [Example of usage](#Example-of-usage)
- [Man or help](#man-or-help)
- [Authors](#authors)

## Description

A UNIX-Shell is a command-line interpreter or "shell" that provides you a command-line user interface for Unix-like operating systems. The Shell is both an interactive and a scripting language. The first Shell was the "Thompson Shell", written by Ken Thompson at Bell Labs, distributed from 1971 to 1975. Ken Thompson developped his Shell version, associated with Dennis Ritchie, in the B programming language. After creating B, Ritchie and teammates moved to language C.

## Learning Objectives 

What we have learn in this project:
- Who designed and implemented the original Unix operating system
- Who wrote the first version of the UNIX shell
- Who invented the B programming language (the direct predecessor to the C programming language)
- Who is Ken Thompson
- How does a shell work
- What is a pid and a ppid
- How to manipulate the environment of the current process
- What is the difference between a function and a system call
- How to create processes
- What are the three prototypes of main
- How does the shell use the PATH to find the programs
- How to execute another program with the execve system call
- How to suspend the execution of a process until one of its children terminates
- What is EOF / “end-of-file”?

## Requirements

- Allowed editors: vi, vim, emacs
- All your files will be compiled on Ubuntu 20.04 LTS using gcc, using the options -Wall -Werror -Wextra -pedantic -std=gnu89
- All your files should end with a new line
- A README.md file, at the root of the folder of the project is mandatory
- Your code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl
- Your shell should not have any memory leaks
- No more than 5 functions per file
- All your header files should be include guarded
- Use system calls only when you need to (why?)

## File Structure

- Authors - list of contributors to this project
- man_1_simple_shell - manual page for the simple_shell
- main.h - header program file
- Main functions:
  - execute_command.c - execute a command
  - get_location.c - retrieve the location of a command in the system's PATH
  - main.c - main function for the simple shell
- Additional functions:
  - parser.c - parse user input into tokens
  - wordcount.c - count the number of words in a string
  - handle_signal.c - handle signals, e.g., Ctrl+C

## Usage

Clone this repository: <br>
```
git clone git@github.com:HernanAlegresa/holbertonschool-simple_shell.git
```
Switch inside the directory: 
```
cd holbertonschool-simple_shell
```
Compile all the files with the correct flags and the wildcard *.c :
```
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 -o ./hsh
```
You're all good to use the shell either in Interactive mode, to do so enter in your terminal:
```
./hsh
```
Then a prompt will be displayed, and you can enter commands.

The other way is in Non-Interactive mode, for example if you want to list files and directory, command ```ls```, call the shell like so:
```
echo "/bin/ls" | ./hsh
```

## Example of usage
### Interactive mode
```
$ ./hsh
($) /bin/ls
hsh main.c shell.c
($)
($) exit
$
```

### Non-interactive mode
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

## Man or help

ALLOWED FUNCTIONS AND SYSTEM CALLS:

all functions from string.h

access (man 2 access)

chdir (man 2 chdir)

close (man 2 close)

closedir (man 3 closedir)

execve (man 2 execve)

exit (man 3 exit)

_exit (man 2 _exit)

fflush (man 3 fflush)

fork (man 2 fork)

free (man 3 free)

getcwd (man 3 getcwd)

getline (man 3 getline)

getpid (man 2 getpid)

isatty (man 3 isatty)

kill (man 2 kill)

malloc (man 3 malloc)

open (man 2 open)

opendir (man 3 opendir)

perror (man 3 perror)

printf (man 3 printf)

fprintf (man 3 fprintf)

vfprintf (man 3 vfprintf)

sprintf (man 3 sprintf)

putchar (man 3 putchar)

read (man 2 read)

readdir (man 3 readdir)

signal (man 2 signal)

stat (__xstat) (man 2 stat)

lstat (__lxstat) (man 2 lstat)

fstat (__fxstat) (man 2 fstat)

strtok (man 3 strtok)

wait (man 2 wait)

waitpid (man 2 waitpid)

wait3 (man 2 wait3)

wait4 (man 2 wait4)

write (man 2 write)

## Authors

These project creators are the students of Holberton School Uruguay:

***HERNÁN ALEGRESA*** --> https://github.com/HernanAlegresa

***MARTIN MORALES*** --> https://github.com/MartinLore
