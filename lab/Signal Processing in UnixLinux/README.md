The sigaction structure is defined as
```
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