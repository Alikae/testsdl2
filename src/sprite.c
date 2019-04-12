#include "SDL/SDL.h"
#include "genekill.h"

SDL_Texture *create_sprite(SDL_Renderer *renderer, const char *path)
{
    SDL_Surface *surface;
    SDL_Texture *texture;

    if (!(surface = SDL_LoadBMP(path)))
        return (0);
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
    return (texture);
}

void        delete_sprite(SDL_Texture *texture)
{
    SDL_DestroyTexture(texture);
}

int         init_sprites(t_params *p, SDL_Texture ***psprites)
{
    if (!(*psprites = (SDL_Texture**)malloc(3 * sizeof(SDL_Texture*))))
        return (0);
    if (!((*psprites)[0] = create_sprite(p->renderer, "images/wall.bmp")))
    {
        free(*psprites);
        return (0);
    }
    if (!((*psprites)[1] = create_sprite(p->renderer, "images/perso.bmp")))
    {
        delete_sprite((*psprites)[0]);
        free(*psprites);
        return (0);
    }
    (*psprites)[2] = 0;
    return (1);
}

void        free_sprites(SDL_Texture **sprites)
{
    int i;

    i = -1;
    while (sprites[++i])
        delete_sprite(sprites[i]);
    free (sprites);
}
