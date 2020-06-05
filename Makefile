EXEC = doom-nukem
CC = clang
SRCS_PATH = srcs
SRCS =	$(SRCS_PATH)/error.c\
		$(SRCS_PATH)/credit.c\
		$(SRCS_PATH)/init.c\
		$(SRCS_PATH)/init_player_maths.c\
		$(SRCS_PATH)/init_polygone.c\
		$(SRCS_PATH)/main_free.c\
		$(SRCS_PATH)/main.c\
		$(SRCS_PATH)/main_free_entities.c\
		$(SRCS_PATH)/animation/animation.c\
		$(SRCS_PATH)/data/poly.c\
		$(SRCS_PATH)/data/delete_poly.c\
		$(SRCS_PATH)/display/renderer.c\
		$(SRCS_PATH)/display/simple_draw.c\
		$(SRCS_PATH)/display/draw_s.c\
		$(SRCS_PATH)/display/text.c\
		$(SRCS_PATH)/display/texture.c\
		$(SRCS_PATH)/display/window.c\
		$(SRCS_PATH)/editor_loop/ed_action.c\
		$(SRCS_PATH)/editor_loop/ed_convert_value.c\
		$(SRCS_PATH)/editor_loop/ed_delete_map.c\
		$(SRCS_PATH)/editor_loop/ed_delete_mob.c\
		$(SRCS_PATH)/editor_loop/ed_delete_object.c\
		$(SRCS_PATH)/editor_loop/ed_display.c\
		$(SRCS_PATH)/editor_loop/ed_display_inclined.c\
		$(SRCS_PATH)/editor_loop/ed_display_mobs.c\
		$(SRCS_PATH)/editor_loop/ed_display_objects.c\
		$(SRCS_PATH)/editor_loop/ed_display_player.c\
		$(SRCS_PATH)/editor_loop/ed_display_poly.c\
		$(SRCS_PATH)/editor_loop/ed_display_polys.c\
		$(SRCS_PATH)/editor_loop/ed_display_selected.c\
		$(SRCS_PATH)/editor_loop/ed_display_list_selected.c\
		$(SRCS_PATH)/editor_loop/ed_event.c\
		$(SRCS_PATH)/editor_loop/ed_export.c\
		$(SRCS_PATH)/editor_loop/ed_package.c\
		$(SRCS_PATH)/editor_loop/ed_export_fonts.c\
		$(SRCS_PATH)/editor_loop/ed_export_sounds.c\
		$(SRCS_PATH)/editor_loop/ed_export_textures.c\
		$(SRCS_PATH)/editor_loop/ed_get_display_color.c\
		$(SRCS_PATH)/editor_loop/ed_get_object_poly_count.c\
		$(SRCS_PATH)/editor_loop/ed_get_z_limits.c\
		$(SRCS_PATH)/editor_loop/ed_init.c\
		$(SRCS_PATH)/editor_loop/ed_is_next_to_poly.c\
		$(SRCS_PATH)/editor_loop/ed_is_poly_printable.c\
		$(SRCS_PATH)/editor_loop/ed_loop.c\
		$(SRCS_PATH)/editor_loop/ed_manage_property.c\
		$(SRCS_PATH)/editor_loop/ed_place_door.c\
		$(SRCS_PATH)/editor_loop/ed_place_flat.c\
		$(SRCS_PATH)/editor_loop/ed_place_inclined.c\
		$(SRCS_PATH)/editor_loop/ed_place_item.c\
		$(SRCS_PATH)/editor_loop/ed_place_player.c\
		$(SRCS_PATH)/editor_loop/ed_place_poly_base.c\
		$(SRCS_PATH)/editor_loop/ed_place_wall.c\
		$(SRCS_PATH)/editor_loop/ed_poly_type.c\
		$(SRCS_PATH)/editor_loop/ed_selection.c\
		$(SRCS_PATH)/editor_loop/ed_selection_get.c\
		$(SRCS_PATH)/editor_loop/ed_selected.c\
		$(SRCS_PATH)/editor_loop/ed_select_poly.c\
		$(SRCS_PATH)/editor_loop/ed_set_buttons_mob.c\
		$(SRCS_PATH)/editor_loop/ed_set_buttons_properties.c\
		$(SRCS_PATH)/editor_loop/ed_set_flags.c\
		$(SRCS_PATH)/editor_loop/ed_set_functions.c\
		$(SRCS_PATH)/editor_loop/ed_set_menu_button_function.c\
		$(SRCS_PATH)/editor_loop/ed_set_z_functions.c\
		$(SRCS_PATH)/editor_loop/ed_export_write.c\
		$(SRCS_PATH)/editor_loop/ed_export_write_cont.c\
		$(SRCS_PATH)/editor_loop/ed_export_write_item.c\
		$(SRCS_PATH)/event/time.c\
		$(SRCS_PATH)/game_loop/events_game_loop.c \
		$(SRCS_PATH)/game_loop/events.c\
		$(SRCS_PATH)/game_loop/game_loop.c\
		$(SRCS_PATH)/game_loop/events_others.c \
		$(SRCS_PATH)/hud/dead.c\
		$(SRCS_PATH)/hud/hud.c\
		$(SRCS_PATH)/hud/hud_utils.c\
		$(SRCS_PATH)/hud/inventory_hud.c\
		$(SRCS_PATH)/hud/win.c\
		$(SRCS_PATH)/hud/weapon.c\
		$(SRCS_PATH)/inventory/ammo.c\
		$(SRCS_PATH)/inventory/inventory.c\
		$(SRCS_PATH)/inventory/inventory_utils.c\
		$(SRCS_PATH)/libui/ui_error.c\
		$(SRCS_PATH)/libui/ui_init.c\
		$(SRCS_PATH)/menu_loops/end.c\
		$(SRCS_PATH)/menu_loops/main_menu.c\
		$(SRCS_PATH)/menu_loops/main_menu_init_cond.c\
		$(SRCS_PATH)/mobs/hit_mobs.c\
		$(SRCS_PATH)/mobs/mobs_move.c\
		$(SRCS_PATH)/objects/box_object.c\
		$(SRCS_PATH)/objects/door_object.c\
		$(SRCS_PATH)/objects/object.c\
		$(SRCS_PATH)/objects/objects_actions.c\
		$(SRCS_PATH)/parsing/parse_error.c\
		$(SRCS_PATH)/parsing/parse_files.c\
		$(SRCS_PATH)/parsing/parsing.c\
		$(SRCS_PATH)/parsing/parsing_mob.c\
		$(SRCS_PATH)/parsing/parsing_mob_utils.c\
		$(SRCS_PATH)/parsing/parsing_music.c\
		$(SRCS_PATH)/parsing/parsing_object.c\
		$(SRCS_PATH)/parsing/parsing_object_utils.c\
		$(SRCS_PATH)/parsing/parsing_player.c\
		$(SRCS_PATH)/parsing/parsing_sphere.c\
		$(SRCS_PATH)/parsing/parsing_texture.c\
		$(SRCS_PATH)/parsing/parsing_utils2.c\
		$(SRCS_PATH)/parsing/parsing_utils.c\
		$(SRCS_PATH)/parsing/fill_poly_mob.c\
		$(SRCS_PATH)/parsing/find_texture.c\
		$(SRCS_PATH)/parsing/add_object_norm2.c\
		$(SRCS_PATH)/parsing/stock_texture.c\
		$(SRCS_PATH)/parsing/free_stock_texture.c\
		$(SRCS_PATH)/physics/collisions_sphere.c\
		$(SRCS_PATH)/physics/draws.c\
		$(SRCS_PATH)/physics/fts_maths_algebra.c\
		$(SRCS_PATH)/physics/fts_maths_fdots_3d_2.c\
		$(SRCS_PATH)/physics/fts_maths_fdots_3d.c\
		$(SRCS_PATH)/physics/fts_maths_geometry.c\
		$(SRCS_PATH)/physics/fts_poly.c\
		$(SRCS_PATH)/physics/lights.c\
		$(SRCS_PATH)/physics/projection_2d.c\
		$(SRCS_PATH)/physics/rotate.c\
		$(SRCS_PATH)/physics/rotate_rotz_only.c\
		$(SRCS_PATH)/physics/rotations_x.c\
		$(SRCS_PATH)/physics/rotations_y.c\
		$(SRCS_PATH)/physics/rotations_z.c\
		$(SRCS_PATH)/physics/sky_box.c\
		$(SRCS_PATH)/physics/slide.c\
		$(SRCS_PATH)/physics/translate.c\
		$(SRCS_PATH)/physics/translate_rotz_only.c\
		$(SRCS_PATH)/physics/raytracing.c\
		$(SRCS_PATH)/player/init_rays.c\
		$(SRCS_PATH)/player/player.c\
		$(SRCS_PATH)/time/time.c\
		$(SRCS_PATH)/libui/button/ui_button.c\
		$(SRCS_PATH)/libui/button/ui_simple_button.c\
		$(SRCS_PATH)/libui/button/ui_text_area.c\
		$(SRCS_PATH)/libui/button/ui_text_entry_button.c\
		$(SRCS_PATH)/libui/draw/draw.c\
		$(SRCS_PATH)/libui/draw/draw_shape.c\
		$(SRCS_PATH)/libui/event/ui_event.c\
		$(SRCS_PATH)/libui/frame/ui_frame.c\
		$(SRCS_PATH)/libui/frame/ui_simple_frame.c\
		$(SRCS_PATH)/libui/load_ui/ui_check_line_name.c\
		$(SRCS_PATH)/libui/load_ui/ui_general_get.c\
		$(SRCS_PATH)/libui/load_ui/ui_get_b_type.c\
		$(SRCS_PATH)/libui/load_ui/ui_get_flags.c\
		$(SRCS_PATH)/libui/load_ui/ui_get_type.c\
		$(SRCS_PATH)/libui/load_ui/ui_load.c\
		$(SRCS_PATH)/libui/load_ui/ui_parse_button.c\
		$(SRCS_PATH)/libui/load_ui/ui_parse_buttons.c\
		$(SRCS_PATH)/libui/load_ui/ui_parse_frame.c\
		$(SRCS_PATH)/libui/load_ui/ui_parse_frame_data.c\
		$(SRCS_PATH)/libui/load_ui/ui_parse_simple_button.c\
		$(SRCS_PATH)/libui/load_ui/ui_parse_simple_frame.c\
		$(SRCS_PATH)/libui/load_ui/ui_parse_text_area.c\
		$(SRCS_PATH)/libui/load_ui/ui_parse_text_entry_button.c\
		$(SRCS_PATH)/libui/load_ui/ui_parse_text_entry_cut.c\
		$(SRCS_PATH)/libui/load_ui/ui_parse_texture.c\
		$(SRCS_PATH)/libui/load_ui/ui_parse_type.c\
		$(SRCS_PATH)/libui/shape/ui_rect.c\
		$(SRCS_PATH)/libui/texture/ui_draw_one_line_return.c\
		$(SRCS_PATH)/libui/texture/ui_draw_text_line.c\
		$(SRCS_PATH)/libui/texture/ui_draw_text_line_return.c\
		$(SRCS_PATH)/libui/texture/ui_free_texture_set.c\
		$(SRCS_PATH)/libui/texture/ui_get_dst_y.c\
		$(SRCS_PATH)/libui/texture/ui_renderer.c\
		$(SRCS_PATH)/libui/texture/ui_text.c\
		$(SRCS_PATH)/libui/texture/ui_texture.c\
		$(SRCS_PATH)/libui/texture/ui_texture_list.c\
		$(SRCS_PATH)/libui/win/ui.c\
		$(SRCS_PATH)/libui/win/ui_call_button_function.c\
		$(SRCS_PATH)/libui/win/ui_check_text_entry_button.c\
		$(SRCS_PATH)/libui/win/ui_display_buttons.c\
		$(SRCS_PATH)/libui/win/ui_display_frames.c\
		$(SRCS_PATH)/libui/win/ui_display_simple.c\
		$(SRCS_PATH)/libui/win/ui_display_text_area.c\
		$(SRCS_PATH)/libui/win/ui_display_text_entry.c\
		$(SRCS_PATH)/libui/win/ui_get_button_by_id.c\
		$(SRCS_PATH)/libui/win/ui_get_side_rect.c\
		$(SRCS_PATH)/libui/win/ui_mouse.c\
		$(SRCS_PATH)/libui/win/ui_resolve_buttons_event.c\
		$(SRCS_PATH)/libui/win/ui_resolve_text_entry_button.c\
		$(SRCS_PATH)/libui/win/ui_set_button_function.c\
		$(SRCS_PATH)/libui/win/ui_update_buttons.c\
		$(SRCS_PATH)/libui/win/ui_update_frames.c\
		$(SRCS_PATH)/libui/win/ui_win.c\
		$(SRCS_PATH)/libui/win/ui_win_size.c\
		$(SRCS_PATH)/libui/win/ui_win_update_ui.c


HEADERS_PATHS = -I./libft/includes/ -I./includes/ -I./includes/libui

OBJS = $(SRCS:c=o)
LDFLAGS = -lm -pthread -Llibft/ -lft -lSDL2 -lSDL2_ttf -lSDL2_mixer -lSDL2_image
CFLAGS = -Wall -Wextra -Werror -O3 -march=native -ffast-math

HEADERS=	./includes/bordel_proto.h\
			./includes/bordel_struct.h\
			./includes/doom_nukem.h\
			./includes/libui/ui_button.h\
			./includes/libui/ui_draw.h\
			./includes/libui/ui_error.h\
			./includes/libui/ui_event.h\
			./includes/libui/ui_frame.h\
			./includes/libui/ui.h\
			./includes/libui/ui_shape.h\
			./includes/libui/ui_texture.h\
			./includes/libui/ui_win.h

all: libft.a $(EXEC)
	@echo "All done"

$(EXEC): $(OBJS)
	@echo "Compiling project"
	@$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.c $(HEADERS) $(LIBS)
	@echo "Compiling $@"
	@$(CC) $(CFLAGS) $(HEADERS_PATHS) -o $@ -c $<

libft.a:
	make -C libft/

clean:
	@make clean -C libft/
	@rm -f $(OBJS)
	@echo "Objects deleted"

fclean: clean
	@make fclean -C libft/
	@rm -f $(EXEC)
	@echo "$(EXEC) is deleted"

re: fclean all

.PHONY: all clean fclean re
