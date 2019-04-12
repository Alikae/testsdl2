#ifndef T_SPRITE_LST_H
# define T_SPRITE_LST_H

typedef struct  s_sprite_lst t_sprite_lst;
# include "sprite.h"

struct  s_sprite_lst
{
    SDL_Texture         *sprite;
    struct s_sprite_lst *next;
};

t_sprite_lst    *create_sprite_lst(SDL_Texture *sprite);
void            delete_all_sprite_lst(t_sprite_lst *origin);
t_sprite_lst    *add_to_sprite_lst(t_sprite_lst **porigin, SDL_Texture *sprite);

#endif
