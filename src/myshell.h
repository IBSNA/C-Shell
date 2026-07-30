/* 
Module: Operating System -> #ca216/myshell

Acknowledgement of the DCU Academic Integrity Policy:
    I understand that the University regards breaches of academic integrity and plagiarism as grave and serious.
    I have read and understood the DCU Academic Integrity and Plagiarism Policy. I accept the penalties that may be imposed should I engage in practice or practices that breach this policy.
    I have identified and included the source of all facts, ideas, opinions and viewpoints of others in the assignment references. Direct quotations, paraphrasing, discussion of ideas from books, journal articles, internet sources, module text, or any other source whatsoever are acknowledged and the sources cited are identified in the assignment references.
    I declare that this material, which I now submit for assessment, is entirely my own work and has not been taken from the work of others save and to the extent that such work has been cited and acknowledged within the text of my work.
    I have used the DCU library referencing guidelines and/or the appropriate referencing system recommended in the assignment guidelines and/or programme documentation.
*/
#ifndef MYSHELL_H
#define MYSHELL_H

#define MAX_BUFFER 1024    // max line buffer
#define MAX_ARGS 64        // max # args
#define SEPARATORS " \t\n" // token separators

/* Functions in utility.c */
void clr();
void cd(char *dir);
void dir(char *dir);
void env(); 
void echo(char *words[]);
void help();
void pause_command();
void quit();
void IORedirection(char **args);

/* New functions */
void batchmode(char *args[]);
void io_redirection(char *args[]);

#endif /* MYSHELL_H */
