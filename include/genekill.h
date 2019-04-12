#ifndef GENEKILL_H
# define GENEKILL_H

typedef struct  s_params t_params;
class   Physical_object;
# include "physical_object.h"
# include "t_chunk.h"
# include "SDL/SDL.h"

# define GAME_NAME "genekill yourself"
# define SCREEN_INIT_WIDTH 1920
# define SCREEN_INIT_HEIGHT 1080

struct  s_params
{
    SDL_Window      *window;
    SDL_Renderer    *renderer;
    int             running;
    Physical_object **players;
    int             screen_width;
    int             screen_height;
    int             map_width;
    int             map_height;
    int             scale;
};

int     fill_map(t_params *p, t_chunk **canvas, SDL_Texture **sprites, Physical_object **objects);
int     init_map(t_params *p, t_chunk ***pcanvas);
int     init_objects(Physical_object ***pobjects, SDL_Texture **sprites);
int     init_players(t_params *p, Physical_object **objects);
void    launch_game(t_params *p);
void    read_input(t_params *p, t_chunk **canvas);
void    render_screen(t_params *p, t_chunk **canvas);

#endif
