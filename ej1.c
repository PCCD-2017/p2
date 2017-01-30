#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <signal.h>

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
 int fin = 0;


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
    struct sigaction act;

    for (int i = 0; i < 3; ++i) {
            child_id = fork();
            if (child_id == 0){
                /**
                 * Children.
                 */
                sleep(5);
                return 0;
            } else continue;
    }

    memset(&act,0, sizeof(act));
    act.sa_handler = handler;
    act.sa_flags = 0;
    sigaction(SIGCHLD,&act,NULL);

    while (fin < 3)
        pause();

    return 0;
}

void handler(int signum){
    switch (signum){
        case SIGCHLD:
            fin = fin + 1;
            printf("Un proceso hijo a finalizado\n");
            break;
        default:
            break;
    }
    return;
}