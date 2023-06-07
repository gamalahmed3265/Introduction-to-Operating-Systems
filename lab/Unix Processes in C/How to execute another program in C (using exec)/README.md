The exec() library functions are a set of functions that allow a process to change its user mode image to a different executable file. The functions take a path to the executable file and a list of arguments as input, and they replace the current process with the new executable file.

The different exec() functions are:

* `execl()`: This function takes a path to the executable file, a list of arguments, and a terminating null pointer as input.
* `execlp()`: This function is similar to `execl()`, but it searches for the executable file in the system path if the path does not contain a leading slash.
* `execle()`: This function is similar to `execl()`, but it also takes an environment variable list as input.
* `execv()`: This function takes a path to the executable file and a list of arguments as input, and it replaces the current process with the new executable file.
* `execvp()`: This function is similar to `execv()`, but it searches for the executable file in the system path if the path does not contain a leading slash.

The exec() library functions are all wrapper functions that call the `execve()` system call. The `execve()` system call replaces the current process with the new executable file, and it copies the arguments and environment variables from the calling process to the new process.

The exec() library functions are a powerful tool that can be used to change the behavior of a process. They can be used to start new programs, to load libraries, and to change the configuration of a process.

Here is an example of how to use the `execlp()` function to start a new program:

```
// This function starts a new program.
void start_program(char *program_name, char *arg1, char *arg2) {
  // Check if the program exists.
  if (access(program_name, F_OK) != 0) {
    // The program does not exist.
    return;
  }

  // Start the program.
  execlp(program_name, program_name, arg1, arg2, NULL);

  // The execlp() function will not return if the program was started successfully.
  // If the program was not started successfully, an error will be printed to the console.
}
```

This function takes the name of the program to start, and two arguments as input. The function checks if the program exists, and if it does, it starts the program. The function will not return if the program was started successfully. If the program was not started successfully, an error will be printed to the console.