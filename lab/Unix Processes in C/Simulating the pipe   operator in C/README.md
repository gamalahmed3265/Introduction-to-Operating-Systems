## Simulating the pipe "|" operator in C


The code you provided creates two child processes, one to run the `ping` command and the other to run the `grep` command. The `ping` command sends five pings to the Google domain and the `grep` command searches the output of the `ping` command for the string `rtt`. The `waitpid` functions wait for the child processes to finish before returning.

Here is a breakdown of what each line of code does:

```c
int fd[2];
// fd[0] - read
// fd[1] - write
```

This line creates a pipe with two file descriptors, `fd[0]` and `fd[1]`. The `fd[0]` file descriptor can be used to read data from the pipe, and the `fd[1]` file descriptor can be used to write data to the pipe.

```c
if (pipe(fd) == -1)
{
    printf("An error ocurred with opening the pip\n");
    return 1;
}
```

This line opens the pipe. If an error occurs, the program prints an error message and returns 1.

```c
int pid = fork();
if (pid == -1)
{
    return 1;
}
```

This line creates a child process. If an error occurs, the program returns 1.

```c
if (pid == 0)
{
    dup2(fd[1], STDOUT_FILENO);
    close(f[0]);
    close(f[1]);
    execlp(
        "ping",
        "ping",
        "-c",
        "5",
        "google.com",
        NULL);
}
```

This code runs the `ping` command in the child process. The `dup2` function redirects the output of the `ping` command to the `fd[1]` file descriptor. The `close` functions close the `fd[0]` and `fd[1]` file descriptors. The `execlp` function runs the `ping` command.

```c
int pi2 = fork();
if (pid2 == -1)
{
    return 2;
}
```

This line creates a second child process. If an error occurs, the program returns 2.

```c
if (pid2 == 0)
{
    dup2(fd[1], STDOUT_FILENO);
    close(f[0]);
    close(f[1]);
    execlp(
        "grep",
        "grep",
        "rtt",
        NULL);
}
```

This code runs the `grep` command in the second child process. The `dup2` function redirects the output of the `grep` command to the `fd[1]` file descriptor. The `close` functions close the `fd[0]` and `fd[1]` file descriptors. The `execlp` function runs the `grep` command.

```c
waitpid(pid, NULL, 0);
waitpid(pid2, NULL, 0);
```

This code waits for the child processes to finish before returning.

```c
return 0;
```

This line returns 0.
