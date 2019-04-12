#ifndef T_OBJECT_LST_H
# define T_OBJECT_LST_H

typedef struct  s_object_lst t_object_lst;

# include "physical_object.h"

struct  s_object_lst
{
    Physical_object     *object;
    struct s_object_lst *next;
};

t_object_lst    *create_object_lst(Physical_object *object);
void            delete_all_object_lst(t_object_lst *origin);
t_object_lst    *add_to_object_lst(t_object_lst **porigin, Physical_object *object);

#endif
