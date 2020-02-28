// #include "doom_nukem.h"


// int		resolve_ui_left_press(t_win *win, t_map_editor *map)
// {
// 	t_text_entry	*data;
// 	t_scalebox		*scale_data;

// 	if (win->selected_button)
// 	{
// 		if (!(map->flags & MAP_TEXT_EDITING))
// 		{
// 			if (win->selected_button->flags & BUTTON_TEXT_ENTRY)
// 			{
// 				if (win->mouse->x > win->selected_button->rect.x + win->selected_button->rect.w / 3)
// 				{
// 					printf("start text_input\n");
// 					data = win->selected_button->data;
// 					// if (win->selected_button->flags & BUTTON_SECTOR_INPUT)
// 					// {
// 					// 	if (data->flags & TEXT_ENTRY_SECTOR_NAME)
// 					// 		data->variable = map->selected_sector->name;
// 					// 	else if (data->flags & TEXT_ENTRY_SECTOR_FLOOR)
// 					// 		data->variable = &map->selected_sector->floor_height;
// 					// 	else if (data->flags & TEXT_ENTRY_SECTOR_CEIL)
// 					// 		data->variable = &map->selected_sector->ceil_height;
// 					// }
// 					if (data->variable)
// 					{
// 						if (data->flags & TEXT_ENTRY_ALPHANUM)
// 						{
// 							if (!update_text_entry_texture(win, win->selected_button, (char*)data->variable))
// 								return(ret_error("update_text_entry_texture failed in resolve_ui_left_press"));
// 						}
// 						// else if (data->flags & TEXT_ENTRY_DIGITAL)
// 						// 	update_text_entry_texture(win, win->selected_button, ft_itoa(*(int*)data->variable));
// 					}
// 					map->flags = MAP_TEXT_EDITING;
// 					SDL_StartTextInput();
// 					SDL_SetTextInputRect(&(SDL_Rect){win->selected_button->rect.x + win->selected_button->rect.w / 3,
// 														win->selected_button->rect.y,
// 														win->selected_button->rect.w - win->selected_button->rect.w / 3,
// 														win->selected_button->rect.h});
// 				}
// 			}
// 			else if (win->selected_button->flags & BUTTON_SCALE_BOX)
// 			{
// 				scale_data = (t_scalebox*)win->selected_button->data;
// 				// if (win->mouse.x )
// 			}
// 		}
// 	}
	
// 	return (1);
// }