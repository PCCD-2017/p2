#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    pid_t child_id;
    pid_t lastChild_id;
    int status, fin = 0;

    system("clear");

    printf("PID padre : %d \n", getpid());

    for (int i = 0; i < 3; ++i) {
        child_id = fork();
        if (child_id == 0) {
            /**
             * Children.
             */
            printf("Proceso hijo %d se ha creado\n", getpid());
            sleep(5 + i);
            exit(EXIT_SUCCESS);
        } else {
            if (child_id > 0) {
                lastChild_id = child_id;
            }
        }
    }

    while (1) {
        child_id = waitpid(lastChild_id, &status, 0);
        fin = fin + 1;
        printf("Proceso hijo finalizado con PID: %d con codigo de finalizacion: %d\n", child_id, status);
        pause();
    }
    return 0;
}

