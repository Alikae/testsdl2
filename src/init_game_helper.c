#include "genekill.h"
#include "character.h"

int fill_map(t_params *p, t_chunk **canvas, SDL_Texture **sprites, Physical_object **objects)
{
    int i;
    int j;
    int k;
    int l;

    i = -1;
    while (++i < p->map_width)
    {
        j = -1;
        while (++j < p->map_height)
        {
            k = -1;
            while (++k < 15)
            {
                l = -1;
                while (++l < 15)
                {
                    if (!(canvas[i][j].background[k][l] = create_sprite_lst(sprites[0])))
                    {
                        //empty_map();
                        return (0);
                    }
                }
            }
        }
    }
    if (!add_to_object_lst(&(canvas[p->players[0]->sget_position()->x / 256][p->players[0]->sget_position()->y / 256].objects), objects[0]))
    {
        //empty_map()
        return (0);
    }
    //
    canvas[0][0].background[0][0]->sprite = sprites[1];
    //
    return (1);
}

int init_map(t_params *p, t_chunk ***pcanvas)
{
    int i;
    int j;
    int k;
    int l;

    if (!(*pcanvas = (t_chunk**)malloc(p->map_width * sizeof(t_chunk*))))
        return (0);
    i = -1;
    while (++i < p->map_width)
        if (!((*pcanvas)[i] = (t_chunk*)malloc(p->map_height * sizeof(t_chunk))))
        {
            while (i--)
                free((*pcanvas)[i]);
            free(*pcanvas);
            return (0);
        }
    i = -1;
    while (++i < p->map_width)
    {
        j = -1;
        while (++j < p->map_height)
        {
            k = -1;
            while (++k < 16)
            {
                l = -1;
                while (++l < 16)
                {
                    (*pcanvas)[i][j].background[k][l] = 0;
                    (*pcanvas)[i][j].foreground[k][l] = 0;
                }
            }
            (*pcanvas)[i][j].objects = 0;
        }
    }
    return (1);
}

int init_players(t_params *p, Physical_object **objects)
{
    if (!(p->players = (Physical_object**)malloc(2 * sizeof(Physical_object*))))
        return (0);
    p->players[0] = objects[0];
    p->players[1] = 0;
    return (1);
}

int init_objects(Physical_object ***pobjects, SDL_Texture **sprites)
{
    if (!((*pobjects) = (Physical_object**)malloc(2 * sizeof(Physical_object*))))
        return (0);
    (*pobjects)[0] = new Character();
    (*pobjects)[0]->init(sprites[1], 256 + 16 * 2 + 10, 16 * 5 + 14);
    (*pobjects)[1] = 0;
    return (1);
}
