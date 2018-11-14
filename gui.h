#ifndef GUI_H
#define GUI_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include "master.h"

#define WIN_WIDTH 800
#define WIN_HEIGHT 800
#define OFFSET_X 10
#define OFFSET_Y 10
#define RECT_SIZE 50

enum ETAT
{
    INTRO,
    JEU,
    FIN
};

typedef struct
{
    int r;
    int g;
    int b;
    int a;
} Color;

typedef struct
{
    SDL_Rect* rect;
    Color color;
} Case;

void afficher_plateau_gui(SDL_Renderer* renderer, Case* plateau[NB_LIGNES][NB_COLONNES+2]);
void afficher_case(SDL_Renderer* renderer, Case* c);
void init_plateau_gui(Case* plateau[NB_LIGNES][NB_COLONNES+2]);

void afficher(SDL_Renderer * renderer, Case* plateau[NB_LIGNES][NB_COLONNES+2]);


#endif // !GUI_H