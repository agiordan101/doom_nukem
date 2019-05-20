#include "doom_nukem.h"

void	draw_color_picker(t_win *win, float picker_position, SDL_Rect rect)
{
    SDL_Color	color;
    double		step;
    double		x;
    int			y1;
    int			y2;
    int			last_x;

    step = rect.w / 1530.0;
    x = rect.x + 1;
    y1 = rect.y + 1;
    y2 = rect.y + rect.h - 1;
    last_x = 0;
    color = (SDL_Color){255, 0, 0, 255};
    while (color.g < 255)
    {
        SDL_SetRenderDrawColor(win->rend, color.r, color.g, color.b, color.a);
        if ((int)x != last_x)
        {
            draw_line(win, (t_dot){x, y1}, (t_dot){x, y2});
            last_x = x;
        }
        color.g++;
        x += step;
    }
    draw_line(win, (t_dot){x, y1}, (t_dot){x, y2});
    while (color.r > 0)
    {
        SDL_SetRenderDrawColor(win->rend, color.r, color.g, color.b, color.a);
        if ((int)x != last_x)
        {
            draw_line(win, (t_dot){x, y1}, (t_dot){x, y2});
            last_x = x;
        }
        color.r--;
        x += step;
    }
    draw_line(win, (t_dot){x, y1}, (t_dot){x, y2});
    while (color.b < 255)
    {
        SDL_SetRenderDrawColor(win->rend, color.r, color.g, color.b, color.a);
        if ((int)x != last_x)
        {
            draw_line(win, (t_dot){x, y1}, (t_dot){x, y2});
            last_x = x;
        }
        color.b++;
        x += step;
    }
    draw_line(win, (t_dot){x, y1}, (t_dot){x, y2});
    while (color.g > 0)
    {
        SDL_SetRenderDrawColor(win->rend, color.r, color.g, color.b, color.a);
        if ((int)x != last_x)
        {
            draw_line(win, (t_dot){x, y1}, (t_dot){x, y2});
            last_x = x;
        }
        color.g--;
        x += step;
    }
    draw_line(win, (t_dot){x, y1}, (t_dot){x, y2});
    while (color.r < 255)
    {
        SDL_SetRenderDrawColor(win->rend, color.r, color.g, color.b, color.a);
        if ((int)x != last_x)
        {
            draw_line(win, (t_dot){x, y1}, (t_dot){x, y2});
            last_x = x;
        }
        color.r++;
        x += step;
    }
    draw_line(win, (t_dot){x, y1}, (t_dot){x, y2});
    while (color.b > 6)
    {
        SDL_SetRenderDrawColor(win->rend, color.r, color.g, color.b, color.a);
        if ((int)x != last_x)
        {
            draw_line(win, (t_dot){x, y1}, (t_dot){x, y2});
            last_x = x;
        }
        color.b--;
        x += step;
    }
    SDL_SetRenderDrawColor(win->rend, 255, 255, 255, 255);
    draw_line(win, (t_dot){rect.x + rect.w * picker_position + 1, y1 - 5}, (t_dot){rect.x + rect.w * picker_position + 1, y2 + 5});
}