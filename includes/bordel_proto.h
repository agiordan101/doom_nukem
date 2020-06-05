/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bordel_proto.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: widrye <widrye@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 17:10:31 by agiordan          #+#    #+#             */
/*   Updated: 2020/06/03 17:56:33 by widrye           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef BORDEL_PROTO_H
# define BORDEL_PROTO_H

# ifdef __linux__
#  include "SDL2/SDL.h"
# else
#  include "SDL.h"
# endif

void		main_free(t_win *win, t_map *map);

int			init_music_timer(t_doom_music *music);
int			init_textures(t_win *win, t_textures *textures);
int			init_win_player(t_win *win, t_player *player);
int			init_threads(t_win *win, t_map *map, t_player *player);

int			init_editor_menu(t_win *win, t_map *map);
int			init_main_menu(t_win *win);
void		condition_loop(t_win *win, t_map *map,
							int *next_loop, int *f_set);

t_mouse		*mouse_refresh();
t_fdot_3d	events_move(t_map *map, t_player *player, const Uint8 *state);
void		events_rotate(t_win *win, t_map *map,
							t_player *player, const Uint8 *state);
void		events_actions(t_win *win, t_map *map,
							t_player *player, const Uint8 *state);
void		events_others(t_win *win, t_player *player, const Uint8 *state);
void		events_game_loop(t_win *win, t_map *map, t_player *player,
								SDL_Event *event);
int			end_game_win(t_win *win, t_map *map, t_player *player, int i);
int			key_pressed(Uint32 sdl_keycode);
t_dot		mouse_drag(int x, int y, SDL_bool end);

int			ret_num_error(const char *error_msg, int i);
int			ret_error(const char *error_msg);
int			ret_perror(const char *error_msg);
void		*ret_null_error(const char *error_msg);
void		*ret_null_perror(const char *error_msg);

void		draw_fps();

void		update_selected_ui(t_win *win);
void		update_ui_rect(t_win *win);

SDL_Texture	*load_texture(SDL_Renderer *rend, const char *file);

int			display_text(t_win *win, t_dot pos, int max_width, char *text);
SDL_Texture	*generate_text(SDL_Renderer *rend, TTF_Font *font,
							const char *text, SDL_Color fg);
SDL_Texture	*create_bg_text_input(t_win *win, SDL_Rect rect,
								SDL_Color l_color, SDL_Color r_color);
SDL_Texture	*blit_text(SDL_Renderer *rend, SDL_Texture *bg_texture,
SDL_Texture	*text, SDL_Rect *text_rect);
t_dot		get_text_size(t_win *win, char *text);

int			create_window(t_win *win, const char *title,
							SDL_Rect rect, Uint32 flags);
void		add_frame_to_window(t_win *win, t_frame *new_frame);
void		remove_frame_flags(t_frame **frame, Uint32 target_flags,
								Uint32 removed_flags);
SDL_bool	is_in_screen(t_win *win, t_dot p);

void		clear_rend(SDL_Renderer *rend, Uint8 r, Uint8 g, Uint8 b);

/*
**	----------------------------- Drawing functon -----------------------------
*/

void		draw(t_win *win, t_map *map, t_player *player);
void		fill_portals(t_win *win, t_player *player);
void		draw_line(t_win *win, t_dot p1, t_dot p2);
void		draw_t_line(t_win *win, t_line line);
void		draw_column(t_win *win, int x, int ylow, int yup);
void		draw_rect(t_win *win, SDL_Rect rect);
void		fill_rect(t_win *win, SDL_Rect rect);
void		draw_ratio_rect(t_win *win, const SDL_Rect *rect,
							const t_frect *ratio);
void		draw_quarter_circle(t_win *win, t_circle circle, float dir_start);
void		draw_circle(t_win *win, t_circle circle);
void		draw_color_picker(t_win *win, float picker_position,
								SDL_Rect rect);

int			win_menu(t_win *win, t_player *player);
void		hud(t_win *win, t_player *player, t_texhud *texhud);
void		print_items_s(t_win *win, SDL_Texture *tex, int slotposx);
void		inventory_hud(t_win *win, t_texhud *texhud, t_player *player);
void		print_weapon(t_win *win, t_player *player, t_texhud *texhud);
void		main_animation(t_map *map, t_win *win, t_texhud *texhud);
void		print_shot(t_win *win, t_player *player);
void		define_line_shot(t_win *win, t_player *player);
void		print_shot(t_win *win, t_player *player);
void		add_bullet(t_player *player);
void		del_bullet(t_player *player);
SDL_Texture	*load_texture(SDL_Renderer *rend, const char *file);
void		dead_menu_ui(t_win *win);
t_line		is_point(int p1x, int p1y, int p2x, int p2y);

void		main_inventory(t_win *win, t_player *player);
void		add_items(t_inventory *inventory, int id);
void		print_items(t_win *win, t_inventory *inventory);
void		print_content_slot(t_win *win, t_player *player, t_texhud *texhud);
void		use_item(t_map *map, t_player *player,
					t_music *music, int slot_selected);
void		reload_ammo(t_player *player);
t_inventory	*define_inventory();
void		drop_box(t_map *map, t_player *player);
void		print_value_item(t_win *win, t_texhud *texhud,
								int nb, int slotposx);

void		add_poly(t_poly **poly);
void		add_existing_poly(t_poly **polys, t_poly *poly);
void		delete_poly(t_poly **polys, t_poly *poly);
void		print_polys(t_poly **polys);
void		init_fpoly(t_poly **poly);

int			parser_png(char *png_file);

int			dead_menu(t_win *win, t_player *player);
void		apply_damage(t_map *map, t_player *player, int damage);
void		apply_heal(t_player *player, int heal);
void		apply_armor(t_player *player, int armor);

int			fill_mob_data(t_mob **mob, char **tab, int i);
void		set_mobs_dots(t_mob *mob);
void		mobs_attack_move(t_map *map, t_player *player, t_mob *mobs);
void		hit_mobs(t_mob *mobs, int damage);
int			add_mob(t_mob **mob);
void		add_existing_mob(t_mob **mob, t_mob *new_mob);

void		fill_abscissa_ordinate(t_map_editor *map, t_dot mouse, int gap);
void		map_zoom(t_map_editor *map, float zoom);
SDL_bool	is_line_horizontally(t_dot lp1, t_dot lp2, float angle);
SDL_bool	is_line_vertically(t_dot lp1, t_dot lp2, float angle);

int			create_tmp_files(int fd, char *dir);
void		create_tmp_bin_files(int fd);
int			ft_parse_error(char **tab);
t_poly		*ft_data_storing(int fd, t_map *map, t_win *win);
char		**fillntesttab(int fd);
int			fill_poly(t_poly *poly, t_map *map);
int			fill_poly_object(t_map *map, t_poly *poly, t_object *object);
int			fill_poly_mob(t_map *map, t_poly *poly, t_mob *mob);
int			fill_poly_object_norm(t_map *map, char *tmp, t_poly	*poly_object);
int			add_poly_object_norm2(t_object *object, char *type_str);
int			ft_data_storing2(t_poly **poly, t_map *map, char **tab, int i);
char		*object_data_fill(char **tab, t_object **object, int i);
void		fill_mob_data_norm(t_mob **mob, char *tab);
int			ft_fill_data(t_map *map, char **tab, t_poly **poly, int i);

int			find_texture(t_map *map, char *tab, t_poly *poly);
t_l_texture	*new_stock_texture(const char *id);
void		add_stock_texture(t_l_texture **textures,
								t_l_texture *t);
int			is_in_stock(t_l_texture *textures,
						t_l_texture *texture);
int			is_id_in_stock(t_l_texture *textures,
						char *id);
void		free_stock_texture(t_l_texture **stock);
SDL_Surface	*get_surface_from_stock(t_l_texture *textures, const char *id);
void		player_data(char **tab, t_player *player, int i);
void		new_sphere(t_sphere *sphere, char **tab, int i);

int			object_data(char **tab, t_object **object, int i);
t_texhud	*define_texhud(t_win *win);

void		clear_leaks(t_map *map);

t_music		*define_music(void);

void		check_map(t_win *win, t_map_editor *map);
void		write_line(int fd, int nb_tab, const char *str);
void		write_player(t_player *player, int fd);
int			export_map(t_map_editor *map, const char *filename);

SDL_bool	is_line_horizontal(int y1, int y2, int pitch);
SDL_bool	is_line_vertical(int x1, int x2, int pitch);
SDL_bool	is_in_rect(SDL_Rect rect, t_dot p);
SDL_bool	intersect_line_rect(t_line line, SDL_Rect rect);
SDL_bool	is_next_point(t_dot dot, t_dot other, int distance);

int			main_menu(t_win *win, t_map *map, char *arg);
void		print_credit(t_win *win);
void		end();
void		main_menu_quit(t_win *win, Uint32 ms);

void		ed_init_map_editor(t_win *win, t_map *map);

int			editor_loop(t_win *win, t_map *map);
int			resolve_ui_left_press(t_win *win, t_map_editor *map);
int			load_ui(int fd, t_win *win);
void		resolve_ui_left_release(t_win *win, t_map_editor *map);
void		check_file(t_map_editor *map);

int			ed_event(t_win *win, t_map *map);
void		ed_action(t_win *win, t_map *map);
void		ed_set_property(t_win *win, t_property *p);
void		ed_clean_property(t_win *win, int i_start);
void		ed_set_buttons_wall(t_win *win, t_poly *selected);
void		ed_set_buttons_flat(t_win *win, t_poly *selected);
void		ed_set_buttons_inclined(t_win *win, t_poly *selected);
void		ed_set_buttons_mob(t_win *win, t_mob *selected);
void		ed_set_buttons_object(t_win *win, t_object *selected);
void		ed_set_buttons_player(t_win *win, t_player *selected);

void		set_int_value(void *argument, char *button_output);
void		set_float_value(void *argument, char *button_output);
void		set_coef_value(void *argument, char *button_output);
void		set_editor_calc(void *argument);
void		set_wall_z1(void *argument, char *button_output);
void		set_wall_z2(void *argument, char *button_output);
void		set_flat_z(void *argument, char *button_output);
void		set_inclined_z1(void *argument, char *button_output);
void		set_inclined_z2(void *argument, char *button_output);
void		set_str_value(void *argument, char *button_output);
void		set_editor_flags(void *argument);
void		ed_set_menu_button_function(t_win *win, t_map *map);

void		ed_display(t_win *win, const t_map *map);
void		ed_display_list_selected(t_win *win, const t_map *map);
void		ed_display_poly(t_win *win, const t_map *map, t_poly *poly);
void		ed_display_polys(t_win *win, const t_map *map);
void		ed_display_polys_flat(t_win *win, const t_map *map);
void		ed_display_polys_inclined(t_win *win, const t_map *map);
void		ed_display_polys_wall(t_win *win, const t_map *map);
void		ed_display_wall(t_win *win, const t_map *map, t_poly *poly);
void		ed_display_inclined(t_win *win, const t_map *map, t_poly *poly);
void		ed_display_flat(t_win *win, const t_map *map, t_poly *poly);
void		ed_display_selected_poly(t_win *win, const t_map *map,
													const t_poly *selected);
void		ed_display_selected_mob(t_win *win, const t_map *map,
													const t_mob *selected);
void		ed_display_selected_obj(t_win *win, const t_map *map,
													const t_object *selected);
void		ed_display_player(t_win *win, const t_map *map);
void		ed_display_mobs(t_win *win, const t_map *map);
void		ed_display_mob(t_win *win, const t_map *map, const t_mob *m);
void		ed_display_object(t_win *win, const t_map *map, t_object *obj);
void		ed_display_objects(t_win *win, const t_map *map);
void		ed_display_placing_door(t_win *win, const t_map *map);
void		ed_place_player(t_win *win, t_map *map);
void		ed_place_door_event(t_win *win, t_map *map);
float		ed_get_line_degrees(t_line	*l);
t_line		ed_get_display_line(const t_map *map, t_dot p1, t_dot p2);
t_dot		ed_get_display_point(const t_map *map, t_dot p);
int			ed_get_map_x(const t_map *map, int n);
int			ed_get_map_y(const t_map *map, int n);
t_dot		ed_get_map_point(const t_map *map, t_dot p);
int			ed_get_object_poly_count(const t_object *obj);
void		ed_place_poly_base(t_win *win, t_map *map);
void		ed_place_item(t_win *win, t_map *map);
int			ed_place_wall(t_win *win, t_map *map);
int			ed_place_flat(t_win *win, t_map *map);
int			ed_place_inclined(t_win *win, t_map *map);
int			ed_get_line_len(t_line *line);
int			ed_get_z_min(const t_poly *polys);
int			ed_get_z_max(const t_poly *polys);
void		ed_delete_map(void *map_ptr);
void		ed_delete_mob(t_mob **mobs, t_mob *mob);
void		ed_delete_obj(t_map *map, t_object **objects, t_object *object);
SDL_Color	ed_get_wall_display_color(const t_map *map, t_poly *poly);
SDL_Color	ed_get_flat_display_color(const t_map *map, t_poly *poly);
SDL_Color	ed_get_mob_display_color(const t_map *map, t_mob *m);
SDL_Color	ed_get_obj_display_color(const t_map *map, t_object *obj);
SDL_bool	ed_is_flat(const t_poly *poly);
SDL_bool	ed_is_inclined(const t_poly *poly);
SDL_bool	ed_is_wall(const t_poly *poly);

void		ed_selection(t_win *win, t_map *map);
void		ed_set_buttons_selected(t_win *win, t_map *map);
t_selected	*ed_new_selected(void *ptr, t_selected_type selected_type);
void		ed_add_selected(t_selected **list_selected, t_selected *selected);
void		ed_free_selected(t_selected **list_selected);
void		ed_get_selected_obj(t_win *win, t_map *map);
void		ed_get_selected_mob(t_win *win, t_map *map);
void		ed_get_selected_poly(t_map *map, int i);
void		ed_get_selected_player(t_win *win, t_map *map);
void		ed_incre_selected(t_selected *list_selected, t_selected **selected);

SDL_bool	ed_is_poly_point(const t_poly *poly);
SDL_bool	ed_is_real_poly(const t_map *map, const t_poly *poly);
SDL_bool	ed_is_poly_printable(const t_map *map, const t_poly *poly);

t_dot		ed_is_next_to_poly(const t_map *map, t_dot point, int radius);

void		ed_export(void *ed_export);
void		ed_package(void *ed_exp);
int			ed_export_textures(int fd, t_map *map);
int			ed_export_sounds(int fd);
int			ed_export_fonts(int fd);
void		ed_write_line(int fd, const char *name, const char *value);
void		ed_write_player(int fd, const t_player *player);
void		ed_write_sphere(int fd, const t_sphere *skybox);
void		ed_write_poly(int fd, const t_poly *poly, const t_player *player);
void		ed_write_mob(int fd, const t_mob *m);
void		ed_write_item(int fd, const t_object *obj, t_fdot_3d playerpos);

int			game_loop(t_win *win, t_map *map);

void		add_existing_object(t_object **objects, t_object *new_object);
void		objects_actions(t_map *map,
							t_player *player, t_object *object);
void		objects_movements(t_map *map, t_player *player, t_object *object);
void		rotate_all_objects(t_player *player, t_object *object);
int			interact_door(t_map *map, t_object *door);
int			set_door_object(t_object *object, t_fdot_3d pos,
							float width_2, float height_2);
int			set_box_object(t_object *object, t_fdot_3d pos,
							float width_2, float height_2);

void		copy_poly_lst(t_poly *dst, t_poly *src);
int			create_poly_save(t_map *map);
void		poly_del(t_poly *poly);
int			check_parallelogram(t_poly *poly);

void		graphics_engine(t_win *win, t_map *map);
int			is_in_poly(t_poly *poly, t_fdot *coord, t_fdot_3d dot);
int			sence(t_cartesienne ray, t_fdot_3d collision);
void		draw_all_square(t_win *win);
void		draw_projection(t_win *win);
void		surround_walls(t_win *win, t_map *map);
void		poly_reduction(t_win *win, t_poly *poly);
t_poly		*inside_poly(t_poly *last_poly, t_poly *poly, int x, int y);

int			process_light(t_map *map, t_poly *poly,
							t_fdot_3d collision, int color);

int			init_rays(t_win *win, t_player *player);
void		translate_all(t_map *map, t_fdot_3d translation);
void		translate_all_poly(t_poly *poly, t_fdot_3d translation);
void		translate_all_objects(t_object *object, t_fdot_3d translation);
void		translate_all_rotz_only(t_map *map, t_poly *poly,
									t_fdot_3d translation);
void		translate_all_poly_rotz_only(t_poly *poly, t_fdot_3d translation);
void		translate_all_objects_rotz_only(t_object *object,
											t_fdot_3d translation);
t_fdot_3d	rotate_dot(t_fdot_3d dot, t_matrix matrix);
void		rotate_all_rotz_only(t_map *map, t_poly *poly, t_matrix matrix);
void		copy_rotate_rotz_only(t_map *map, t_poly *poly, t_matrix matrix);
void		rotate_box(t_player *player, t_object *object);
void		translate_box(t_object *object);

t_matrix	create_matrix(t_fdot_3d axe, float angle);
t_matrix	create_rx_matrix(float angle);
t_matrix	create_ry_matrix(float angle);
t_matrix	create_rz_matrix(float angle);
void		init_matrix_rx(t_player *player);
void		init_matrix_rx_inv(t_player *player);
void		init_matrix_ry(t_player *player);
void		init_matrix_ry_inv(t_player *player);
void		init_matrix_rz(t_player *player);
void		init_matrix_rz_inv(t_player *player);
void		init_polygone(t_poly *poly);
void		init_player_maths(t_win *win, t_player *player);

t_poly		*collisions(t_player *player, t_poly *poly);
int			is_poly_collision(t_player *player, t_poly *poly);
void		slide(t_map *map, t_poly *polys, t_poly *polys_save,
					t_fdot_3d poly_collide_v);

t_poly		*collisions_sphere(t_map *map, t_player *player,
								t_poly *poly, int ban_interest);
int			collision_poly(t_map *map, t_player *player, t_poly *poly);
int			collision_segment(t_fdot_3d dots[4], float width_2);
t_fdot_3d	segment_slide(t_fdot_3d dots[N_DOTS_POLY],
							t_plan plan, int segment_code);
int			collision_dots(t_fdot_3d dots[N_DOTS_POLY], float ray);
int			is_collision_box(t_object *object, t_cartesienne *ray);
void		move_and_collide(t_map *map,
								t_player *player, t_fdot_3d move);

void		*draw_ray(void *param);
int			sky_box(t_sphere *sky_box, t_cartesienne *ray);

int			test_timer(t_timer *timer);
int			test_timer_refresh(t_timer *timer);
void		start_cooldown(t_timer *timer, Uint32 time);
void		reload_cd(t_map *map);

float		scalar_product(t_fdot_3d v1, t_fdot_3d v2);
t_fdot_3d	vectoriel_product(t_fdot_3d v1, t_fdot_3d v2);
float		modulo(float nbr, float mod);
float		fdist(t_fdot p1, t_fdot p2);
float		fdist_3d(t_fdot_3d p1, t_fdot_3d p2);
float		fdist_3d_squared(t_fdot_3d p1, t_fdot_3d p2);
t_fdot_3d	fdot_3d_add(t_fdot_3d d1, t_fdot_3d d2);
t_fdot_3d	fdot_3d_sub(t_fdot_3d d1, t_fdot_3d d2);
float		mag(t_fdot_3d v);
int			sign(float nbr);
t_fdot_3d	normalize(t_fdot_3d vector);
int			is_null(float nbr, float precision);
t_fdot_3d	mid_segment(t_fdot_3d d1, t_fdot_3d d2);

t_dot		intersection_segment_edge(t_win *win,
										t_dot d1, t_dot d2, int edge);
void		draw_affine(t_win *win, t_affine function);
float		fprop(float value, t_fdot inter1, t_fdot inter2);
float		prop(float value, t_dot inter1, t_dot inter2);
int			is_intersection_cercle_poly(t_poly *poly, int radius);
int			intersection_plan_my_ray(t_fdot_3d *collision,
									t_plan plan, t_cartesienne *ray);
int			intersection_plan_ray(t_fdot_3d *collision,
									t_plan plan, t_cartesienne ray);
int			resolve_polynome(t_fdot_3d polynome, float *x1, float *x2);
void		proj_ortho_plan(t_fdot_3d dot, t_plan plan, t_fdot_3d *proj_ortho);
t_fdot_3d	proj_ortho_origin_line(t_fdot_3d l1, t_fdot_3d l2, t_fdot_3d *proj);
int			is_in_segment(t_fdot_3d is, t_fdot_3d d1, t_fdot_3d d2);
int			is_in_poly_rotz_only(t_poly *poly, t_fdot_3d dot);
t_fdot_3d	intersection_axe_y(t_fdot_3d d1, t_fdot_3d d2);

void		main_free_rays(t_cartesienne **rays);
void		main_free_inventory(t_inventory *inventory);
void		main_free_player(t_player *player);
void		main_free_polys(t_poly **polys);

#endif
