#include "doom_nukem.h"

t_inventory     *define_inventory()
{
    t_inventory     *inventory;

    if (!(inventory = (t_inventory *)ft_memalloc(sizeof(t_inventory))))
		return (ret_null_error("inventory allocation failed in define inventory"));
    return (inventory);
}

int        define_pos_slot(t_inventory *inventory, t_win *win)
{
    int     i;
    int     slotPosx;

    i = 0;
    slotPosx = 240;
    while (i <= 4)
    {   
        inventory->item[i] = (t_item *)ft_memalloc(sizeof(t_item));
        i++;
    }
    i = 0;
    while (i <= 4)
    {  
        inventory->item[i]->pos = &(SDL_Rect){(slotPosx), (win->h * 0.8875), (win->w * 0.075), (win->h * 0.09375)};
        inventory->item[i]->nb = 0;
        slotPosx += 80;
        i++;
    }
    return (0);
}

void        print_value_item(t_win *win, t_texhud *texhud, int nb, int slotposx)
{
    SDL_Texture     *text;
    char            *tmp;

    tmp = ft_strjoin( " X ", ft_itoa(nb));
    text = generate_text(win->rend, texhud->police, tmp, (SDL_Color){255, 255, 255, 50});
    SDL_RenderCopy(win->rend, text, NULL, &(SDL_Rect){(slotposx + 60), (win->h * 0.95), (win->w * 0.035), (win->h * 0.04375)});
    free(tmp);
}

void        print_content_slot(t_win *win, t_player *player, t_texhud *texhud)
{
   int i;
   int slotPosx;

   i = 0;
   slotPosx = win->w * 0.24;
   while (i <= 4)
   {    
       if (player->inventory->item[i]->nb != 0)
       {    
           if (i == 0)
           {
                SDL_RenderCopy(win->rend, texhud->tex[7], NULL, &(SDL_Rect){(slotPosx), (win->h * 0.8875), (win->w * 0.075), (win->h * 0.09375)});
                print_value_item(win, texhud, player->inventory->item[i]->nb, slotPosx);
           }
           if (i == 1)
           {
                SDL_RenderCopy(win->rend, texhud->tex[8], NULL, &(SDL_Rect){(slotPosx), (win->h * 0.8875), (win->w * 0.075), (win->h * 0.09375)});
                print_value_item(win, texhud, player->inventory->item[i]->nb, slotPosx);
           }
           if (i == 2)
           {
                SDL_RenderCopy(win->rend, texhud->tex[9], NULL, &(SDL_Rect){(slotPosx), (win->h * 0.8875), (win->w * 0.075), (win->h * 0.09375)});
                print_value_item(win, texhud, player->inventory->item[i]->nb, slotPosx);
           }
		   if (i == 3)
		   {
				SDL_RenderCopy(win->rend, texhud->tex[15], NULL, &(SDL_Rect){(slotPosx), (win->h * 0.8875), (win->w * 0.075), (win->h * 0.09375)});
                print_value_item(win, texhud, player->inventory->item[i]->nb, slotPosx);
		   }
		   if (i == 4)
		   {
			   	SDL_RenderCopy(win->rend, texhud->tex[14], NULL, &(SDL_Rect){(slotPosx + 10), (win->h * 0.8975), (win->w * 0.065), (win->h * 0.08375)});
                print_value_item(win, texhud, player->inventory->item[i]->nb, slotPosx);
		   }
       }
       slotPosx += win->w * 0.08;
       i++;
   }
}

void        main_inventory(t_win *win, t_player *player)
{
    define_pos_slot(player->inventory, win);
    player->inventory->weapon = 1;
    ft_putendl("inventory created");
}