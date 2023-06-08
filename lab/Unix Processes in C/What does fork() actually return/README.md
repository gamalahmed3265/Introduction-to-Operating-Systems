The code you provided will create a new process, called the child process, which runs concurrently with the process that makes the fork() call (parent process). The child process will then sleep for 1 second, while the parent process will continue executing. After the child process wakes up, it will print the following message:

```
Returing by fork=> 0, Current id=> 27, parent id=> 1
```

The first number in the message is the process ID of the child process. The second number is the process ID of the parent process. The third number is the process ID of the grandparent process.

Here is an explanation of what happens in each line of code:

```c
int pid=fork();
```

The fork() function creates a new process and returns the process ID of the child process to the parent process. If the fork() function fails, it returns -1.

```c
if (pid==0){// child p wait
```

This if statement checks if the current process is the child process. If it is, the code inside the if statement will be executed.

```c
sleep(1);
```

The sleep() function pauses the execution of the current process for the specified number of seconds. In this case, the sleep() function will pause the execution of the child process for 1 second.

```c
}
```

This closing curly brace marks the end of the if statement.

```c
printf("Returing by fork=> %d, Current id=> %d , parent id=> %d\n",pid,getpid(),getppid());
```

The printf() function prints the specified message to the standard output. The message includes the process ID of the child process, the process ID of the current process, and the process ID of the parent process.
