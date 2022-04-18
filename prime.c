#include "types.h"
#include "stat.h"
#include "user.h"

int
main(int argc, char *argv[]) {

    int n = atoi(argv[1]);
    int ebx_old_val;

    asm (
            "movl %%ebx, %0;"
            "movl %1, %%ebx;"
            : "=r" (ebx_old_val)
            : "r" (n)
            : "%ebx"
            );
    printf(0, "ebx value before system call: %d\n", ebx_old_val);
    printf(0, "%d\n", find_next_prime_number());

    asm (
            "movl %0, %%ebx;"
            :: "r" (ebx_old_val)
            );

    asm (
            "movl %%ebx, %0;"
            : "=r" (ebx_old_val)
            );
    printf(0, "ebx value after system call: %d\n", ebx_old_val);

    exit();
}