# Pipex

![Pipex](https://img.shields.io/badge/Pipex-C%20Project-blue)

Description from assignment:

Pipex is a project designed to help you explore a core UNIX mechanism—pipelines. This program emulates the pipeline behavior of the shell by handling pipes between commands, processing input from files, and redirecting output to other files. By completing this project, you’ll deepen your understanding of process communication and I/O redirection.

## Table of Contents
- [Project Overview](#project-overview)
- [Usage](#usage)
- [Examples](#examples)
- [Mandatory Requirements](#mandatory-requirements)
- [Bonus Features](#bonus-features)
- [Compiling and Testing](#compiling-and-testing)
- [Submission and Evaluation](#submission-and-evaluation)

## Project-Overview

- **Program Name**: `pipex`
- **Language**: C
- **Compilation**: Uses a Makefile
- **External Functions Allowed**:
  - `open`, `close`, `read`, `write`, `malloc`, `free`, `perror`, `strerror`, `access`, `dup`, `dup2`, `execve`, `exit`, `fork`, `pipe`, `unlink`, `wait`, `waitpid`, and custom `ft_printf` functions.
- **Libft**: Authorized

The project is intended to take a closer look on Linux pipe mechanism by implementing my own pipe program using functions above ^^^.

This project simulates the following shell command:

```bash
< file1 cmd1 | cmd2 > file2
```
  
## Usage

To use the project simply follow this steps.

```bash
https://github.com/cvrs3d/42prague-core-pipex.git
```

```bash
cd <cloned repo name>
```

```bash
make
```

```bash
./pipex inputfile cmd1 cmd2 outputfile
```

