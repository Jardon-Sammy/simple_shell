#ifndef _MAIN_H_
#define _MAIN_H_

#define MAX_ARGS 10

char *read_input_line();
void parse_input(char *line, char *args[]);
void execute_command(char *args[]);
char* _strtok(char* str, char* del);

#endif
