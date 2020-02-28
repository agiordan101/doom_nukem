#include "ui.h"
#include "ui_error.h"

void	incre_value(void *value)
{
	int	*int_value;

	int_value = value;
	*int_value += 1;
}

// void	assign_value(void *dst, char *value)
// {
// 	*((int*)dst) = ft_atoi(value);
// }

// void 	assign_char_value(void *dst, char *value)
// {
// 	*((char**)dst) = ft_strdup(value);
// }

// int		libuimain()
// {
// 	t_winui		*win;
// 	int			loop;

// 	if (ui_init(SDL_INIT_VIDEO) < 0)
// 		return (1);

// 	/////////////////////////////////////////////////////////
// 	//////////////////////// WINDOW. ////////////////////////
// 	/////////////////////////////////////////////////////////

// 	if (!(win = ui_new_win("libui",
// 							(t_rect){SDL_WINDOWPOS_CENTERED,
// 							SDL_WINDOWPOS_CENTERED,
// 							900,
// 							900},
// 							SDL_WINDOW_RESIZABLE,
// 							SDL_RENDERER_ACCELERATED)))
// 		return (1);

// 	if (!(win->ui.button_font = ui_load_font("font/Raleway-Regular.ttf", 100)))
// 		return (1);

// 	/////////////////////////////////////////////////////////
// 	///---------------------------------------------------///
// 	/////////////////////////////////////////////////////////

// 	if (ui_load("test_ui/ui.txt", win))
// 	{
// 		loop = 1;
// 		while (loop)
// 		{
// 			ui_set_draw_color(win->rend, &(SDL_Color){50, 50, 50, 255});
// 			ui_clear_win(win);
// 			ui_display_frames(win, win->ui.frames);
// 			// SDL_RenderCopy(win->rend, texture, NULL, NULL);
// 			// ui_draw_text(win->rend, font, &(ui_text){"voilatrucmuch on s'ammuse\ngrosse ambiance putain\nCordialement\n",
// 			// 										20,
// 			// 										&(SDL_Color){200, 200, 255, 255},
// 			// 										(ui_dot){200, 200}, TEXT_ALIGN_LEFT});
// 			ui_set_draw_color(win->rend, &(SDL_Color){255, 0, 0, 255});
// 			// ui_draw_rect(win->rend, &(t_rect){400, 200, 200, 25});
// 			// ui_draw_text_in_rect(win->rend, &(t_text){"11111111\n111111111222222222222awefafaefafs222\n22222222",
// 			// 										20,
// 			// 										win->ui.button_font,
// 			// 										(SDL_Color){200, 200, 200, 255},
// 			// 										(t_dot){200, 200},
// 			// 										TEXT_ALIGN_LEFT | TEXT_ALIGN_V_MIDDLE},
// 			// 										(t_rect){400, 200, 200, 500});
// 			// ui_draw_rect(win->rend, &(t_rect){100, 100, 200, 25});
// 			// ui_draw_text_line(win->rend,  &(t_text_line_kit){"test ui draw text line",
// 			// 	(SDL_Color){255, 255, 255, 255},
// 			// 	(t_dot){100, 100},
// 			// 	200,
// 			// 	25,
// 			// 	win->ui.button_font,
// 			// 	TEXT_ALIGN_LEFT | TEXT_ALIGN_V_TOP});
// 			// ui_draw_text_line_return(win->rend,  &(t_text_line_kit){"test ui draw text line return",
// 			// 	(SDL_Color){255, 255, 255, 255},
// 			// 	(t_dot){300, 200},
// 			// 	150,
// 			// 	25,
// 			// 	win->ui.button_font,
// 			// 	TEXT_ALIGN_CENTER});
// 			ui_draw_rend(win);
// 			ui_wait_event(&win->event);
// 			ui_update_ui(win);
// 			// printf("text_entry_value = %s\n", text_entry_value);
// 			if (win->event.type == SDL_QUIT)
// 				loop = 0;
// 		}
// 	}
// 	ui_free_win(&win);
// 	ui_quit(SDL_INIT_VIDEO);
// 	/////////////////////////////////////////////////////////
// 	///---------------------------------------------------///
// 	/////////////////////////////////////////////////////////
// 	return (0);
// }

    // button
    // {
    //     id : "button2"
    //     type : UI_BUTTON_SIMPLE
    //     resize_type : UI_RESIZE_ALL_LINEAR
    //     ratio : 0.4 0.1 0.15 0.05
    //     data
    //     {
    //         text : "puet"
    //         texture_normal : "textures/ui_normal_button.png"
    //         texture_clicked : "textures/ui_clicked_button.png"
    //         texture_on_mouse : "textures/ui_on_mouse_button.png"
    //         clicked_condition : UI_MOUSE_LEFT
    //     }
    // }

    // button
    // {
    //     id : "button4"
    //     type : UI_BUTTON_TEXT_ENTRY
    //     resize_type : UI_RESIZE_ALL_LINEAR
    //     ratio : 0.7 0.5 0.15 0.05
    //     data
    //     {
    //         name : "puet"
    //         text : ""
    //         max_text_size : 8
    //         min_int : 0
    //         max_int : 9000
    //         name_side_texture : "textures/ui_text_entry_button_normal.png"
    //         normal_box_texture : "textures/ui_text_entry_button_normal.png"
    //         writting_box_texture : "textures/ui_text_entry_button_writting.png"
    //         text_side : UI_TEXT_SIDE_LEFT
    //         text_type : UI_TEXT_TYPE_NONE
    //     }
    // }