#include "master.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main(int argc, char ** argv)
{
    int plateau[NB_LIGNES][NB_COLONNES+2];
    int solution[NB_COLONNES];
    int proposition[NB_COLONNES];
    int i;
    combinaison c;
    int nb_tour = 0;

/*
    printf("\033[0;40m");
    printf("COLORTEST\n");
    printf("\033[1;41m");
    printf("COLORTEST\n");
    printf("\033[42m");
    printf("COLORTEST\n");
    printf("\033[43m");
    printf("COLORTEST\n");
    printf("\033[44m");
    printf("COLORTEST\n");
    printf("\033[45m");
    printf("COLORTEST\n");
    printf("\033[46m");
    printf("COLORTEST\n");
    printf("\033[47m");
    printf("COLORTEST\n");
*/

    // Init
    initialiser_proposition(proposition);
    initialiser_plateau(plateau);
    if(argc > 1)
        initialiser_solution_germe(solution, atoi(argv[1]));
    else
        initialiser_solution(solution);


    afficher_solution(solution);

    do {
        printf("Tour %d\n", nb_tour+1);
        afficher_plateau(plateau);

        do {
            printf("Saisir un jeu de couleur commme 1 1 2 3, valider par entree :\n");
            for(i = 0; i < NB_COLONNES; i++)
                scanf("%d", &proposition[i]);
        } while(!proposition_correcte(proposition));

        c = compiler_proposition(proposition, solution);

        for(i = 0; i < NB_COLONNES; i++)
            plateau[nb_tour][i] = proposition[i];
        plateau[nb_tour][i++] = c.bienp;
        plateau[nb_tour][i] = c.malp;

        nb_tour++;

    } while(nb_tour < NB_LIGNES && !gagne(c));

    if(gagne(c))
    {
        printf("###########################\n");
        printf("Bien joue, vous avez gagne!\n");
    }
    else
    {
        printf("###########################\n");
        printf("Dommage, vous avez perdu!\n");
    }
    printf("La solution etait:\n");
    afficher_solution(solution);

    return 0;
}