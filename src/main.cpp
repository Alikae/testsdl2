#include "genekill.h"
#include "init_quit_sdl.h"

int main()
{
    t_params    p;

    if (!init_sdl())
        return (-1);
    if (init_window(&p))
    {
        //init_params
        p.running = 1;
        launch_game(&p);
    }
    quit_window(&p);
    quit_sdl();
    return (0);
}
