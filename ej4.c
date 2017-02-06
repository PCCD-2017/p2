#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * @note Comenzamos creando la variable pid_t,
 * pid_t representa el ID de un proceso,
 * podemos obtener el ID del proceso utilizando
 * la funcion getpid().
 *
 * @note Despues de esto, creamos un for que sera
 * recorrido tres veces para obtener 3 hijos.
 *
 * @note tal y como indica el manual de fork, se devolvera
 * un 0 al proceso hijo, por ello, si pid_t es 0 significa
 * que estamos en el proceso hijo.
 *
 *
 * @return 0
 */

int main(int argc, char *argv[])
{
    pid_t child_id ;
    int status,fin=0;

    system("clear");

    for (int i = 0; i < 3; ++i) {
        child_id = fork();
        if (child_id == 0) {
            /**
             * Children.
             */
            printf("Proceso hijo %d se ha creado\n",getpid());
            execl("p2ej4","Ay","mi","madre","el","bicho\n");
            sleep(5);
            return 0;
        }
    }

    while (fin < 3) {
        child_id = wait(&status);
        fin = fin + 1;
        printf("Proceso hijo finalizado con PID: %d con codigo de finalizacion: %d\n",child_id,status);
    }

    return 0;
}