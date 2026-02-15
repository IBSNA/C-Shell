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
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include "myshell.h"

/* Declare environ */
extern char **environ;

/* clear the screen */
void clr() {
    system("clear");
}

/* change the current directory */
void cd(char *dir) {
    char directory[100];
    getcwd(directory, sizeof(directory));

    if (dir == NULL) {
        printf("%s\n", directory);
    } else {
        if (chdir(dir) != 0) {
            perror("cd");
        } else {
            getcwd(directory, sizeof(directory));
            setenv("PWD", directory, 1);
        }
    }
}

/* list the contents of directory */
void dir(char *dir) {
    char directory[256];

    getcwd(directory, sizeof(directory));
    system("ls -al $directory");
}

/* list all the environment strings */
void env() {
    for (int i = 0; environ[i] != NULL; i++) {
        printf("%s\n", environ[i]);
    }
}

/* echo on the display followed by a new line */
void echo(char *argv[]) {
    for (int i = 1; argv[i]; i++) {
        printf("%s\n", argv[i]);
    }
}

/* display the user manual using the more filter */
void help() {
    char help[1024] = "more ./manual/readme.md";
    system(help);
}

/* pause operation of the shell until 'Enter' is pressed */
void pause_command() {
    printf("Press Enter to Continue....\n");
    while (getchar() != '\n');
}

/* quit the shell */
void quit() {
    exit(0);
}

/* I/O Redirection */
void IORedirection(char **args) {
    for (int i = 1; args[i - 1] != NULL; i++) {
        /* check for '<' redirection character */
        if (strcmp(args[i - 1], "<") == 0) {
            if (access(args[i - 1], F_OK) != 0) {
                perror("Error: File Not Found.");
            } else {
                /* Read mode */
                freopen(args[i], "r", stdin);
                args[i - 1] = NULL;
                i++;
            }
        }

        /* check for '>' redirection character */
        if (strcmp(args[i - 1], ">") == 0) {
            /* write mode */
            freopen(args[i], "w", stdout);
            args[i - 1] = NULL;
            i++;
        }

        /* check for '>>' redirection character */
        if (strcmp(args[i - 1], ">>") == 0) {
            /* Append mode */
            freopen(args[i], "a", stdout);
            args[i - 1] = NULL;
            i++;
        }
    }
}

/* BATCHMODE AND IO REDIRECTION */
/* BATCHMODE FUNCTION */
void batchmode(char *args[]) {
    if (args[1]) {
        const char* batchfile = args[1];
        if (access(batchfile, F_OK) == 0) {
            freopen(batchfile, "r", stdin);
        } else {
            printf("File %s does not exist.\n", batchfile);
            exit(0);
        }
    }
}
/* IO REDIRECTION FUNCTION (echo, environ, dir, help, other)*/
void io_redirection(char *args[]) {
    char* input = NULL;
    char* output = NULL;
    char* output_addedto = NULL;
    
    int arg_count = 0;
    while (args[arg_count]) {
        arg_count++;
    }
    int shift = 0;
    for (int i = 0; i < arg_count; i++) {
        if (!strcmp(args[i], "<")) {
            input = args[i + 1];
            i = i + 1;
        } else if (!strcmp(args[i], ">")) {
            output = args[i + 1];
            i = i + 1;
        } else if (!strcmp(args[i], ">>")) {
            output_addedto = args[i + 1];
            i = i + 1;
        } else {
            /* Check for the "quit" command */
            if (!strcmp(args[i], "quit")) {
                quit();  // Exit immediately if "quit" command is encountered
            } else {
                args[shift] = args[i];
                shift = shift + 1;
            }
        }
    }
    
    args[shift] = NULL;
    if (input != NULL) {
        if (access(input, F_OK) == 0) {
            freopen(input, "r", stdin);
        } else {
            printf("IO Redirection Error: Input file.");
        }
    }
    if (output != NULL) {
        if (freopen(output, "w", stdout) == NULL) {
            printf("IO Redirection Error: Output file.");
        }
    }
    if (output_addedto != NULL) {
        if (freopen(output_addedto, "a", stdout) == NULL) {
            printf("IO Redirection Error: Output Added file.");
        }
    }
}
