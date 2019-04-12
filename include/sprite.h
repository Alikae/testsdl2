#ifndef SPRITE_H
# define SPRITE_H

# include "SDL/SDL.h"
# include "genekill.h"

SDL_Texture *create_sprite(SDL_Renderer *renderer, const char *path);
void        delete_sprite(SDL_Texture *texture);
int         init_sprites(t_params *p, SDL_Texture ***psprites);
void        free_sprites(SDL_Texture **sprites);

#endif
