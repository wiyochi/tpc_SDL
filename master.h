#ifndef MASTER_H
#define MASTER_H

/* DECLARATION DES CONSTANTES SYMBOLIQUES */

#define NB_LIGNES 10
#define NB_COLONNES 4
#define NB_COULEURS 6

#define BLACK    "\033[1;30m"
#define RED      "\033[1;31m"
#define GREEN    "\033[1;32m"
#define YELLOW   "\033[1;33m"
#define BLUE     "\033[1;34m"
#define PURPLE   "\033[1;35m"
#define CYAN     "\033[1;36m"
#define GREY     "\033[1;37m"
#define DEFAULT_COLOR "\033[1;m"

/* DECLARATION DES TYPES PERSONNELS */
// et de leur typedef si besoin

typedef struct {
    int bienp;
    int malp;
} combinaison;

/* DECLARATIONS DES METHODES */

void initialiser_solution(int solution[NB_COLONNES]);
void initialiser_solution_germe(int solution[NB_COLONNES], int germe);
void initialiser_plateau (int plateau[NB_LIGNES][NB_COLONNES+2]);
void initialiser_proposition(int proposition[NB_COLONNES]);
combinaison compiler_proposition(int proposition[NB_COLONNES], int solution[NB_COLONNES]);
void afficher_plateau(int plateau[NB_LIGNES][NB_COLONNES+2]);
void afficher_solution(int solution[NB_COLONNES]);
int proposition_correcte(int proposition[NB_COLONNES]);
int gagne(combinaison c);

#endif //!MASTER_H