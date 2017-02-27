#include <stdio.h>
#include <sys/resource.h>

int main() {
    struct rlimit lim;
    struct rlimit rlp;
    struct rlimit fsize;
    getrlimit(RLIMIT_STACK, &lim);
    getrlimit(RLIMIT_NPROC, &rlp);
    getrlimit(RLIMIT_FSIZE, &fsize);
    printf("stack size: %ld\n", lim.rlim_cur);
    printf("process limit: %ld\n", rlp.rlim_cur);
    printf("max file descriptors: %ld\n", fsize.rlim_cur);
    return 0;
}
