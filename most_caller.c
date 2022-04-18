#include "types.h"
#include "stat.h"
#include "user.h"
#include "syscall.h"

int
main(int argc, char *argv[])
{
    int fork_caller, write_caller, wait_caller;

    fork_caller = get_most_caller(SYS_fork);
    write_caller = get_most_caller(SYS_write);
    wait_caller = get_most_caller(SYS_wait);

    printf(0,"fork() most caller: %d\n", fork_caller);
    printf(0,"write() most caller: %d\n", write_caller);
    printf(0,"wait() most caller: %d\n", wait_caller);

    exit();
}
