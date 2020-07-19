# linux-basic-course

This is a set of tasks and code to solve for better understanding of OS working.



### 0 (bash)

- Check if file exists in directory with project

- Print numbers between [1, 100]

- Create folder with name N. In this folder Create file with name N and text N for N in [1,5]

  

### 1 (C basics)

Practice:

Create program that realize stack data structure (base on array). Working with stack must be implemented with `push`, `pop`, `peak` operations.

Definitions of keep in `stack.h` file. All logic in `stack.c` file.



### 2 (File operations)

Theory:

- File descriptor

- Standard input/output streams
- Redirection of input/output streams in terminal, transporters
- Functions: `open`, `close`, `read`, `write`, `lseek`

Practice (C):
Create a program which takes two arguments (in command).

Takes text from first file, set all text to lower register and save text to second file. 
(Fist file - path specified in first argument, Second file - path specified in second argument)

### 3 (Files and directories)

- `chdir`
- `mkdir`
- `unlink`
- `rmdir`
- `rename`
- `stat`
- `strace` and `gdb` debugger

Practice:

Create a program that opens file specified in argument and writes size of program in bytes (KiB, MiB, GiB, TiB)

### 4 (Processes)

Theory:

- `getpid`
- `fork`
- `wait` 
- `exec`
- `exit`
- UNIX processes signals

Practice:

Create program that writes sum of elements from random array. Calculating of sum split in few parts and each parts calculate in separate process.



### 5 (Unnamed channels)

Theory:

Read about unnamed channel and process interaction. `pipe`



Practice:

Create program where parent and child processes send number to each other and increase it by 1. Stop working when number 

will rich some value (maybe passed in argument).



### 6 (Signals)

Theory:

Read about signals in UNIX.

[https://ru.wikipedia.org/wiki/%D0%A1%D0%B8%D0%B3%D0%BD%D0%B0%D0%BB_(Unix)](https://ru.wikipedia.org/wiki/Сигнал_(Unix))

https://www.ibm.com/developerworks/ru/library/l-signals_1/



Practice:

I would add it in future. Maybe :)





