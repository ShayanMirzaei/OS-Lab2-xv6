#include "types.h"
#include "stat.h"
#include "user.h"
#include "syscall.h"

int
main(int argc, char *argv[])
{
    int pid = getpid();
    printf(0, "Process ID: %d\n", pid);
    exit();
}
