// #include "doom_nukem.h"

// static void	set_selected_portal_id(t_map_editor *map, int id)
// {
// 	t_linedef		*l;

// 	l = NULL;
// 	if (map->selected_sector)
// 		l = map->selected_sector->lines;
// 	while (l)
// 	{
// 		if (l->flags & LINEDEF_SELECTED && l->gflags & PORTAL)
// 			l->id = id;
// 		l = l->next;
// 	}
// }
 
// int		fill_variable(t_win *win, t_map_editor *map, t_button *button, const void *result)
// {
// 	t_text_entry	*data;
// 	int				*int_variable;
// 	char			*str_variable;

// 	data = button->data;
// 	if (win)
// 	{
// 		if (data->variable)
// 		{
// 			if (data->flags & TEXT_ENTRY_DIGITAL)
// 			{
// 				int_variable = data->variable;
// 				*int_variable = *((int*)result);
// 			}			
// 			else if (data->flags & TEXT_ENTRY_ALPHANUM)
// 			{
// 				str_variable = (char*)data->variable;
// 				ft_strcpy(str_variable, (char*)result);
// 			}
// 			// data->variable = NULL;
// 		}
// 		else
// 		{
// 			if (button->flags & BUTTON_ID)
// 				set_selected_portal_id(map, *((int*)result));
// 		}
// 		if (data->flags & TEXT_ENTRY_TMP)
// 		{
// 			if (!update_text_entry_texture(win, button, NULL))
// 				return (ret_error("update_text_entry_texture failed in fill_variable"));
// 		}
// 	}
// 	return (1);
// }