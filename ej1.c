#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <signal.h>
#include <stdlib.h>


/**
 * @header void handler(int);
 *
 * Función usada para detectar las
 * señales.
 *
 * @param signum
 */

void handler(int);


/**
 * Variables globales
 */
 int count = 0;


/**
 * @note Comenzamos creando la variable pid_t,
 * pid_t representa el ID de un proceso,
 * podemos obtener el ID del proceso utilizando
 * la funcion getpid().
 *
 * @note Despues de esto, creamos un for que sera
 * recorrido tres veces tal y como indica el enunciado.
 *
 * @note tal y como indica el manual de fork, se devolvera
 * un 0 al proceso hijo, por ello, si pid_t es 0 significa
 * que estamos en el proceso hijo.
 *
 *
 * @return 0
 */

int main()
{
    pid_t child_id ;

    for (int i = 0; i < 3; ++i) {
        printf("su antes\n");
        child_id = fork() ;
        if (child_id  == 0) {
            printf("Se ha creado un proceso hijo %d\n",getpid());
            sleep(5);
            exit(0);
        }
    }

    struct sigaction act;
    memset(&act,0, sizeof(act));
    act.sa_handler = handler;
    act.sa_flags = 0;

    for (int i = 3; i < 30; ++i) {
        sigaction(i, &act, NULL);
    }

    for (int j = 0; j < 3; ++j) {
        pause();
    }

    return 0;
}

void handler(int signum){
    switch (signum){
        case SIGCHLD:
            count =  count + 1;
            printf("Un proceso hijo a finalizado\n");
            break;
        default:
            break;
    }
    return;
}