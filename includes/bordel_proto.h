#ifndef BORDEL_PROTO_H
# define BORDEL_PROTO_H

# include "SDL.h"


/*
** =====================================================================================
** ================================== MAIN ============================================
** =====================================================================================
*/

int			ret_error(const char *error_msg);
void		*ret_null_error(const char *error_msg);
int			ret_perror(const char *error_msg);
void		*ret_null_perror(const char *error_msg);

/*
** =====================================================================================
** ================================== EVENT ============================================
** =====================================================================================
*/

/*
**	---------------------------------- Mouse ----------------------------------
*/

t_mouse		*mouse_refresh();
t_dot		mouse_drag(int x, int y, SDL_bool end);

/*
**	---------------------------------- Event ----------------------------------
*/

int		    keyboard_state(t_map *map, t_player *player);
int		    key_pressed(Uint32 sdl_keycode);

/*
**	---------------------------------- Time ----------------------------------
*/

/*
** ==================== Error Management ==========================
*/


/*
**	====================== Time Managment ======================
*/

void	draw_fps();

/*
** ============================================================================
** ================================== DISPAY ==================================
** ============================================================================
*/


/*
**	---------------------------------- button ----------------------------------
*/

t_button	*new_button(const t_frect ratio, SDL_Texture *texture, Uint32 button_flags);
void		add_button(t_button **buttons, t_button *new_button);

/*
**	---------------------------------- frame ----------------------------------
*/

t_frame		*new_frame(const t_frect ratio, SDL_Texture *texture, Uint32 frame_flags, t_button *buttons);
void		add_frame(t_frame **frames, t_frame *new_frame);
void		add_button_to_frame(t_frame **frame, t_button *button);
void		add_frame_flags(t_frame **frame, Uint32 target_flags, Uint32 added_flags);

/*
**	---------------------------------- Window ----------------------------------
*/

int			create_window(t_win *win, const char *title, SDL_Rect rect, Uint32 flags);
SDL_bool	is_in_screen(t_win *win, t_dot p);
void		add_frame_to_window(t_win *win, t_frame *new_frame);
void		remove_frame_flags(t_frame **frame, Uint32 target_flags, Uint32 removed_flags);

/*
**	---------------------------------- Renderer ----------------------------------
*/

void		clear_rend(SDL_Renderer *rend, Uint8 r, Uint8 g, Uint8 b);

/*
**	---------------------------------- Drawing functon ----------------------------------
*/


void		draw_line(t_win *win, t_dot p1, t_dot p2);
void		draw_rect(t_win *win, SDL_Rect rect);
void		draw_ratio_rect(t_win *win, const SDL_Rect *rect, const t_frect *ratio);
void		draw_circle(t_win *win, t_circle circle);
void	    draw_color_picker(t_win *win, float picker_position, SDL_Rect rect);
void		draw(t_win *win, t_map *map, t_player *player);

/*
** ==========================================================================
** ================================== DATA ==================================
** ==========================================================================
*/

/*
**	---------------------------------- png ----------------------------------
*/

int		    parser_png(char *png_file);

/*
**	---------------------------------- linedef ----------------------------------
*/

void		add_linedef(t_linedef **lines, t_linedef *new_linedef);
t_linedef	*new_linedef(t_line line, SDL_Texture *texture, Uint32 flags);
t_linedef	*new_void_linedef(void);
int			get_nb_linedef(t_linedef *lines);


/*
**	---------------------------------- sector ----------------------------------
*/

t_sector	*new_sector(void);
t_sector	*new_void_sector(void);
void		add_sector(t_sector **sectors, t_sector *new_sectors);
int			get_nb_sectors(t_sector *sector);

/*
**	---------------------------------- player ----------------------------------
*/

int		move(t_map *map, t_player *player);

/*
**	---------------------------------- map ----------------------------------
*/

void		selected_linedef(t_map_editor *map, t_linedef *lines, Uint32 flags);
void		selected_sector_linedef(t_map_editor *map, t_sector *sectors, Uint32 flags);
void		selected_all_linedef(t_map_editor *map, Uint32 flags);

void		delete_linedef(t_linedef **lines, Uint32 delete_flags);
void		delete_all_linedef(t_map_editor *map, Uint32 delete_flags);

SDL_bool 	is_next_to_linedef(t_map_editor *map, t_dot *dot, int radius);
void		map_zoom(t_map_editor *map, double zoom);
void		map_add_line(t_map *map, int n_sector, t_linedef *line);
t_linedef	*new_linedef(t_line line, SDL_Texture *texture, Uint32 flags);

/*
** =============================================================================
** ================================== PARSING ==================================
** =============================================================================
*/

int 		ft_parse_error(char **tab);
void 		ft_data_storing(int fd, int fd1);
void		ft_find_coord_p1(t_sector *sector, char *tab);
void		ft_find_coord_p2(t_sector *sector, char *tab);

/*
** =================================================================================
** ================================== PHYSICS ======================================
** =================================================================================
*/

SDL_bool	is_line_horizontal(int y1, int y2, int pitch);
SDL_bool	is_line_vertical(int x1, int x2, int pitch);
SDL_bool	is_in_rect(SDL_Rect rect, t_dot p);
SDL_bool	intersect_line_rect(t_line line, SDL_Rect rect);
SDL_bool 	is_next_point(t_dot dot, t_dot other, int distance);

/*
** =================================================================================
** ================================== EDITOR LOOP ==================================
** =================================================================================
*/

int			editor_loop(t_win *win);
void		resolve_ui_left_release(t_win *win, t_map_editor *map);
int			editor_event(t_win *win, t_map_editor *map, SDL_bool *loop);

/*
** ===============================================================================
** ================================== GAME LOOP ==================================
** ===============================================================================
*/

int			game_loop(t_win *win, t_map *map);
int			move(t_map *map, t_player *player);

/*
** ========================== Math functions ======================
*/

double		fdist(t_fdot p1, t_fdot p2);
double		dist(t_dot p1, t_dot p2);
double		mag(t_vector vector);
int			sign(double nbr);

#endif
