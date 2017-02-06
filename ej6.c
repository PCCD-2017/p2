/**
 * Ejercicio 5 de la práctica 2
 */

#include <stdio.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * fflush(0)  to empty all I/O buffers before forking.
 * @param argc
 * @param argv
 * @return 0
 */

int main(){

    char* alineacion[11] = {"De Gea", "Carvajal", "Ramos", "Piqué", "Jordi-Alba", "Busquets", "Nolito", "Isco", "Iniesta", "Silva", "Aspas"};
    int status,count = 0;
    pid_t child_aux,child_carvajal,child_ramos,child_pique, child_iniesta_silva;

    /**
     * DE GEA.
     */
    printf("%s ",alineacion[0]);

    /**
     * CARVAJAL, RAMOS, PIQUE.
     */
    for (int i = 1; i < 4; ++i) {
        child_aux = fork();
        if (child_aux == 0){
            execl("p2ej4",alineacion[i]);
        } else{
            switch (i){
                case 1:
                    child_carvajal = child_aux;
                    break;
                case 2:
                    child_ramos = child_aux;
                    break;
                case 3:
                    child_pique = child_aux;
                    break;
                default:
                    break;
            }
        }
    }

    /**
     * JORDI ALBA
     */
    printf("%s ",alineacion[4]);

    /**
     * INIESTA,SILVA.
     */

    child_aux = fork();
    if (child_aux == 0){
        execl("p2ej4",alineacion[8],alineacion[9]);
    } else{
        child_iniesta_silva = child_aux;
    }

    while (count < 3){
        child_aux = wait(&status);
        if(child_aux == child_carvajal || child_aux == child_ramos || child_aux == child_pique)
            count = count + 1;
    }

    /**
     * BUSQUETS, NOLITO, ISCO.
     */
    printf("%s ",alineacion[5]);
    printf("%s ",alineacion[6]);
    printf("%s ",alineacion[7]);

    while (count == 0){
        child_aux = wait(&status);
        count = count +1;
    }

    return 0;

    /**
     * ASPAS
     */
    while (1){
        child_aux = wait(&status);
        if(child_aux == child_iniesta_silva){
            printf("%s \n",alineacion[10]);
            break;
        }
    }

    return 0;
}