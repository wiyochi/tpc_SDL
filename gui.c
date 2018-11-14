#include "gui.h"

void afficher_plateau_gui(SDL_Renderer* renderer, Case* plateau[NB_LIGNES][NB_COLONNES+2])
{
    int i, j;

    for(i = 0; i < NB_LIGNES; i++)
    {
        for(j = 0; j < NB_COLONNES+2; j++)
        {
            afficher_case(renderer, plateau[i][j]);
        }
    }
}

void afficher_case(SDL_Renderer* renderer, Case* c)
{
    SDL_SetRenderDrawColor(renderer,\
                            c->color.r,\
                            c->color.g,\
                            c->color.b,\
                            c->color.a\
                            );
    SDL_RenderFillRect(renderer, c->rect);
}

void init_plateau_gui(Case* plateau[NB_LIGNES][NB_COLONNES+2])
{
    int i, j;

    for(i = 0; i < NB_LIGNES; i++)
    {
        for(j = 0; j < NB_COLONNES+2; j++)
        {
            plateau[i][j] = malloc(sizeof(Case));
            plateau[i][j]->color.r = 0;
            plateau[i][j]->color.g = 0;
            plateau[i][j]->color.b = 0;
            plateau[i][j]->color.a = 0;
            plateau[i][j]->rect = malloc(sizeof(SDL_Rect));
            plateau[i][j]->rect->w = RECT_SIZE;
            plateau[i][j]->rect->h = RECT_SIZE;
            plateau[i][j]->rect->x = OFFSET_Y + j*(RECT_SIZE+5);
            plateau[i][j]->rect->y = OFFSET_X + i*(RECT_SIZE+5);
        }
    }
}

void afficher(SDL_Renderer * renderer, Case* plateau[NB_LIGNES][NB_COLONNES+2])
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
    SDL_RenderClear(renderer);

    afficher_plateau_gui(renderer, plateau);

    SDL_RenderPresent(renderer);
}