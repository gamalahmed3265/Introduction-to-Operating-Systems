`wait()` and `waitpid()` are system calls that are used to wait for a child process to finish.

`wait()` waits for any child process to finish.

`waitpid()` waits for a specific child process to finish.

Both `wait()` and `waitpid()` return the process ID of the child process that finished.

`wait()` and `waitpid()` can also be used to get information about the child process that finished, such as the exit status and the signal that caused the child process to terminate.

The following table shows the differences between `wait()` and `waitpid()`:

| Feature | wait() | waitpid() |
|---|---|---|
| Returns | Process ID of any child process that finished | Process ID of specific child process |
| Can get information about | Exit status and signal that caused the child process to terminate | Exit status and signal that caused the child process to terminate, as well as the process group ID of the child process |
| Can be used to wait for | Any child process | Specific child process |

Here is an example of how to use `wait()`:

```c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
  int pid = fork();
  if (pid == 0) {
    // Child process
    execlp("ls", "ls", NULL);
  } else {
    // Parent process
    int status;
    wait(&status);
    printf("Child process exited with status %d\n", WEXITSTATUS(status));
  }

  return 0;
}
```

This code will fork a child process and then call `wait()` to wait for the child process to finish. When the child process finishes, the `wait()` call will return the process ID of the child process and the exit status of the child process. The exit status is a number that indicates how the child process terminated. For example, a value of 0 indicates that the child process terminated normally, and a value of 127 indicates that the child process terminated due to a segmentation fault.

Here is an example of how to use `waitpid()`:

```c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
  int pid = fork();
  if (pid == 0) {
    // Child process
    execlp("ls", "ls", NULL);
  } else {
    // Parent process
    int status;
    waitpid(pid, &status, 0);
    printf("Child process exited with status %d\n", WEXITSTATUS(status));
  }

  return 0;
}
```

This code is similar to the previous code, but it uses `waitpid()` instead of `wait()`. The `waitpid()` call takes three arguments: the process ID of the child process to wait for, a pointer to a variable that will store the exit status of the child process, and a set of flags. The flags can be used to control how `waitpid()` behaves. For example, the `WNOHANG` flag can be used to make `waitpid()` return immediately if the child process has not yet finished.

I hope this helps! Let me know if you have any other questions.