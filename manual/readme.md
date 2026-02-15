# ------User Help Manual------
Welcome to the User Manual. Below you will find information regarding the commands and features of myshell.

Press ENTER or D to continue.
To exit the User Help Manual, enter Q.

# Description
MyShell supports various internal commands, has batch mode execution, I/O redirection, and background execution.

# Synopsis
./bin/myshell

# Internal Commands
Internal commands are commands that are hardwired into the shell code. 
The ones available in this shell are listed below:

- `cd <directory>`: Changes the current default directory. If a directory is not supplied, `cd` reports the current directory.
- `clr` or `clear`: Clears the screen.
- `dir <directory>`: Lists the contents of the specified directory. If none is supplied, `dir` will list the contents of the current directory.
- `environ`: Lists all the environment strings.
- `echo <input>`: Prints out the given input message into the terminal followed by a new line.
- `help`: Prints out the User Manual.
- `pause`: Pauses operation of the shell until 'Enter' is pressed.
- `quit`: Quits out of the shell.

# External Commands
This shell also supports the use of external commands. External commands are commands that are not hardwired into the shell. 
An example would be the `cat` command or the `ls` command - Both of these commands are not explicitly written into the coding of this shell, but will work regardless. This is done through forking and executing these commands.

# Batch Mode
This shell also supports the running of batch files. Batch files are files that contain codes to be executed in the shell. The way to run batch
files is by mentioning the batch file name beside the shell name through the initial command line before entering the shell.
Eg: `./myshell <batchfile_name.sh>`. 
The shell then starts up and executes every command in the batch file and exits the shell.

# I/O Redirection
IO Redirection refers to the way a program can change where the input / output of a program or command is printed. Normally, when a command is executed the result is printed out as standard output to the screen in the terminal. With I/O Redirection, this output can be changed to print elsewhere.
This is run by typing: programname arg1 arg2 < inputfile > outputfile

- `<`: The less than symbol represents input. If the user lists a file after this symbol, input for the program will be read from the file specified.
- `>`: The greater than symbol represents output. If the user lists a file after this symbol, the output of that command will be printed into the specified file.
- `>>`: This symbol is the same as the above output symbol except it has the added functionality that any output printed will not replace the output currently in the file specified.

# Program Environment
- **Environment Variables**: Variables defining settings/values that are used by the shell. They are key-value pairs where the key represents the variable and the value represents the data.
- **User-Defined Variables**: Variables defined by the user.
- **Functions**: User defined blocks of code that do a particular function. Functions need to be called in order to be activated.

# Process Concept
My shell contains two processes -> the Parent process (default) and a child process. The child process is used for the execution of the external commands and some of the internal commands.

# Background and Foreground Execution
- **Background Execution**: This means that the program is running in the background of the current process and does not occupy the terminal.
- **Foreground Execution**: This means that the program is occupying the terminal and is running in the current process.

In this shell background and foreground execution are facilitated. The default execution is foreground execution. When the user enters an ampersand ("&") character after their command - background execution is executed.

# References:
1. Graham, I.G. and Stallings, W. (no date) Lab04/05: Building a Shell, Dublin City University Loop. Edited by G. Healy. Available at: https://loop.dcu.ie/mod/book/view.php?id=2054177 
2. Parker, S. (2014) Unix & Linux Shell scripting tutorial. United States: CreateSpace Independent Publishing Platform. 
3. Blum, Richard, and Christine Bresnahan. "Linux Command Line and Shell Scripting Bible." John Wiley & Sons, 2020.
4. Sobell, Mark G. "A Practical Guide to Linux Commands, Editors, and Shell Programming." Pearson Education, 2017.


# DECLARATION
Name: Ishrat Allybuxsh
Student Number: 21338756
Module: Operating System -> myshell project 1
Acknowledgement of the DCU Academic Integrity Policy:
    I understand that the University regards breaches of academic integrity and plagiarism as grave and serious.
    I have read and understood the DCU Academic Integrity and Plagiarism Policy. I accept the penalties that may be imposed should I engage in practice or practices that breach this policy.
    I have identified and included the source of all facts, ideas, opinions and viewpoints of others in the assignment references. Direct quotations, paraphrasing, discussion of ideas from books, journal articles, internet sources, module text, or any other source whatsoever are acknowledged and the sources cited are identified in the assignment references.
    I declare that this material, which I now submit for assessment, is entirely my own work and has not been taken from the work of others save and to the extent that such work has been cited and acknowledged within the text of my work.
    I have used the DCU library referencing guidelines and/or the appropriate referencing system recommended in the assignment guidelines and/or programme documentation.
