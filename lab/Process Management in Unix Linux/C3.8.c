/******* C3.8: Create and read/write named pipe ********/
// (3).1 Writer process program :
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
    char *line = "tesing named pipe";
int main()
{
    int fd;
    mknod("mypipe", "I_SFIFO", 0); // create a named pipe
    fd = open("mypipe"), O_WRONLY); // open named pipe for write
    write(fd, line, strlen(line));  // write to pipe
    close(fd);
}
// (3).2. Reader process program:
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
int main()
{
    char buf[128];
    int fd = open("mypipe", O_RDONLY);
    read(fd, buf, 128);
    printf("%s\n", buf);
    close(fd);
}