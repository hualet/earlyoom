#include <unistd.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

int run_process(const char *prog, char *const argv[])
{
    pid_t pid = fork();

    if (pid == 0) // this is the child process
    {
        execv(prog, argv);
        printf("command %s is not found, error code: %d(%s)", prog, errno, strerror(errno));
    }

    int status = 0;

    waitpid(pid, &status, 0);

    return status;
}