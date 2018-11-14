#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include "master.h"
#include "gui.h"

void init();
void afficherEcran(SDL_Renderer * renderer);

int main()
{
    init();

    SDL_Window * window;
    SDL_Event event;
    SDL_Renderer* renderer;
    int width = 800;
    int height = 800;
    int running = 1;

    Case plateau[NB_LIGNES][NB_COLONNES+2];
    init_plateau_gui(plateau);

    window = SDL_CreateWindow("SDL2 Programme 0.1", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                width, height,
                SDL_WINDOW_RESIZABLE);
    if (window == 0)
        fprintf(stderr, "Erreur d'initialisation de la SDL : %s\n", SDL_GetError());

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if(renderer == 0)
        fprintf(stderr, "Erreur d'initialisation de la SDL : %s\n", SDL_GetError());

    while (running)
    {
        while (SDL_PollEvent(&event))
        {
            switch(event.type)
            {
                case SDL_WINDOWEVENT:
                    switch (event.window.event)
                    {
                        case SDL_WINDOWEVENT_CLOSE:
                            printf("appui sur la croix\n");
                            break;
                        case SDL_WINDOWEVENT_SIZE_CHANGED:
                            width = event.window.data1;
                            height = event.window.data2;
                            printf("Size : %d%d\n", width, height);
                        default:
                            afficher(renderer, plateau);
                    }
                    break;
                case SDL_MOUSEBUTTONDOWN:
                    printf("Appui :%d %d\n", event.button.x, event.button.y);
                    // afficherEcran() ?
                    break;
                case SDL_QUIT :
                    printf("on quitte\n");
                    running = 0;
            }
        }
        SDL_Delay(1); //  delai minimal
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    IMG_Quit();
    TTF_Quit();
    SDL_Quit();
    return 0;
}

void init()
{
    if (SDL_Init(SDL_INIT_VIDEO) == -1)
    {
        fprintf(stderr, "Erreur d'initialisation de la SDL : %s\n", SDL_GetError());
    }
    int flags=IMG_INIT_JPG|IMG_INIT_PNG;
    int initted= 0;

    if (TTF_Init() != 0)
    {
        fprintf(stderr, "Erreur d'initialisation TTF : %s\n", TTF_GetError());
    }

    initted = IMG_Init(flags);

    if((initted&flags) != flags)
    {
        printf("IMG_Init: Impossible d'initialiser le support des formats JPG et PNG requis!\n");
        printf("IMG_Init: %s\n", IMG_GetError());
    }
}

void afficherEcran(SDL_Renderer * renderer)
{
    SDL_Rect rect;

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
    SDL_RenderClear(renderer);

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 0);
    rect.x = rect.y = 0;
    rect.w = rect.h = 600;
    SDL_RenderFillRect(renderer, &rect );

    SDL_RenderPresent(renderer);
}