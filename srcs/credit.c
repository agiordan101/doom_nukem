#include "doom_nukem.h"

// static int      credit_menu_init(t_win *win)
// {
//     TTF_Font    *police;
//     SDL_Texture *text;

//     police = TTF_OpenFont("TTF/DooM.ttf", 65);
//     text = generate_text(win->rend, police, "Return", (SDL_Color){255, 0, 0, 50});
//     //menu_frame
//     add_frame_to_window(win, new_frame((t_frect){-0.01, -0.01, 1.01, 1.01}, NULL, FRAME_NONE, NULL));
//     //return menu button
//     add_frame_to_window(win, new_button((t_frect){0.35, 0.8, 0.3, 0.08}, text, BUTTON_CREDIT_RETURN)); 
//     return (1);
// }

SDL_Texture    *define_credit(t_win *win)
{
    SDL_Texture *text;
    TTF_Font    *police;
    char *tmp;

    police = TTF_OpenFont("TTF/DooM.ttf", 65);
    tmp = "Aducimet Agiordan Gmomacho";
    text = generate_text(win->rend, police, tmp, (SDL_Color){255, 255, 255, 50});
    free(tmp);
    return (text);
}

void    print_credit(t_win *win)
{
    SDL_Event   event;
    SDL_bool    loop;
    SDL_Texture *background;
    
    background = load_texture(win->rend, "textures/creditBack.png");
    loop = SDL_TRUE;
    if (win)
    {
        if (Mix_PlayMusic(win->music.credit_music, -1) == -1)
		    ft_putendl_fd("editor loop : Impossible to play map_editor.wav", 2);
        while (loop)
        {   
            SDL_GetWindowSize(win->ptr, &win->w, &win->h);
            clear_rend(win->rend, 197, 50, 250);
            SDL_PumpEvents();
			SDL_PollEvent(&event);
            SDL_RenderCopy(win->rend, background, NULL, &(SDL_Rect){(0), (0), (win->w), (win->h)});
            if (event.type == SDL_QUIT || event.key.keysym.sym == SDLK_ESCAPE)
                loop = SDL_FALSE;
            SDL_RenderPresent(win->rend);
        }
	    Mix_FadeOutMusic(100);
        init_main_menu(win);
    }
}