![buidtshell](https://i.imgur.com/w7IoZUd.jpg)


#### **Medellín,  April 16th 2020. / Versión 1.0**

# Building SHELL

The Shell is an sh-compatible command language interpreter that executes commands from the stand input or from a file.



### Synopsis:

All files in this repository are designed to be compiled with the GNU Compiler Collection v. "gcc 4.8.4" in the linux environment of "Ubuntu 14.04.5 LTS". When compiled, the executable file replicates a shell, which is a user interface used to access the services. This shell has a set of customizable built-in commands and also integrates with other commands located in the system's PATH. The output and functionality is designed to replicate the output of the "sh" shell and some commands.

### Description:

The shell is a program that reads line by line from a file or from the terminal, then interprets it and executes it if the line is a valid command. Otherwise, it returns an error message corresponding to the requested action.

### Usage:

All the files are to be compiled on an Ubuntu <style="color:blue">14.04</style> LTS machine with __"gcc -Wall -Werror -Wextra -pedantic *.c -o hsh"__

**Example:**
$ gcc -Wall -Werror -Wextra -pedantic **.c -o hsh*

Once compiled, to start the program, run: **./hsh**

**Example:**
$ ./hsh*

To exit the program, run: **exit [status]**

**Example:**
$ exit 44

### Simple Commands:
If a simple command has been recognized, the shell performs the following actions.  You can enter a command in any of the ways:

__*command [arguments] or path/command [arguments].*__

**Example:**
*$ls -la*
*total 96*
*drwxrwxr-x 3 vagrant vagrant 4096 Apr 16 20:43 .*
*drwxr-xr-x 12 vagrant vagrant 4096 Apr 16 19:41 ..*
*-rw-rw-r-- 1 vagrant vagrant 172 Apr 16 02:43 AUTHORS*
*-rw-rw-r-- 1 vagrant vagrant 1083 Apr 16 19:46 built-in.c*
*-rw-rw-r-- 1 vagrant vagrant 1666 Apr 16 19:46 exec.c*
*drwxrwxr-x 8 vagrant vagrant 4096 Apr 16 20:54 .git*
*-rwxrwxr-x 1 vagrant vagrant 29219 Apr 16 20:43 hsh*
*-rw-rw-r-- 1 vagrant vagrant 1623 Apr 16 19:46 llist_tools.c*
*-rw-rw-r-- 1 vagrant vagrant 2048 Apr 16 19:46 main.c*
*-rw-rw-r-- 1 vagrant vagrant 1268 Apr 16 19:46 main_tools.c*
*-rw-rw-r-- 1 vagrant vagrant 3248 Apr 16 20:50 man_1_simple_shell*
*-rw-rw-r-- 1 vagrant vagrant 1303 Apr 16 19:46 own_help.c*
*-rw-rw-r-- 1 vagrant vagrant 1388 Apr 16 19:46 print_tools.c*
*-rw-rw-r-- 1 vagrant vagrant 3400 Apr 16 20:54 README.md*
*-rw-rw-r-- 1 vagrant vagrant 1901 Apr 16 19:46 shellh.h*
*-rw-rw-r-- 1 vagrant vagrant 1589 Apr 16 19:46 str_tools.c*
*-rw-rw-r-- 1 vagrant vagrant 581 Apr 16 19:46 tools.c*

The shell will go looking for it. If it gets it, it will execute the corresponding action, otherwise it will return an error indicating that it is not a valid command.

### Built-ins:

This section lists the built-in commands that need to perform some operation that cannot be done by a separate process.

-  **exit:** terminate the shell process. If exitstatus is given it is used as the exit status of the shell; otherwise the exit status of the preceding command is used. To use it you must write: exit

-  **env:** prints out the current environment. To use it you must write: env

-  **help:** show the shell's help options. To use it you must write: help exit, help env or help help.

### Functions created:

The following functions were created to replace the functions of the standard libraries:

-  **srtlen:** determine length of a string.

-  **srtcmp:** compare two strings. If the result is 0, there is a match between the strings.

-  **strdup:** duplicates a string, placing it in a new memory position with the same size and elements of the original.

-  **strconcat:** concatenate two strings.

-  **atoi:** converts a string into an integer.

### Functions within the files:
| File | Description
| ------------- |:-------------|
| **shell.h** | Header file that contains all the functions and standard C library header file |
| **main.c** | Contains: int main(void) |
| **built-in.c** | Contains the functions: _print_env, own_exit and own_help |
| **exec.c.c** | Contains the functions: execve, _check_path, _find_path and _full_path |
| **llist_tools.c** |  Contains the functions: add_node_end, _linkPATH and free_list |
| **main_tools.c** | Contains the functions: _split and _processing |
| **own_help.c** | Contains the functions: help_exit, help_exit, help_help and print_help_cmds |
| **print_tools.c** | Contains the functions: _putchar, _puts, _print_number_err, _puts_err and _putchar_err |
| **str_tools.c** | Contains the functions: _strdup, _strcmp, _str_concat and _strlen |
| **tools.c** | Contains the functions: free_grid and _atoi  |
| **man_1_simple_shell** | man shell|

### See also:

List of allowed functions and system calls: `access`, `chdir`, `close`, `closedir`, `execve`, `exit`, `fork`, `free`, `fstat`, `getcwd`, `getline`, `kill`, `lstat`, `malloc`, `open`, `opendir`, `perror`, `read`, `readdir`, `signal`, `stat`, `strtok`, `wait`, `waitpid`, `wait3`, `wait4`, `write`, `_exit`.

### Return value:

The shell will exit with status 0 unless status is specified.

### Bugs:

No known bugs.

### Authors:

[Andrés, Callejas González](https://github.com/AndresCallejasG)

[Marlon Aurelio, García Morales](https://github.com/clasesucatmarlon)