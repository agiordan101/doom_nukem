#ifndef BORDEL_PROTO_H
# define BORDEL_PROTO_H

# include "SDL.h"

/*
** =====================================================================================
** ================================== MAIN ============================================
** =====================================================================================
*/

int				init_music_timer(t_map *map, t_doom_music *music);
int				init_textures(t_win *win, t_textures *textures);
int				init_win_player(t_win *win, t_player *player);
int				init_threads(t_win *win, t_map *map, t_player *player);

/*
**	---------------------------------- init_menu ----------------------------------
*/

int		        init_editor_menu(t_win *win, t_map *map);
int				init_main_menu(t_win *win);

/*
** =====================================================================================
** ================================== EVENT ============================================
** =====================================================================================
*/

t_mouse			*mouse_refresh();
t_fdot_3d		events_move(t_map *map, t_player *player, const Uint8 *state);
void			events_rotate(t_win *win, t_map *map, t_player *player, const Uint8 *state);
void			events_actions(t_win *win, t_map *map, t_player *player, const Uint8 *state);
void			events_others(t_win *win, t_player *player, const Uint8 *state);

int				key_pressed(Uint32 sdl_keycode);
t_dot			mouse_drag(int x, int y, SDL_bool end);

/*
**	---------------------------------- Time ----------------------------------
*/

/*
** ==================== Error Management ==========================
*/

int		ret_num_error(const char *error_msg, int i);
int		ret_error(const char *error_msg);
int		ret_perror(const char *error_msg);
void		*ret_null_error(const char *error_msg);
void		*ret_null_perror(const char *error_msg);

/*
**	====================== Time Managment ======================
*/

void		draw_fps();

/*
** ============================================================================
** ================================== DISPAY ==================================
** ============================================================================
*/


void		update_selected_ui(t_win *win);
void		update_ui_rect(t_win *win);

/*
**	---------------------------------- texture ----------------------------------
*/

SDL_Texture	*load_texture(SDL_Renderer *rend, const char *file);

/*
**	---------------------------------- text ----------------------------------
*/

int			display_text(t_win *win, t_dot pos, int max_width, char *text);
SDL_Texture	*generate_text(SDL_Renderer *rend, TTF_Font *font, const char *text, SDL_Color fg);
SDL_Texture	*create_bg_text_input(t_win *win, SDL_Rect rect, SDL_Color l_color, SDL_Color r_color);
SDL_Texture	*blit_text(SDL_Renderer *rend, SDL_Texture *bg_texture, SDL_Texture *text, SDL_Rect *text_rect);
t_dot		get_text_size(t_win *win, char *text);

/*
**	---------------------------------- Window ----------------------------------
*/

int			create_window(t_win *win, const char *title, SDL_Rect rect, Uint32 flags);
void		add_frame_to_window(t_win *win, t_frame *new_frame);
void		remove_frame_flags(t_frame **frame, Uint32 target_flags, Uint32 removed_flags);
SDL_bool	is_in_screen(t_win *win, t_dot p);

/*
**	---------------------------------- Renderer ----------------------------------
*/

void		clear_rend(SDL_Renderer *rend, Uint8 r, Uint8 g, Uint8 b);

/*
**	---------------------------------- Drawing functon ----------------------------------
*/

void		fill_portals(t_win *win, t_player *player);
void		draw_line(t_win *win, t_dot p1, t_dot p2);
void		draw_t_line(t_win *win, t_line line);
void		draw_column(t_win *win, int x, int ylow, int yup);
void		draw_rect(t_win *win, SDL_Rect rect);
void		fill_rect(t_win *win, SDL_Rect rect);
void		draw_ratio_rect(t_win *win, const SDL_Rect *rect, const t_frect *ratio);
void		draw_circle(t_win *win, t_circle circle);
void		draw_color_picker(t_win *win, float picker_position, SDL_Rect rect);

/*
**	---------------------------------- texture ----------------------------------
*/

void		hud(t_win *win, t_player *player, t_texhud *texhud);
void    	inventory_hud(t_win *win, t_texhud *texhud, t_player *player);
void		print_weapon(t_win *win, t_player *player, t_texhud *texhud);
void            main_animation(t_map *map, t_win *win, t_texhud *texhud);
void 		print_shot(t_win *win, t_player *player);
void 		define_line_shot(t_win *win, t_player *player);
void 	        print_shot(t_win *win, t_player *player);
void		add_bullet(t_player *player);
void	        del_bullet(t_player *player);
SDL_Texture	*load_texture(SDL_Renderer *rend, const char *file);

/*
**	---------------------------------- inventory ----------------------------------
*/

void   	        main_inventory(t_win *win, t_player *player);
void            add_items(t_inventory *inventory, int id);
void            print_items(t_win *win, t_inventory *inventory);
void            print_content_slot(t_win *win, t_player *player, t_texhud *texhud);
void            use_item(t_map *map, t_player *player, t_music *music, int slotSelected);
void            reload_ammo(t_player *player);
t_inventory     *define_inventory();
void			drop_box(t_map *map, t_player *player);

/*
** ==========================================================================
** ================================== DATA ==================================
** ==========================================================================
*/

/*
**	---------------------------------- Poly ----------------------------------
*/

void    add_poly(t_poly **poly);
void    add_existing_poly(t_poly **polys, t_poly *poly);
void	delete_poly(t_poly **polys, t_poly *poly);
void	print_polys(t_poly **polys);
    
/*
**	---------------------------------- png ----------------------------------
*/

int             parser_png(char *png_file);

/*
**	---------------------------------- linedef ----------------------------------
*/

int			get_nb_linedef(t_linedef *lines, Uint32 flags);
void		add_linedef(t_linedef **lines, t_linedef *new_linedef);
void		add_linedef_flags(t_linedef **lines, Uint32 flags);
void	    remove_sector(t_sector **sector, t_sector *del_sector);
void		free_linedef(t_linedef *linedef);
void		free_linedefs(t_linedef **lines);
t_linedef	*new_void_linedef(void);
t_linedef	*new_linedef(t_line line, SDL_Surface *texture, Uint32 flags);
t_linedef	*init_equation(t_linedef *line);

/*
**	---------------------------------- sector ----------------------------------
*/

//t_sector	*create_sector(void);
int	        get_nb_sectors(t_sector *sector);
void		add_sector(t_sector **sectors);
void	        reverse_sectors(t_sector **sectors);
void		free_sector(t_sector *sector);
void		free_sectors(t_sector **sectors);

/*
**	---------------------------------- player ----------------------------------
*/

int         dead_menu(t_win *win, t_player *player);
void    	apply_damage(t_map *map, t_player *player, int damage);
void    	apply_heal(t_player *player, int heal);
void    	apply_armor(t_player *player, int armor);
/*
**	---------------------------------- mob ----------------------------------
*/

void		fill_mob_data(t_mob **mob, char **tab, int i);   
void    	set_mobs_dots(t_mob *mob);
void		mobs_attack_move(t_map *map, t_player *player, t_mob *mobs);
void		hit_mobs(t_mob *mobs, int damage);
void    	add_mob(t_mob **mob);
void   		add_existing_mob(t_mob **mob, t_mob *new_mob);
/*
**	---------------------------------- map ----------------------------------
*/

void		selected_linedef(t_map_editor *map, t_linedef *lines, Uint32 flags);
void		selected_sector_linedef(t_map_editor *map, t_sector *sectors, Uint32 flags);

void		delete_linedef(t_linedef **lines, Uint32 delete_flags);
void		delete_sector_linedef(t_sector *sectors, Uint32 delete_flags);

void	        fill_abscissa_ordinate(t_map_editor *map, t_dot mouse, int gap);
void		map_zoom(t_map_editor *map, float zoom);
void		map_add_line(t_map *map, int n_sector, t_linedef *line);
SDL_bool	is_line_horizontally(t_dot lp1, t_dot lp2, float angle);
SDL_bool	is_line_vertically(t_dot lp1, t_dot lp2, float angle);
SDL_bool 	is_next_to_linedef(t_map_editor *map, t_dot *dot, int radius);

/*
** =============================================================================
** ================================== PARSING ==================================
** =============================================================================
*/

/*
**	---------------------------------- map ----------------------------------
*/


int 		ft_parse_error(char **tab);
void		ft_find_coord_p1(t_linedef *line, char *tab);
void		ft_find_coord_p2(t_linedef *line, char *tab);
void	    ft_find_type(char *tab, t_linedef *line);
void		ft_find_id(char *id, t_linedef *line);
t_poly	    *ft_data_storing(int fd, int fd1, t_map *map, t_win *win);
char 		**fillntesttab(int fd, int fd1);
void		fill_poly(t_poly *poly, t_map *map);
void		fill_poly_object(t_poly *poly, t_object *object);
void		fill_poly_mob(t_poly *poly, t_mob *mob);
void 		fill_poly_object_norm(char *tmp, t_poly	*poly_object);
char		*object_data_fill(char **tab, t_object **object, int i);
void		fill_mob_data_norm(t_mob **mob, char *tab);

void		player_data(char **tab, t_player *player, int i);

int			object_data(char **tab, t_object **object, int i);
t_texhud   	*define_texhud(t_win *win);
// void		save_lights(t_map *map);

/*
**	---------------------------------- music ----------------------------------
*/
t_music         *define_music(void);
/*
** =============================================================================
** ================================== EXPORT ===================================
** =============================================================================
*/

void		check_map(t_win *win, t_map_editor *map);
void		write_line(int fd, int nb_tab, const char *str);
void		write_sector(t_sector *sector, int fd);
void		write_player(t_player *player, int fd);
int		export_sector(t_player *player, t_sector *sector, const char* filename);
int		export_map(t_map_editor *map, const char *filename);

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
** ================================== MENU LOOPS ==================================
** =================================================================================
*/

/*
** ================================== main_menu ===================================
*/

int				main_menu(t_win *win, t_map *map);
void            print_credit(t_win *win);
//static int	main_menu_event(t_win *win, int *loop);

/*
** =================================================================================
** ================================== EDITOR LOOP ==================================
** =================================================================================
*/

int	        editor_loop(t_win *win, t_map *map);
int 		ed_event(t_win *win, t_map *map);
int			resolve_ui_left_press(t_win *win, t_map_editor *map);
int			load_ui(int fd, t_win *win);
int			add_sector_button(t_win *win, t_frame *f, int nb_sectors);
void		ed_display(t_win *win, const t_map *map);
void		resolve_ui_left_release(t_win *win, t_map_editor *map);
void		check_file(t_map_editor *map);


void		ed_display_wall(t_win *win, const t_map *map, t_poly *poly);
void		ed_display_inclined(t_win *win, const t_map *map, t_poly *poly);
void		ed_display_flat(t_win *win, const t_map *map, t_poly *poly);
void		ed_display_selected_poly(t_win *win, const t_map *map);
void		ed_display_selected_mob(t_win *win, const t_map *map);
void		ed_display_selected_obj(t_win *win, const t_map *map);
void		ed_display_player(t_win *win, const t_map *map);
void		ed_display_mobs(t_win *win, const t_map *map);
void		ed_display_object(t_win *win, const t_map *map, t_object *obj);
void		ed_display_objects(t_win *win, const t_map *map);


void		ed_place_player(t_win *win, t_map *map);

t_line		ed_get_display_line(const t_map *map, t_dot p1, t_dot p2);
t_dot		ed_get_display_point(const t_map *map, t_dot p);
int			ed_get_map_x(const t_map *map, int n);
int			ed_get_map_y(const t_map *map, int n);
t_dot		ed_get_map_point(const t_map *map, t_dot p);

int			ed_place_wall(t_win *win, t_map *map);
int			ed_place_flat(t_win *win, t_map *map);
int			ed_place_inclined(t_win *win, t_map *map);

int			ed_get_line_len(t_line *line);

int			ed_get_z_min(const t_poly *polys);
int			ed_get_z_max(const t_poly *polys);

void		ed_delete_map(void *map_ptr);
void		ed_delete_mob(t_mob **mobs, t_mob *mob);

SDL_Color	ed_get_wall_display_color(const t_map *map, t_poly *poly);
SDL_Color	ed_get_flat_display_color(const t_map *map, t_poly *poly);
SDL_Color	ed_get_mob_display_color(const t_map *map, t_mob *m);
SDL_Color	ed_get_obj_display_color(const t_map *map, t_object *obj);

SDL_bool	ed_is_flat(t_poly *poly);
SDL_bool	ed_is_inclined(t_poly *poly);
SDL_bool	ed_is_wall(t_poly *poly);
t_poly		*ed_get_selected_poly(t_win *win, t_map *map);
SDL_bool	ed_is_poly_printable(const t_map *map, t_poly *poly);

t_dot		ed_is_next_to_poly(const t_map *map, t_dot point, int radius);


void		ed_export(void *ed_export);
int 		ed_export_ready(int fd, t_map *map);
int         ed_export_sounds(int fd);
void		ed_write_player(int fd, const t_player *player);
void		ed_write_poly(int fd, const t_poly *poly, const t_player *player);
void		ed_write_mob(int fd, const t_mob *m);
void		ed_write_item(int fd, const t_object *obj);
/*
** ===============================================================================
** ================================== GAME LOOP ==================================
** ===============================================================================
*/

int			game_loop(t_win *win, t_map *map);

/*
** ============================= Objects ======================
*/

void		add_existing_object(t_object **objects, t_object *new_object);
void		objects_actions(t_map *map, t_player *player, t_object *object);
void		objects_movements(t_map *map, t_player *player, t_object *object);
int			interact_door(t_object	*door);
int			set_door_object(t_object *object, t_fdot_3d pos, float width_2, float height_2);
int			set_box_object(t_object *object, t_fdot_3d pos, float width_2, float height_2);

/*
** ============================= Polys ======================
*/

int					lstlen(t_poly *poly);
void				copy_poly_lst(t_poly *dst, t_poly *src);
// void				copy_poly_lst(t_poly *dst, t_poly *src, t_object *dst_obj, t_object *src_obj);
int					create_poly_save(t_map *map);
void				poly_del(t_poly *poly);

/*
** ================================== Physics ===================================
*/

void				raycasting_3d(t_win *win, t_map *map);
int					is_in_poly(t_poly *poly, t_fdot *coord, t_fdot_3d dot);
int					sence(t_cartesienne ray, t_fdot_3d collision);
void				draw_all_square(t_win *win);
void				draw_projection(t_win *win);
void				surround_walls(t_win *win, t_map *map);
void				poly_reduction(t_win *win, t_poly *poly);
t_poly				*inside_poly(t_poly *last_poly, t_poly *poly, int x, int y);
// int			physics(t_win *win, t_map *map, t_player *player);
// int			actions(t_win *win, t_map *map, t_linedef *portal, float h);

int					process_light(t_map *map, t_poly *poly, t_fdot_3d collision, int color);
int					is_in_shadow(t_map *map, t_poly *poly_light, t_fdot_3d light, t_poly *poly_collision, t_fdot_3d pos, t_fdot_3d vector);

int					init_rays(t_win *win, t_player *player);
void				translate_all(t_map *map, t_fdot_3d translation);
void				translate_all_poly(t_poly *poly, t_fdot_3d translation);
void				translate_all_objects(t_object *object, t_fdot_3d translation);
void				translate_all_rotz_only(t_map *map, t_poly *poly, t_fdot_3d translation);
void				translate_all_poly_rotz_only(t_poly *poly, t_fdot_3d translation);
void				translate_all_objects_rotz_only(t_object *object, t_fdot_3d translation);
t_fdot_3d			rotate_dot(t_fdot_3d dot, t_matrix matrix);
// void				rotate_all_dots(t_poly *sector, t_matrix matrix);
void				rotate_all_rotz_only(t_map *map, t_poly *poly, t_matrix matrix);
void				copy_rotate_rotz_only(t_map *map, t_poly *poly, t_matrix matrix);
void				rotate_box(t_player *player, t_object *object);
void				translate_box(t_object *object);

void 				print_poly(t_poly *poly, int arg);

t_matrix			create_matrix(t_fdot_3d axe, float angle);
t_matrix			create_rx_matrix(float angle);
t_matrix			create_ry_matrix(float angle);
t_matrix			create_rz_matrix(float angle);
void				init_matrix_rx(t_player *player);
void				init_matrix_rx_inv(t_player *player);
void				init_matrix_ry(t_player *player);
void				init_matrix_ry_inv(t_player *player);
void				init_matrix_rz(t_player *player);
void				init_matrix_rz_inv(t_player *player);
void				init_polygone(t_poly *poly);

t_poly				*collisions(t_player *player, t_poly *poly);
int					is_poly_collision(t_player *player, t_poly *poly);
void				slide(t_map *map, t_poly *polys, t_poly *polys_save, t_fdot_3d poly_collide_v);

t_poly				*collisions_sphere(t_map *map, t_player *player, t_poly *poly, int ban_interest);
int					collision_poly(t_map *map, t_player *player, t_poly *poly);
int					collision_segment(t_fdot_3d dots[4], float width_2);
t_fdot_3d			segment_slide(t_fdot_3d dots[N_DOTS_POLY], t_plan plan, int segment_code);
int					collision_dots(t_fdot_3d dots[N_DOTS_POLY], float ray);
int					is_collision_box(t_object *object, t_cartesienne *ray);

/*
** ================================== Time ===================================
*/

int    				test_timer(t_timer *timer);
int					test_timer_refresh(t_timer *timer);
void				start_cooldown(t_timer *timer, Uint32 time);
// void				init_cd(t_map *map);
void				reload_cd(t_map *map);

/*
** =========================== Math functions ===================================
*/

float				scalar_product(t_fdot_3d v1, t_fdot_3d v2);
t_fdot_3d			vectoriel_product(t_fdot_3d v1, t_fdot_3d v2);
float  				modulo(float nbr, float mod);
float				fdist(t_fdot p1, t_fdot p2);
float				fdist_3d(t_fdot_3d p1, t_fdot_3d p2);
float				fdist_3d_squared(t_fdot_3d p1, t_fdot_3d p2);
t_fdot_3d			fdot_3d_add(t_fdot_3d d1, t_fdot_3d d2);
t_fdot_3d			fdot_3d_sub(t_fdot_3d d1, t_fdot_3d d2);
float				mag(t_fdot_3d v);
int					sign(float nbr);
t_fdot_3d			normalize(t_fdot_3d vector);
int					is_null(float nbr, float precision);
t_fdot_3d			mid_segment(t_fdot_3d d1, t_fdot_3d d2);


t_dot				intersection_segment_edge(t_win *win, t_dot d1, t_dot d2, int edge);
void				draw_affine(t_win *win, t_affine function);
void				draw_ray(t_win *win, t_player *player, t_affine ray);
float				fprop(float value, t_fdot inter1, t_fdot inter2);
float				prop(float value, t_dot inter1, t_dot inter2);
int					is_intersection_cercle_poly(t_poly *poly, int radius);
int					intersection_plan_my_ray(t_fdot_3d *collision, t_plan plan, t_cartesienne *ray);
int					intersection_plan_ray(t_fdot_3d *collision, t_plan plan, t_cartesienne ray);
int					resolve_polynome(t_fdot_3d polynome, float *x1, float *x2);
void				proj_ortho_plan(t_fdot_3d dot, t_plan plan, t_fdot_3d *proj_ortho);
t_fdot_3d			proj_ortho_origin_line(t_fdot_3d l1, t_fdot_3d l2, t_fdot_3d *proj);
int					is_in_segment(t_fdot_3d is, t_fdot_3d d1, t_fdot_3d d2);

#endif
