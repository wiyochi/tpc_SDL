#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "master.h"

// un petit commentaire ?
void initialiser_solution(int solution[NB_COLONNES])
{
    int i;
    srand(time(NULL));
    for(i = 0; i < NB_COLONNES; i++)
    {
        solution[i] = (rand()%6)+1;
    }
}

void initialiser_solution_germe(int solution[NB_COLONNES], int germe)
{
    int i;
    srand(germe);
    for(i = 0; i < NB_COLONNES; i++)
    {
        solution[i] = (rand()%6)+1;
    }
}

// un petit commentaire ?
void initialiser_plateau(int plateau[NB_LIGNES][NB_COLONNES+2])
{
    int i, j;
    for(i = 0; i < NB_LIGNES; i++)
    {
        for(j = 0; j < NB_COLONNES+2; j++)
        {
            plateau[i][j] = 0;;
        }
    }
}

void initialiser_proposition(int proposition[NB_COLONNES])
{
    int i;
    for(i = 0; i < NB_COLONNES; i++)
    {
        proposition[i] = 0;
    }
}

combinaison compiler_proposition(int proposition[NB_COLONNES], int solution[NB_COLONNES])
{
    int i, j;
	combinaison c;
    c.bienp = 0;
    c.malp = 0;

    int trouve[NB_COLONNES] = {0, 0, 0, 0};
    int utilise[NB_COLONNES] = {0, 0, 0, 0};

    for(i = 0; i < NB_COLONNES; i++)
    {
        if(proposition[i] == solution[i])
        {
            c.bienp++;
            trouve[i] = 1;
            utilise[i] = 1;
        }
    }

    for(i = 0; i < NB_COLONNES; i++)
    {
        for(j = 0; j < NB_COLONNES; j++)
        {
            if(i != j && proposition[i] == solution[j] && trouve[j] != 1 && utilise[i] != 1)
            {
                c.malp++;
                trouve[j] = 1;
                utilise[i] = 1;
            }
        }
    }
    return c;
}

void afficher_plateau(int plateau[NB_LIGNES][NB_COLONNES+2])
{
    int i, j;

    printf("=============b=m==\n");
    for(i = 0; i < NB_LIGNES; i++)
    {
        printf("| ");
        for(j = 0; j < NB_COLONNES+2; j++)
        {
            if(j == 4)
                printf("|| ");
            printf("%d ", plateau[i][j]);
        }
        printf("|\n");
    }
    printf("==================\n");
}


void afficher_solution(int solution[NB_COLONNES])
{
    int i;
    printf("Solution: ");
    for(i = 0; i < NB_COLONNES; i++)
        printf("%d ", solution[i]);
    printf("\n");
}

int proposition_correcte(int proposition[NB_COLONNES])
{
    int i = 0;

    while(i < NB_COLONNES && proposition[i] > 0 && proposition[i] < 7)
        i++;

    return (i == NB_COLONNES);
}

int gagne(combinaison c)
{
    return (NB_COLONNES == c.bienp);
}