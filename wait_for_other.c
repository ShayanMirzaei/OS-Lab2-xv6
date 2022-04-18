#include "types.h"
#include "stat.h"
#include "user.h"
#include "syscall.h"

int
main(int argc, char *argv[])
{
    int pid1, pid2;
    pid1 = fork();
    if (pid1 < 0)
        exit();
    else if (pid1 == 0) {
        printf(0, "Child 1 started\n");
        sleep(100);
        printf(0, "Child 1 loop ended\n");
        exit();
    }
    else {
        pid2 = fork();
        if (pid2 < 0)
            exit();
        else if (pid2 == 0) {
            printf(0, "Child 2 is waiting\n");
            wait_for_process(pid1);
            printf(0, "Child 2 returned\n");
        }
        else {
            wait();
        }
    }

    wait();
    exit();
}
