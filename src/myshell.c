/* 
Name: Ishrat Allybuxsh
Student Number: 21338756
Module: Operating System -> #ca216/myshell

Acknowledgement of the DCU Academic Integrity Policy:
    I understand that the University regards breaches of academic integrity and plagiarism as grave and serious.
    I have read and understood the DCU Academic Integrity and Plagiarism Policy. I accept the penalties that may be imposed should I engage in practice or practices that breach this policy.
    I have identified and included the source of all facts, ideas, opinions and viewpoints of others in the assignment references. Direct quotations, paraphrasing, discussion of ideas from books, journal articles, internet sources, module text, or any other source whatsoever are acknowledged and the sources cited are identified in the assignment references.
    I declare that this material, which I now submit for assessment, is entirely my own work and has not been taken from the work of others save and to the extent that such work has been cited and acknowledged within the text of my work.
    I have used the DCU library referencing guidelines and/or the appropriate referencing system recommended in the assignment guidelines and/or programme documentation.

*******************************************************************
Original base source code - including my modifications

version: 1.0
date:    December 2003
author:  Ian G Graham
School of Information Technology
Griffith University, Gold Coast
ian.graham@griffith.edu.au
copyright (c) Ian G Graham, 2003. All rights reserved.
This code can be used for teaching purposes, but no warranty,
explicit or implicit, is provided.

******************************************************************
*/

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "myshell.h"

#define MAX_BUFFER 1024      // max line buffer
#define MAX_ARGS 64          // max # args
#define SEPARATORS " \t\n"   // token separators

int main(int argc, char **argv) {
    char buf[MAX_BUFFER];      // line buffer
    char *args[MAX_ARGS];      // pointers to arg strings
    char **arg;                // working pointer thru args
    char *prompt = "==>";      // shell prompt
    pid_t pid;

    /* Batch Mode */
    /* check if batch file is provided in the command line*/
    if (argc > 1) {
        batchmode(argv);
    }

    /* keep reading input until "quit" command or eof of redirected input */
    while (!feof(stdin)) {
        /* get command line from input */
        fputs(prompt, stdout); // write prompt

        if (fgets(buf, MAX_BUFFER, stdin)) { // read a line
            /* tokenize the input into args array */
            arg = args;
            *arg++ = strtok(buf, SEPARATORS);   // tokenize input

            while ((*arg++ = strtok(NULL, SEPARATORS)));

            // last entry will be NULL
            if (args[0]) {                     // if there's anything there
                /* check for internal/external command */

                  /* Executes quit command to exit the shell */
                if (!strcmp(args[0], "quit")) {  // "quit" command
                    quit();
                }

                /* Executes clr or clear command to clear the screen */
                if (!strcmp(args[0], "clr") || !strcmp(args[0], "clear")) { // "clr" or "clear" command
                    clr();
                    continue;
                }

                /* Executes cd command to change directory */
                else if (!strcmp(args[0], "cd")) { // "cd" command
                    cd(args[1]);
                    continue;
                }

                /* Executes dir command to list the current directory contents */
                else if (!strcmp(args[0], "dir")) { // 'ls -al' command
                    dir(args[1]);
                    continue;
                }

                /* Executes environ command to list all the environment strings */
                else if (!strcmp(args[0], "environ")) { // 'environ' command
                    env();
                    continue;
                }

                /* Executes echo command which echo on the display followed by a new line */
                else if (!strcmp(args[0], "echo")) { // 'echo' command
                    echo(args);
                    continue;
                }

                /* Executes help command to open the readme.md file in the manual folder */
                else if (!strcmp(args[0], "help")) { // "help" command
                    help();
                    continue;
                }

                /* Executes pause command to pause operation on the shell until 'Enter' is pressed */
                else if (!strcmp(args[0], "pause")) { // "pause" command
                    pause_command();
                    continue;
                }

                /* shell forking and executing */
                else {
                    pid = fork();
                    // checking for any error while forking
                    if (pid < 0) {
                        printf("Error: Failed Forking");
                        break;
                    } else if (pid == 0) {    // Child process
                        io_redirection(args);
                    } else {  // Parent process
                        /* Background execution */
                        /* Check if last argument is & */
                        int i;
                        for (i = 0; args[i] != NULL; i++);
                        if (strcmp(args[i - 1], "&") != 0) {
                            /* Wait till child process finish */
                            waitpid(pid, NULL, 0);
                        }
                    }
                }
            }
        }
    }
    return 0;
}
