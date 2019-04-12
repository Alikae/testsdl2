#ifndef T_CHUNK_H
# define T_CHUNK_H

typedef struct  s_chunk t_chunk;

# include "t_sprite_lst.h"
# include "t_object_lst.h"

struct  s_chunk
{
    t_sprite_lst    *background[16][16];
    t_sprite_lst    *foreground[16][16];
    t_object_lst    *objects;
};

void    move_object_lst_in_chunk(t_chunk *dest, t_chunk *src, int id);

#endif
