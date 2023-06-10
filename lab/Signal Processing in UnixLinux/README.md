# signal
The `signal()` function in C is used to set the action taken by a process on receipt of a specific signal. The signal can be any valid signal except SIGKILL and SIGSTOP.

The `signal()` function takes two arguments:

`sig`: The signal to be handled.
`handler`: A pointer to the function that will be called when the signal is received.
The `sig` argument specifies the signal that is to be handled. The handler argument specifies the function that will be called when the signal is received. The `handler` function can be any function that takes one argument, which is the signal number.

The following code shows how to use the signal() function to set a signal handler for the SIGINT signal:

```c
#include <signal.h>

void sigint_handler(int signo) {
  // Do something when SIGINT is received.
}

int main() {
  // Set the signal handler for SIGINT.
  signal(SIGINT, sigint_handler);

  // Do some work.

  // Wait for a signal to be received.
  pause();

  return 0;
}
```


In this example, the sigint_handler() function is called when SIGINT is received. The `signal()` function returns the previous action for the signal.

The `signal()` function can also be used to get the current action for a signal. To do this, pass a NULL pointer for the handler argument. The sig argument specifies the signal that is to be handled.

The following code shows how to use the `signal()` function to get the current action for the SIGINT signal:

```c
#include <signal.h>

int main() {
  // Get the current action for SIGINT.
  void (*old_handler)(int) = signal(SIGINT, NULL);

  // Do some work.

  // Restore the old action for SIGINT.
  signal(SIGINT, old_handler);

  return 0;
}

```

In this example, the `old_handler` variable is assigned the previous action for the SIGINT signal. The `signal()` function returns the previous action for the signal.

The `signal()` function is a powerful tool that can be used to control the behavior of signals. It can be used to set signal handlers, block signals, and get the current action for a signal.

# Sigaction


The sigaction structure is defined as
```c
struct sigaction{
    void (*sa_handler)(int);
    void (*sa_sigaction)(int, siginfo_t *, void *);
    sigset_t sa_mask;
    int sa_flags;
    void (*sa_restorer)(void);
};
```
The most important fields are:
1. sa_handler: This is the pointer to a handler function that has the same prototype as a handler for
signal().
2. sa_sigaction: This is an alternative way to run the signal handler. It has two additional arguments
beside the signal number where the siginfo_t * provides more information about the received signal.
3. sa_mask: allows to set signals to be blocked during execution of the handler.
4. sa_flags: allows to modify the behavior of the signal handling process. To use the sa_sigaction
    handler, sa_flags must be set to SA_SIGINFO.
    For a detailed description of the sigaction structure fields, see the sigaction manual page. The following
    shows a simple example of using the sigaction() system call.
    
    
The code you provided is a C program that uses the `sigaction()` function to set a signal handler for the SIGTERM signal. The signal handler prints the signal number, the PID of the process that sent the signal, and the UID of the process that sent the signal.

The `sigaction()` function takes three arguments:

1. `sig`: The signal to be handled.
2. `act`: A pointer to a `struct sigaction` structure that specifies the new action to be taken.
3. `oact`: A pointer to a `struct sigaction` structure that will be filled in with the old action.
The `struct sigaction` structure has the following members:

1..  `sa_handler`: A pointer to the signal handler function.
2. `sa_mask`: A set of signals that will be blocked while the signal handler is running.
3. `sa_flags`: A set of flags that control the behavior of the signal handler.
The `sa_handler` member is a pointer to the function that will be called when the signal is received. The `sa_mask` member is a set of signals that will be blocked while the signal handler is running. This means that other signals will not be able to interrupt the signal handler. The `sa_flags` member is a set of flags that control the behavior of the signal handler.

In the code you provided, the `sa_handler` member is set to the address of the `handler()` function. The `handler() `function prints the signal number, the PID of the process that sent the signal, and the UID of the process that sent the signal. The `sa_mask` member is set to the empty set. This means that no signals will be blocked while the `handler()` function is running. The sa_flags member is set to the `SA_SIGINFO` flag. This flag tells the `sigaction()` function to pass a `siginfo_t` structure to the signal handler.

`The siginfo_t` structure is a structure that contains information about the signal that was received. The siginfo_t structure has the following members:

1. `si_signo`: The signal number.
2. `si_errno`: The error number, if any.
3. `si_code`: The signal code.
4.`si_pid`: The PID of the process that sent the signal.
5.`si_uid`: The UID of the process that sent the signal.
6.`si_status`: The exit status of the process, if any.
7.`si_utime`: The user time consumed by the signal handler.
8.`si_stime`: The system time consumed by the signal handler.
9.`The siginfo_t` structure is passed to the signal handler as an argument. The signal handler can use the siginfo_t structure to get information about the signal that was received.

In the `handler()` function, the `si_pid` member of the `siginfo_t` structure is used to get the PID of the process that sent the signal. The `si_uid `member of the `siginfo_t` structure is used to get the UID of the process that sent the signal.

The `sigaction()` function is a powerful tool that can be used to control the behavior of signals. It can be used to set signal handlers, block signals, and get the current action for a signal.

# memset
`memset` is a standard library function in C and C++ programming languages. It is used to set the specified number of bytes of an array to a particular value. The syntax of the memset function is as follows:
```c
void *memset(void *s, int c, size_t n);

```

hhe first argument, s, is a pointer to the array that is to be filled. The second argument, c, is the value that the array is to be filled with. The third argument, n, is the number of bytes to be filled.

The memset function returns a pointer to the array that was filled.

The following code shows how to use the memset function to fill an array with zeros:
```c
#include <stdio.h>

int main() {
  int array[10];

  // Fill the array with zeros.
  memset(array, 0, sizeof(array));

  // Print the array.
  for (int i = 0; i < 10; i++) {
    printf("%d ", array[i]);
  }

  printf("\n");

  return 0;
}
```
# output
```
0 0 0 0 0 0 0 0 0 0

```

# pipes and named pipes
Both unnamed pipes and named pipes can be used for related or unrelated processes. However, there are some differences in how they are used.

* **Unnamed pipes** are created by the `pipe()` system call. They are a form of **inter-process communication (IPC)** that allows two processes to communicate with each other directly. Unnamed pipes are **temporary** and only exist as long as the processes that created them are still running.
* **Named pipes** are created by the `mkfifo()` system call. They are also a form of IPC, but they are **persistent** and can be used by any process that has access to them. Named pipes are often used to create **daemons**, which are processes that run in the background and provide services to other processes.

In general, unnamed pipes are a good choice for communication between **related processes**, such as the parent and child processes of a fork(). Named pipes are a good choice for communication between **unrelated processes**, such as a web server and a database server.

Here is a table that summarizes the differences between unnamed pipes and named pipes:

| Feature | Unnamed Pipes | Named Pipes |
|---|---|---|
| Creation | `pipe()` system call | `mkfifo()` system call |
| Lifetime | Temporary, only exists as long as the processes that created it are still running | Persistent, can be used by any process that has access to it |
| Use | Communication between related processes | Communication between unrelated processes |
| Example | Parent and child processes of a fork() | Web server and database server |

I hope this helps! Let me know if you have any other questions.
