#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main(int argc, char *argv[]) {
    printf("El proceso que me ha invocado ha sido: %d\n", getpid());
    for (int i = 0; i < (argc - 1); ++i) {
        if (i < (argc - 2)) printf("%s ", argv[i]);
        else printf(" %s\n", argv[i]);
    }
    return 0;
}