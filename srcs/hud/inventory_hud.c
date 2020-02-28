#include "doom_nukem.h"

void    hud_slot(t_win *win, t_texhud *texhud, t_player *player)
{
    int i;
    float slotPosx;

    i = 0;
    slotPosx = win->w * 0.24;
    while (i++ < 5)
    {
       SDL_RenderCopy(win->rend, texhud->tex[5], NULL, &(SDL_Rect){(slotPosx), (win->h * 0.8875), (win->w * 0.075), (win->h * 0.09375)});
       slotPosx += (win->w * 0.08);
    }
    SDL_RenderCopy(win->rend, texhud->tex[6], NULL, &(SDL_Rect){((win->w * 0.24 + (win->w * 0.08 * player->inventory->selected_slot))), (win->h * 0.8875), (win->w * 0.075), (win->h * 0.09375)});
}

void    inventory_hud(t_win *win, t_texhud *texhud, t_player *player)
{
    hud_slot(win, texhud, player);
}