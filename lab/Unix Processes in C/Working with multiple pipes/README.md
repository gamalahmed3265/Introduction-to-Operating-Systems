Working with multiple pipes can be a bit tricky, but it's not too difficult once you understand the basics.

A pipe is a unidirectional communication channel that can be used to connect two processes. A process can write data to a pipe, and another process can read data from the same pipe.

To create a pipe, you can use the `pipe()` system call. This function returns two file descriptors, one for reading from the pipe and one for writing to the pipe.

Once you have created a pipe, you can use the `fork()` system call to create a child process. The child process can then use the `dup2()` system call to redirect its standard output to the write end of the pipe. The parent process can then use the `read()` system call to read data from the read end of the pipe.

Here is an example of how to use multiple pipes:

```
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
  int fd[2];
  int fd2[2];

  if (pipe(fd) == -1) {
    perror("pipe");
    exit(1);
  }

  if (pipe(fd2) == -1) {
    perror("pipe");
    exit(1);
  }

  int pid = fork();
  if (pid == 0) {
    // Child process
    dup2(fd[1], STDOUT_FILENO);
    close(fd[0]);
    close(fd[1]);
    execlp("ls", "ls", NULL);
  } else {
    // Parent process
    dup2(fd2[0], STDIN_FILENO);
    close(fd2[0]);
    close(fd2[1]);
    char buf[1024];
    int n;
    while ((n = read(STDIN_FILENO, buf, sizeof(buf))) > 0) {
      printf("%s", buf);
    }
    wait(NULL);
  }

  return 0;
}
```

This code creates two pipes. The first pipe is used to communicate between the parent process and the child process. The second pipe is used to communicate between the child process and the `ls` command.

The parent process forks a child process. The child process then uses the `dup2()` system call to redirect its standard output to the write end of the first pipe. The parent process then uses the `dup2()` system call to redirect its standard input to the read end of the second pipe.

The `ls` command then reads data from the read end of the second pipe and prints it to standard output. The parent process then reads data from the write end of the first pipe and prints it to standard output.

This code will list the contents of the current directory.