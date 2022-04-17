#include "types.h"
#include "stat.h"
#include "user.h"

int
main(int argv, char *argc[]) {

    int prime = atoi(argc[1]);

    printf(0, "%d\n", find_next_prime_number(prime));
    exit();
}