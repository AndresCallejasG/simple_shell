#include "shellh.h"

/**
* help_exit - prints information about exit built-in
*
*/
void help_exit(void)
{
	_puts("exit: exit [num]\n");
	_puts("\tExit the simple_shell\n\n");
	_puts("\tExit the shell with a status of <num>.\n");
	_puts("\tIf <num> is omitted, the exit status is:\n");
	_puts("\that of the last command executed.\n");
}

/**
* help_env - prints information about env built-in
*
*/
void help_env(void)
{
	_puts("env: env\n");
	_puts("\tPrints the current environment\n\n");
	_puts("\tUsing the external variable **environ.\n");
	_puts("\tprints every environment variable.\n");
}
/**
* help_help - prints information about help built-in
*
*/

void help_help(void)
{
	_puts("help: help [built-in]\n");
	_puts("\tDisplay info related to built-in commands\n\n");
	_puts("\tIf <built-in> is specified, gives detailed help\n");
	_puts("\trelated to an specific command. Otherwise the list\n");
	_puts("\tof help topics is printed\n");
}

/**
* print_help_cmds - prints the help pages availables
*
*/

void print_help_cmds(void)
{
	_puts("These shell commands are defined internally.\n\n");
	_puts("\tType `help' to see this list. Type `help name'\n");
	_puts("\tto find out more about the function `name'.\n\n");
	_puts("\texit [status]\n");
	_puts("\tenv\n");
	_puts("\thelp [built-in]\n");
}
