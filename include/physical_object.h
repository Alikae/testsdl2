#ifndef PHYSICAL_OBJECT_H
# define PHYSICAL_OBJECT_H

# include "t_pos.h"
# include "sprite.h"

class   Physical_object
{
protected:
    static int  id_gen;
    SDL_Texture *sprite;
    t_pos       position;
    t_pos       velocity;
    int         id;

public:
    static int  generate_id(void);
                Physical_object(void);
    void        add_velocity(int x, int y);
    int         get_id(void);
    SDL_Texture *get_sprite(void);
    void        init(SDL_Texture *spr);
    void        init(SDL_Texture *spr, int x, int y);
    t_pos       *sget_position(void);
    t_pos       *sget_velocity(void);
};

#endif
