#include "t_sprite_lst.h"

t_sprite_lst    *create_sprite_lst(SDL_Texture *sprite)
{
    t_sprite_lst    *spr_lst;

    if ((spr_lst = (t_sprite_lst*)malloc(sizeof(t_sprite_lst))))
    {
        spr_lst->sprite = sprite;
        spr_lst->next = 0;
    }
    return (spr_lst);
}

void            delete_all_sprite_lst(t_sprite_lst *origin)
{
    t_sprite_lst    *tmp;

    while (origin)
    {
        tmp = origin;
        origin = origin->next;
        free(tmp);
    }
}

t_sprite_lst    *add_to_sprite_lst(t_sprite_lst **porigin, SDL_Texture *sprite)
{
    t_sprite_lst    *tmp;

    if (!*porigin)
        return ((*porigin = create_sprite_lst(sprite)));
    tmp = *porigin;
    while (tmp->next)
        tmp = tmp->next;
    return ((tmp->next = create_sprite_lst(sprite)));
}
