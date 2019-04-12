#include "physical_object.h"

int         Physical_object::id_gen;

int         Physical_object::generate_id(void)
{
    return (++id_gen);
}

Physical_object::Physical_object(void)
{
    id = Physical_object::generate_id();
}

void        Physical_object::init(SDL_Texture *spr)
{
    sprite = spr;
}

void        Physical_object::init(SDL_Texture *spr, int x, int y)
{
    position.x = x;
    position.y = y;
    sprite = spr;
}

int         Physical_object::get_id(void)
{
    return (id);
}

void        Physical_object::add_velocity(int x, int y)
{
    //SET MAX VELOCITY!
    velocity.x += x;
    velocity.y += y;
}

SDL_Texture *Physical_object::get_sprite(void)
{
    return (sprite);
}

t_pos       *Physical_object::sget_position(void)
{
    return (&position);
}

t_pos       *Physical_object::sget_velocity(void)
{
    return (&velocity);
}
