NAME = doom-nukem

SRCS_PATH =		./srcs
SRCS_PATH_1 =	data
SRCS_PATH_2 =	display
SRCS_PATH_3 =	event
SRCS_PATH_4 =	editor_loop
SRCS_PATH_5 =	game_loop
SRCS_PATH_6 =	physics
SRCS =		$(wildcard $(SRCS_PATH)/*.c)\
			$(wildcard $(SRCS_PATH)/$(SRCS_PATH_1)/*.c)\
			$(wildcard $(SRCS_PATH)/$(SRCS_PATH_2)/*.c)\
			$(wildcard $(SRCS_PATH)/$(SRCS_PATH_3)/*.c)\
			$(wildcard $(SRCS_PATH)/$(SRCS_PATH_4)/*.c)\
			$(wildcard $(SRCS_PATH)/$(SRCS_PATH_5)/*.c)\
			$(wildcard $(SRCS_PATH)/$(SRCS_PATH_6)/*.c)

OBJS_PATH =	./objs
OBJS = $(patsubst $(SRCS_PATH)/%.c , $(OBJS_PATH)/%.o , $(SRCS))

LIBSDL2 = -framework SDL2 -F $(FW_PATH) -framework SDL2_image -framework SDL2_ttf -rpath $(FW_PATH)
LIBFT = libft
LIBRARIES = $(LIBSDL2) ./$(LIBFT)/$(LIBFT).a

INCLUDE_PATH = ./includes
FW_PATH = ./frameworks
CC = gcc
CFLAGS += -Wall -Wextra -Werror -g -fsanitize=address	-I$(INCLUDE_PATH)\
														-I./$(LIBFT)/includes/\
														-I$(FW_PATH)/SDL2_image.framework/Headers/\
														-I$(FW_PATH)/SDL2_ttf.framework/Headers/\
														-I$(FW_PATH)/SDL2.framework/Headers/

all:	directory $(NAME)

$(NAME): $(OBJS)
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

directory:
		@mkdir $(OBJS_PATH) 2> /dev/null || true
		@mkdir $(OBJS_PATH)/$(SRCS_PATH_1) 2> /dev/null || true
		@mkdir $(OBJS_PATH)/$(SRCS_PATH_2) 2> /dev/null || true
		@mkdir $(OBJS_PATH)/$(SRCS_PATH_3) 2> /dev/null || true
		@mkdir $(OBJS_PATH)/$(SRCS_PATH_4) 2> /dev/null || true
		@mkdir $(OBJS_PATH)/$(SRCS_PATH_5) 2> /dev/null || true
		@mkdir $(OBJS_PATH)/$(SRCS_PATH_6) 2> /dev/null || true

clean:
		rm -rf $(OBJS_PATH)
		make clean -C $(LIBFT)

fclean:	clean
		rm -rf $(NAME)
		make fclean -C $(LIBFT)

re:		fclean all

norme:
		@norminette $(LIBFT)/*.c
		@norminette $(SRCS_PATH)
		@norminette $(INCLUDE_PATH)

.PHONY: all, clean, fclean, re, directory, norme
