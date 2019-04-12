#include "t_object_lst.h"

t_object_lst    *create_object_lst(Physical_object *object)
{
    t_object_lst    *obj_lst;

    if ((obj_lst = (t_object_lst*)malloc(sizeof(t_object_lst))))
    {
        obj_lst->object = object;
        obj_lst->next = 0;
    }
    return (obj_lst);
}

void            delete_all_object_lst(t_object_lst *origin)
{
    t_object_lst    *tmp;

    while (origin)
    {
        tmp = origin;
        origin = origin->next;
        free(tmp);
    }
}

t_object_lst    *add_to_object_lst(t_object_lst **porigin, Physical_object *object)
{
    t_object_lst    *tmp;

    if (!*porigin)
        return (*porigin = create_object_lst(object));
    tmp = *porigin;
    while(tmp->next)
        tmp = tmp->next;
    return ((tmp = create_object_lst(object)));
}
