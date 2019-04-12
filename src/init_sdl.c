#include "SDL/SDL.h"
#include "genekill.h"

void    quit_window(t_params *p)
{
    SDL_DestroyRenderer(p->renderer);
    SDL_DestroyWindow(p->window);
}

int     init_window(t_params *p)
{
    p->renderer = 0;
    if (!(p->window = SDL_CreateWindow(GAME_NAME, 
                    SDL_WINDOWPOS_CENTERED,
                    SDL_WINDOWPOS_CENTERED,
                    SCREEN_INIT_WIDTH,
                    SCREEN_INIT_HEIGHT,
                    SDL_WINDOW_SHOWN)))
        return (0);
    if (!(p->renderer = SDL_CreateRenderer(p->window, -1, SDL_RENDERER_ACCELERATED)))
        return (0);
    SDL_SetRenderDrawColor(p->renderer, 255, 255, 255, 255);
    return (1);
}

void    quit_sdl(void)
{
    SDL_Quit();
}

int     init_sdl(void)
{
    if (SDL_Init(SDL_INIT_VIDEO))
        return (0);
    return (1);
}
