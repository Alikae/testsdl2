#include "genekill.h"

void    render_objects(t_params *p, t_chunk **canvas, int xcam, int ycam, t_pos chunk_min, t_pos chunk_max)
{
    SDL_Rect        dest;
    int             x;
    int             y;
    t_pos           screen_center;
    t_object_lst    *obj_lst;

    screen_center.x = p->screen_width / 2;
    screen_center.y = p->screen_height / 2;
    x = chunk_min.x - 1;
    while (++x < chunk_max.x)
    {
        y = chunk_min.y - 1;
        while (++y < chunk_max.y)
        {
            obj_lst = canvas[x][y].objects;
            while (obj_lst)
            {
                dest = {
                    (obj_lst->object->sget_position()->x - 8) * p->scale - (xcam - screen_center.x),
                    p->screen_height - ((obj_lst->object->sget_position()->y - 8) * p->scale - (ycam - screen_center.y)),
                    16 * p->scale, 16 * p->scale};
                //if (!(x || y))
                    //printf("dest: x%i, y%i, w%i, h%i\n", dest.x, dest.y, dest.w, dest.h);
                //SDL_RenderCopy(p->renderer, obj_lst->object->get_sprite(), 0, &dest);
                obj_lst = obj_lst->next;
            }
        }
    }
}

void    render_background(t_params *p, t_chunk **canvas, int xcam, int ycam, t_pos chunk_min, t_pos chunk_max)
{
    SDL_Rect        dest;
    int             x;
    int             y;
    int             i;
    int             j;
    t_pos           screen_center;
    t_sprite_lst    *spr_lst;

    screen_center.x = p->screen_width / 2;
    screen_center.y = p->screen_height / 2;
    i  = -1;
    while (++i < 16)
    {
        j = -1;
        while (++j < 16)
        {
            x = chunk_min.x - 1;
            while (++x < chunk_max.x)
            {
                y = chunk_min.y - 1;
                while (++y < chunk_max.y)
                {
                    spr_lst = canvas[x][y].background[i][j];
                    while (spr_lst)
                    {
                        dest = {(256 * p->scale * x + 16 * p->scale * i) - (xcam - screen_center.x) - 8 * p->scale, p->screen_height - ((256 * p->scale * y + 16 * p->scale * j) - (ycam - screen_center.y)) - 8 * p->scale, 16 * p->scale, 16 * p->scale};
                        //if (!(i || j || x || y))
                            //printf("dest: x%i, y%i, w%i, h%i\n", dest.x, dest.y, dest.w, dest.h);
                        //SDL_RenderCopy(p->renderer, spr_lst->sprite, 0, &dest);
                        spr_lst = spr_lst->next;
                    }
                }
            }
        }
    }
}

void    render_screen(t_params *p, t_chunk **canvas)
{
    t_pos   chunk_min;
    t_pos   chunk_max;
    int     xcam;
    int     ycam;
    int     tmp;

    SDL_RenderClear(p->renderer);
    xcam = p->players[0]->sget_position()->x * p->scale;
    ycam = p->players[0]->sget_position()->y * p->scale;
    chunk_min.x = ((tmp = xcam / 256 - 2) > 0) ? tmp : 0;
    chunk_min.y = ((tmp = ycam / 256 - 2) > 0) ? tmp : 0;
    chunk_max.x = ((tmp = xcam / 256 + 2) < p->map_width) ? tmp : p->map_width - 1;
    chunk_max.y = ((tmp = ycam / 256 + 2) < p->map_height) ? tmp : p->map_height - 1;
    //printf("min:%i, %i\nmax: %i, %i\nhere: %i, %i\n", chunk_min.x, chunk_min.y, chunk_max.x, chunk_max.y, xcam / 256, ycam / 256);
    render_background(p, canvas, xcam, ycam, chunk_min, chunk_max);
    render_objects(p, canvas, xcam, ycam, chunk_min, chunk_max);
    //foreach chunks around cam
    //  render objects
    //render_players
    //foreach chunks around cam
    //  for i 16 j 16
    //      render foreground
    SDL_RenderPresent(p->renderer);
}
