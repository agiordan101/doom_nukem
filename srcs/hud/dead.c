#include "doom_nukem.h"
#include "ui.h"
#include "ui_error.h"
#include "libft.h"

static void		dead_change_loop(void *argument)
{
	t_arg_menu	*arg_menu;

	arg_menu = (t_arg_menu*)argument;
	*(arg_menu->loop) = arg_menu->value;
}

static void		set_menu_button_function(t_winui *winui, int *next_loop)
{
	ui_set_simple_button_function(winui,
									"b_menu",
									&dead_change_loop,
									&(t_arg_menu){next_loop, 1});
	ui_set_simple_button_function(winui,
									"b_exit",
									&dead_change_loop,
									&(t_arg_menu){next_loop, 2});
}

int		init_dead_menu(t_win *win)
{
	if (!(win->winui->ui.button_font = ui_load_font("TTF/DooM.ttf", 100)))
    {
        printf("en haut\n");
		return (0);
    }
	if (!ui_load("interfaces/menu_dead", win->winui))
    {
        printf("en bas\n");
        return (0);
    }
	SDL_SetRelativeMouseMode(SDL_FALSE);
	return (1);
}

static void	main_menu_quit(t_win *win, Uint32 ms)
{
	ui_free_ui(&win->winui->ui);
	SDL_Delay(ms);
}

static void		dead_menu_ui(t_win *win)
{
	ui_set_draw_color(win->rend, &(SDL_Color){71, 27, 27, 255});
	ui_clear_win(win->winui);
	ui_display_frames(win->winui, win->winui->ui.frames);
	ui_draw_rend(win->winui);
	ui_poll_event(&win->winui->event);
	ui_update_ui(win->winui);
}

int dead_menu(t_win *win, t_player *player)
{
    int next_loop;
    int flag;

    flag = 0;
    next_loop = 0;
    if (init_dead_menu(win) == 0)
	    return (ret_error("dead_menu"));
    if (player->currentHp <= 0)
    {   
        while (!next_loop)
        {   
            next_loop = 0;
            if (!flag)
            {   
                set_menu_button_function(win->winui, &next_loop);
                flag = 1;
            }
            dead_menu_ui(win);
            if (next_loop != 0)
            {   
                main_menu_quit(win, 250);
                return(next_loop);
            }
        }
    }
    return (0);
}