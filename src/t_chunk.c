#include "t_chunk.h"

void    move_object_lst_in_chunk(t_chunk *dest, t_chunk *src, int id)
{
    t_object_lst    *obj_lst;
    t_object_lst    *tmp;

    obj_lst = src->objects;
    if (obj_lst && obj_lst->object->get_id() == id)
    {
        src->objects = obj_lst->next;
        obj_lst->next = dest->objects;
        dest->objects = obj_lst->next;
        return ;
    }
    while (obj_lst)
    {
        if (obj_lst->next->object->get_id() == id)
        {
            tmp = obj_lst->next;
            obj_lst->next = obj_lst->next->next;
            tmp->next = dest->objects;
            dest->objects = tmp;
            break;
        }
        obj_lst = obj_lst->next;
    }
}
