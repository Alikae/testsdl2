#include "genekill.h"
#include "SDL/SDL.h"

void    read_input(t_params *p, t_chunk **canvas)
{
    const Uint8 *keyboard_state_array;
    SDL_Event   ev;

    keyboard_state_array = SDL_GetKeyboardState(NULL);
    //printf("x: %i, y: %i\n", p->players[0]->sget_position()->x, p->players[0]->sget_position()->y);
    while (SDL_PollEvent(&ev))
    {
        switch (ev.type)
        {
            case SDL_WINDOWEVENT:
            {
                if (ev.window.event == SDL_WINDOWEVENT_CLOSE)
                    p->running = 0;
                break;
            }
            case SDL_KEYDOWN:
            {
                //update map
                if (ev.type == SDL_KEYDOWN || ev.type == SDL_KEYUP)
                {
                    if (keyboard_state_array[SDL_SCANCODE_UP])
                    {
                        p->players[0]->sget_position()->y++;
                    }
                    else if (keyboard_state_array[SDL_SCANCODE_DOWN])
                    {
                        p->players[0]->sget_position()->y--;
                    }
                    if (keyboard_state_array[SDL_SCANCODE_RIGHT])
                    {
                        p->players[0]->sget_position()->x++;
                    }
                    else if (keyboard_state_array[SDL_SCANCODE_LEFT])
                    {
                        p->players[0]->sget_position()->x--;
                    }
                }
                switch (ev.key.keysym.sym)
                {
                    /*
                    case SDLK_LEFT:
                    {
                        if (p->players[0]->sget_position()->x )
                            move_object_lst_in_chunk();
                        p->players[0]->sget_position()->x--;
                        break;
                    }
                    case SDLK_RIGHT:
                    {
                        p->players[0]->sget_position()->x++;
                        break;
                    }
                    case SDLK_DOWN:
                    {
                        p->players[0]->sget_position()->y--;
                        break;
                    }
                    case SDLK_UP:
                    {
                        p->players[0]->sget_position()->y++;
                        break;
                    }
                    */
                    case SDLK_p:
                    {
                        p->scale++;;
                        break;
                    }
                    case SDLK_o:
                    {
                        p->scale--;
                        break;
                    }
                }
            }
        }
    }
}
