#include <stdio.h>
#include <sys/resource.h>

int main() {
    struct rlimit rl;

    getrlimit(RLIMIT_STACK, &rl);
    printf("stack size: %lu\n", rl.rlim_cur);

    getrlimit(RLIMIT_NPROC, &rl);
    printf("process limit: %lu\n", rl.rlim_cur);

    getrlimit(RLIMIT_NOFILE, &rl);
    printf("max file descriptors: %lu\n", rl.rlim_cur);

    return 0;
}
