#ifndef SHELL_H
#define SHELL_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#define MAX_COMMAND_LENGTH 100
ssize_t getline(char **lineptr, size_t *n, FILE *stream);
void prompt(int argc, char **argv, char **env); 
int stat(const char *pathname, struct stat *statbuf);
int execve(const char *pathname, char *const argv[], char *const envp[]);
