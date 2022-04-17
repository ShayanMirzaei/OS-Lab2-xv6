#include "types.h"
#include "stat.h"
#include "user.h"
#include "syscall.h"

int
main(int argc, char *argv[])
{
    int i, pid;
    int fork_count, write_count;

    for (i = 0; i < 2; i++) {
        pid = fork();
        if (pid < 0)
            exit();
        else if (pid == 0)
            break;
        wait();
    }
    fork_count = get_call_count(SYS_fork);
    write_count = get_call_count(SYS_write);
    pid = getpid();
    printf(0, "pid: %d, fork: %d \n", pid, fork_count);
    printf(0, "pid: %d, write: %d \n", pid, write_count);
    exit();
}
