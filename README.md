# MiniShell
Minishell is a school 42 team project to create a basic shell program in C.
It mimics the behavior of a Unix-based shell by interpreting and executing user commands. 
The purpose of this project is to gain hands-on experience with system programming concepts, 
such as process management, file handling, and command execution.

## Installation
1. Clone the repository to your local machine:
   ```bash
   git clone https://github.com/n1cxyz/minishell.git
   ```
2. Navigate to the project directory:
   ```Makefile
   cd minishell
   ```
3. Build the project using `make`:
   ```
   make
   ```
   This will generate the executable `minishell`.

## Features
- Execution of common shell commands
- Handling of environment variables
- Support for built-in commands like `cd`, `echo`, `exit`, etc.
- Input/output redirection (`>`, `>>`, `<`, `<<`)
- Piping (`|`)
- Signal handling (`Ctrl+C`, `Ctrl+D`, `Ctrl+\`)
- Command chaining with `&&` and `||`
- Handling of wildcards
- Error handling with informative messages


## Usage
Once compiled, you can start the MiniShell by running the following command:
```
./minishell
```
The shell will prompt for user input. You can enter any supported command, 
and the shell will execute it accordingly. To exit the shell, use the `exit` command or press `Ctrl+D`.

Example commands:
```bash
$ ls -l
$ cd /path/to/directory
$ echo "Hello, world!"
$ cat file.txt | grep "search term"
```

## Contributors
- [dasal](https://github.com/n1cxyz)
- [wlucke](https://github.com/Welf42)
