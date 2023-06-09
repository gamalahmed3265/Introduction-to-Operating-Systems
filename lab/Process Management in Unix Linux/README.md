Running the MT Multitasking System: Under Linux, enter
                                      `gcc –m32 t.c s.s`
                                      
 ### Sample Outputs of the MT Multitasking System
![Screenshot 2023-06-09 063821_edited](https://github.com/gamalahmed3265/Operating-Systems/assets/75225936/a9abfeb5-aa9c-42d9-9933-0791a8c3b6bd)



![pipe](https://github.com/gamalahmed3265/Operating-Systems/assets/75225936/16fdee62-b67c-4afa-b7fe-d4cddfc6a880)
![sim](https://github.com/gamalahmed3265/Operating-Systems/assets/75225936/7a3b76d9-5637-4db1-a77b-ef9dae75f55c)










Process management is the set of activities that an operating system performs to create, start, stop, and manage processes. In Unix and Linux, process management is handled by the kernel. The kernel is the core of the operating system, and it is responsible for managing all of the resources on the system, including processes.

The kernel uses a number of tools to manage processes. These tools include:

* **fork():** This system call creates a new process that is a copy of the calling process.
* **exec():** This system call replaces the current process with a new process.
* **wait():** This system call waits for a child process to finish.
* **kill():** This system call sends a signal to a process, which can cause the process to terminate.

Processes can be classified into two types: foreground processes and background processes. Foreground processes are processes that are interactive with the user. Background processes are processes that run in the background and do not require user interaction.

Foreground processes are started by the user at the command line. They are displayed in the foreground of the terminal window. The user can interact with foreground processes by typing commands at the prompt.

Background processes are started by the user with the & character. They are displayed in the background of the terminal window. The user cannot interact with background processes by typing commands at the prompt.

The kernel uses a number of mechanisms to manage the execution of processes. These mechanisms include:

* **Scheduling:** The kernel schedules processes to run on the CPU. The kernel uses a variety of factors to determine which process to run next, such as the priority of the process, the amount of CPU time that the process has used, and the amount of memory that the process is using.
* **Memory management:** The kernel manages the memory that is used by processes. The kernel allocates memory to processes when they are created, and it deallocates memory when processes are terminated.
* **Inter-process communication (IPC):** The kernel provides mechanisms for processes to communicate with each other. These mechanisms include pipes, sockets, and shared memory.

Process management is a complex and important part of Unix and Linux operating systems. The kernel provides a number of tools and mechanisms to manage processes, and these tools and mechanisms are used to ensure that processes run efficiently and safely.




Sure, here is an example of a C program that creates two processes and then waits for the child processes to finish:

```c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {

  // Create a child process
  pid_t pid = fork();

  // If the child process was created, then execute the child code
  if (pid == 0) {

    // Print a message from the child process
    printf("I am the child process\n");

    // Exit the child process
    exit(0);
  }

  // If the parent process was created, then execute the parent code
  else {

    // Wait for the child process to finish
    wait(NULL);

    // Print a message from the parent process
    printf("I am the parent process\n");

    // Exit the parent process
    exit(0);
  }

  return 0;
}
```

This code will create two processes, one child process and one parent process. The child process will print a message and then exit. The parent process will wait for the child process to finish and then print a message and exit.

The code can be modified to create more than two processes, or to have the child processes do something other than print a message.



The dup() and dup2() system calls in Linux are used to duplicate a file descriptor. dup() creates a new file descriptor that refers to the same open file description as the old file descriptor. dup2() creates a new file descriptor that refers to the same open file description as the old file descriptor, and closes the old file descriptor if necessary.

The following table summarizes the differences between dup() and dup2():

| Feature | dup() | dup2() |
|---|---|---|
| File descriptor | Creates a new file descriptor that refers to the same open file description as the old file descriptor. | Creates a new file descriptor that refers to the same open file description as the old file descriptor, and closes the old file descriptor if necessary. |
| Return value | Returns the new file descriptor. | Returns the new file descriptor, or -1 on error. |
| Error codes | EINTR, EBADF, EINVAL, EMFILE, ENFILE, ENOSPC | EINTR, EBADF, EINVAL, EMFILE, ENFILE, ENOSPC, ENOTFD |

Here is an example of how to use dup() and dup2():

```c
int main() {

  // Open a file
  int fd = open("file.txt", O_RDONLY);

  // Duplicate the file descriptor
  int new_fd = dup(fd);

  // Close the original file descriptor
  close(fd);

  // Read from the new file descriptor
  char buf[1024];
  read(new_fd, buf, sizeof(buf));

  // Close the new file descriptor
  close(new_fd);

  return 0;
}
```

This code will open the file "file.txt" for reading, duplicate the file descriptor, close the original file descriptor, read from the new file descriptor, and close the new file descriptor.

The dup() and dup2() system calls can be used to duplicate file descriptors for a variety of purposes. For example, they can be used to redirect the output of a command to a file, or to create a pipe that can be used for communication between two processes.
