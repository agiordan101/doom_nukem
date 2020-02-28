#include "doom_nukem.h"

void	add_existing_object(t_object **objects, t_object *new_object)
{
	if (new_object)
	{
		new_object->next = *objects;
		*objects = new_object;
	}
}