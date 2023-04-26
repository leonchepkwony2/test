#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <dirent.h>
#include <signal.h>

#define MAX_INPUT 1024 // Maximum input size

void display_prompt();
int _putchar(char c);
char* _fgets(char* str, int num, FILE* stream);
int _strcmp(const char* str1, const char* str2);
size_t _strlen(const char* str);
int _getchar(void);
char* _strchr(const char* str, int c);



#endif
