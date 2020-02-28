NAME = doom-nukem

SRCS_PATH =     ./srcs
SRCS_PATH_1 =   data
SRCS_PATH_2 =   display
SRCS_PATH_3 =   event
SRCS_PATH_4 =   editor_loop
SRCS_PATH_5 =   game_loop
SRCS_PATH_6 =   physics
SRCS_PATH_7 =   parsing
SRCS_PATH_8 =   menu_loops
SRCS_PATH_9 =   hud
SRCS_PATH_10 =  inventory
SRCS_PATH_11 =  time
SRCS_PATH_12 =  ui
SRCS_PATH_13 =	player
SRCS_PATH_14 =	mobs
SRCS_PATH_15 =	objects
SRCS_LIBUI = libui
SRCS_LIBUI_0 = button
SRCS_LIBUI_1 = draw
SRCS_LIBUI_2 = event
SRCS_LIBUI_3 = frame
SRCS_LIBUI_4 = load_ui
SRCS_LIBUI_5 = shape
SRCS_LIBUI_6 = texture
SRCS_LIBUI_7 = win

#Pas le droit aux wildcards
SRCS =      $(wildcard $(SRCS_PATH)/*.c)\
            $(wildcard $(SRCS_PATH)/$(SRCS_PATH_1)/*.c)\
            $(wildcard $(SRCS_PATH)/$(SRCS_PATH_2)/*.c)\
            $(wildcard $(SRCS_PATH)/$(SRCS_PATH_3)/*.c)\
            $(wildcard $(SRCS_PATH)/$(SRCS_PATH_4)/*.c)\
            $(wildcard $(SRCS_PATH)/$(SRCS_PATH_5)/*.c)\
            $(wildcard $(SRCS_PATH)/$(SRCS_PATH_6)/*.c)\
            $(wildcard $(SRCS_PATH)/$(SRCS_PATH_7)/*.c)\
            $(wildcard $(SRCS_PATH)/$(SRCS_PATH_8)/*.c)\
            $(wildcard $(SRCS_PATH)/$(SRCS_PATH_9)/*.c)\
            $(wildcard $(SRCS_PATH)/$(SRCS_PATH_10)/*.c)\
            $(wildcard $(SRCS_PATH)/$(SRCS_PATH_11)/*.c)\
            $(wildcard $(SRCS_PATH)/$(SRCS_PATH_12)/*.c)\
            $(wildcard $(SRCS_PATH)/$(SRCS_PATH_13)/*.c)\
            $(wildcard $(SRCS_PATH)/$(SRCS_PATH_14)/*.c)\
            $(wildcard $(SRCS_PATH)/$(SRCS_PATH_15)/*.c)\
            $(wildcard $(SRCS_PATH)/$(SRCS_LIBUI)/*.c)\
            $(wildcard $(SRCS_PATH)/$(SRCS_LIBUI)/$(SRCS_LIBUI_0)/*.c)\
            $(wildcard $(SRCS_PATH)/$(SRCS_LIBUI)/$(SRCS_LIBUI_1)/*.c)\
            $(wildcard $(SRCS_PATH)/$(SRCS_LIBUI)/$(SRCS_LIBUI_2)/*.c)\
            $(wildcard $(SRCS_PATH)/$(SRCS_LIBUI)/$(SRCS_LIBUI_3)/*.c)\
            $(wildcard $(SRCS_PATH)/$(SRCS_LIBUI)/$(SRCS_LIBUI_4)/*.c)\
            $(wildcard $(SRCS_PATH)/$(SRCS_LIBUI)/$(SRCS_LIBUI_5)/*.c)\
            $(wildcard $(SRCS_PATH)/$(SRCS_LIBUI)/$(SRCS_LIBUI_6)/*.c)\
            $(wildcard $(SRCS_PATH)/$(SRCS_LIBUI)/$(SRCS_LIBUI_7)/*.c)

OBJS_PATH = ./objs
OBJS = $(patsubst $(SRCS_PATH)/%.c , $(OBJS_PATH)/%.o , $(SRCS))

FW_PATH = ./frameworks
LIBSDL2 = -framework SDL2 -F $(FW_PATH) -framework SDL2_image -framework SDL2_ttf -framework SDL2_mixer -rpath $(FW_PATH)
LIBFT = libft
LIBRARIES = $(LIBSDL2) ./$(LIBFT)/$(LIBFT).a

INCLUDE_PATH = ./includes
INCLUDES = $(wildcard $(INCLUDE_PATH)/*.h)
CC = gcc
CFLAGS += -Wall -Wextra -Werror -O3 -march=native -flto -ffast-math -I$(INCLUDE_PATH)\
														-I$(INCLUDE_PATH)/libui/\
                                                        -I$(LIBFT)/includes/\
														-I./$(LIBSDLMIXER)/\
                                                        -I$(FW_PATH)/SDL2_image.framework/Headers/\
                                                        -I$(FW_PATH)/SDL2_ttf.framework/Headers/\
                                                        -I$(FW_PATH)/SDL2.framework/Headers/\
                                                        -I$(FW_PATH)/SDL2_mixer.framework/Headers/

#-march=native -flto -ffast-math
#Enlever le flag -g3 -fsanitize=address 

all:    directory $(NAME)

$(NAME): $(OBJS) $(INCLUDES)
		make -C $(LIBFT)
		$(CC) $(CFLAGS) $(LIBRARIES) $(OBJS) -o $(NAME)

$(OBJS_PATH)/%.o : $(SRCS_PATH)/%.c
		$(CC) $(CFLAGS) -c $< -o $@
$(OBJS_PATH)/$(SRCS_PATH_1)/%.o : $(SRCS_PATH)/$(SRCS_PATH_1)/%.c
		$(CC) $(CFLAGS) -c $< -o $@
$(OBJS_PATH)/$(SRCS_PATH_2)/%.o : $(SRCS_PATH)/$(SRCS_PATH_2)/%.c
		$(CC) $(CFLAGS) -c $< -o $@
$(OBJS_PATH)/$(SRCS_PATH_3)/%.o : $(SRCS_PATH)/$(SRCS_PATH_3)/%.c
		$(CC) $(CFLAGS) -c $< -o $@
$(OBJS_PATH)/$(SRCS_PATH_4)/%.o : $(SRCS_PATH)/$(SRCS_PATH_4)/%.c
		$(CC) $(CFLAGS) -c $< -o $@
$(OBJS_PATH)/$(SRCS_PATH_5)/%.o : $(SRCS_PATH)/$(SRCS_PATH_5)/%.c
		$(CC) $(CFLAGS) -c $< -o $@
$(OBJS_PATH)/$(SRCS_PATH_6)/%.o : $(SRCS_PATH)/$(SRCS_PATH_6)/%.c
		$(CC) $(CFLAGS) -c $< -o $@
$(OBJS_PATH)/$(SRCS_PATH_7)/%.o : $(SRCS_PATH)/$(SRCS_PATH_7)/%.c
		$(CC) $(CFLAGS) -c $< -o $@
$(OBJS_PATH)/$(SRCS_PATH_8)/%.o : $(SRCS_PATH)/$(SRCS_PATH_8)/%.c
		$(CC) $(CFLAGS) -c $< -o $@
$(OBJS_PATH)/$(SRCS_PATH_9)/%.o : $(SRCS_PATH)/$(SRCS_PATH_9)/%.c
		$(CC) $(CFLAGS) -c $< -o $@
$(OBJS_PATH)/$(SRCS_PATH_10)/%.o : $(SRCS_PATH)/$(SRCS_PATH_10)/%.c
		$(CC) $(CFLAGS) -c $< -o $@
$(OBJS_PATH)/$(SRCS_PATH_11)/%.o : $(SRCS_PATH)/$(SRCS_PATH_11)/%.c
		$(CC) $(CFLAGS) -c $< -o $@
$(OBJS_PATH)/$(SRCS_PATH_12)/%.o : $(SRCS_PATH)/$(SRCS_PATH_12)/%.c
		$(CC) $(CFLAGS) -c $< -o $@
$(OBJS_PATH)/$(SRCS_LIBUI)/%.o : $(SRCS_PATH)/$(SRCS_LIBUI)/%.c
		$(CC) $(CFLAGS) -c $< -o $@
$(OBJS_PATH)/$(SRCS_LIBUI)/$(SRCS_LIBUI_0)/%.o : $(SRCS_PATH)/$(SRCS_LIBUI)/$(SRCS_LIBUI_0)/%.c
		$(CC) $(CFLAGS) -c $< -o $@
$(OBJS_PATH)/$(SRCS_LIBUI)/$(SRCS_LIBUI_1)/%.o : $(SRCS_PATH)/$(SRCS_LIBUI)/$(SRCS_LIBUI_1)/%.c
		$(CC) $(CFLAGS) -c $< -o $@
$(OBJS_PATH)/$(SRCS_LIBUI)/$(SRCS_LIBUI_2)/%.o : $(SRCS_PATH)/$(SRCS_LIBUI)/$(SRCS_LIBUI_2)/%.c
		$(CC) $(CFLAGS) -c $< -o $@
$(OBJS_PATH)/$(SRCS_LIBUI)/$(SRCS_LIBUI_3)/%.o : $(SRCS_PATH)/$(SRCS_LIBUI)/$(SRCS_LIBUI_3)/%.c
		$(CC) $(CFLAGS) -c $< -o $@
$(OBJS_PATH)/$(SRCS_LIBUI)/$(SRCS_LIBUI_4)/%.o : $(SRCS_PATH)/$(SRCS_LIBUI)/$(SRCS_LIBUI_4)/%.c
		$(CC) $(CFLAGS) -c $< -o $@
$(OBJS_PATH)/$(SRCS_LIBUI)/$(SRCS_LIBUI_5)/%.o : $(SRCS_PATH)/$(SRCS_LIBUI)/$(SRCS_LIBUI_5)/%.c
		$(CC) $(CFLAGS) -c $< -o $@
$(OBJS_PATH)/$(SRCS_LIBUI)/$(SRCS_LIBUI_6)/%.o : $(SRCS_PATH)/$(SRCS_LIBUI)/$(SRCS_LIBUI_6)/%.c
		$(CC) $(CFLAGS) -c $< -o $@
$(OBJS_PATH)/$(SRCS_LIBUI)/$(SRCS_LIBUI_7)/%.o : $(SRCS_PATH)/$(SRCS_LIBUI)/$(SRCS_LIBUI_7)/%.c
		$(CC) $(CFLAGS) -c $< -o $@

directory:
		@mkdir $(OBJS_PATH) 2> /dev/null || true
		@mkdir $(OBJS_PATH)/$(SRCS_PATH_1) 2> /dev/null || true
		@mkdir $(OBJS_PATH)/$(SRCS_PATH_2) 2> /dev/null || true
		@mkdir $(OBJS_PATH)/$(SRCS_PATH_3) 2> /dev/null || true
		@mkdir $(OBJS_PATH)/$(SRCS_PATH_4) 2> /dev/null || true
		@mkdir $(OBJS_PATH)/$(SRCS_PATH_5) 2> /dev/null || true
		@mkdir $(OBJS_PATH)/$(SRCS_PATH_6) 2> /dev/null || true
		@mkdir $(OBJS_PATH)/$(SRCS_PATH_7) 2> /dev/null || true
		@mkdir $(OBJS_PATH)/$(SRCS_PATH_8) 2> /dev/null || true
		@mkdir $(OBJS_PATH)/$(SRCS_PATH_9) 2> /dev/null || true
		@mkdir $(OBJS_PATH)/$(SRCS_PATH_10) 2> /dev/null || true
		@mkdir $(OBJS_PATH)/$(SRCS_PATH_11) 2> /dev/null || true
		@mkdir $(OBJS_PATH)/$(SRCS_PATH_12) 2> /dev/null || true

clean:
		rm -rf $(OBJS_PATH)
		make clean -C $(LIBFT)

fclean: clean
		rm -rf $(NAME)
		make fclean -C $(LIBFT)

re:   		fclean all

norme:
		@norminette $(LIBFT)/*.c
		@norminette $(SRCS_PATH)
		@norminette $(INCLUDE_PATH)

.PHONY: all, clean, fclean, re, directory, norme
