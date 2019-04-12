#include "genekill.h"
#include "t_chunk.h"
#include "sprite.h"

int     init_game(t_params *p, t_chunk ***pcanvas, SDL_Texture ***psprites, Physical_object ***pobjects)
{
    if (!init_sprites(p, psprites))
        return (0);
    if (!(init_objects(pobjects, *psprites)))
    {
        free_sprites(*psprites);
        return (0);
    }
    init_players(p, *pobjects);
    if (!init_map(p, pcanvas))
    {
        //free_objects(*pobjects); 
        free_sprites(*psprites);
        return (0);
    }
    if (!fill_map(p, *pcanvas, *psprites, *pobjects))
    {
        //free_map();
        //free_objects(*pobjects); 
        free_sprites(*psprites);
        return (0);
    }
    return (1);
}

void    quit_game(t_params *p, t_chunk **canvas, SDL_Texture **sprites)
{
    //empty_map;
    //free_map;
    //free_players;
    //free_objects;
    free_sprites(sprites);
}

void    launch_game(t_params *p)
{
    t_chunk         **canvas;
    SDL_Texture     **sprites;
    Physical_object **objects;
    unsigned int    frame_wait;

    //
    p->screen_width = 800;
    p->screen_height = 600;
    p->map_width = 10;
    p->map_height = 5;
    p->scale = 1;
    frame_wait = 0;
    //
    if (!init_game(p, &canvas, &sprites, &objects))
        return;
    while (p->running)
    {
        int count = 0;
        while (!SDL_TICKS_PASSED(SDL_GetTicks(), frame_wait))
        {
            count++;
            SDL_Delay(1);
        }
        printf("%i ms waited\n", count);
        frame_wait = SDL_GetTicks() + 16;
        render_screen(p, canvas);
        read_input(p, canvas);
        //calc_next_frame();
    }
    quit_game(p, canvas, sprites);
}
