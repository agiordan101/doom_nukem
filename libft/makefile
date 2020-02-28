# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: widrye <widrye@student.le-101.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/02 16:01:28 by gmonacho          #+#    #+#              #
#    Updated: 2020/02/27 19:20:25 by widrye           ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #


NAME = libft.a

CC = gcc

SRCS = ./src/ft_atoi.c\
	./src/ft_atof.c\
	./src/ft_abs.c\
	./src/ft_bzero.c\
	./src/ft_isalnum.c\
	./src/ft_isalpha.c\
	./src/ft_isascii.c\
	./src/ft_isdigit.c\
	./src/ft_isprint.c\
	./src/ft_itoa.c\
	./src/ft_memalloc.c\
	./src/ft_memccpy.c\
	./src/ft_memchr.c\
	./src/ft_memcmp.c\
	./src/ft_memcpy.c\
	./src/ft_memdel.c\
	./src/ft_memmove.c\
	./src/ft_memset.c\
	./src/ft_putchar.c\
	./src/ft_putchar_fd.c\
	./src/ft_putendl.c\
	./src/ft_putendl_fd.c\
	./src/ft_putnbr.c\
	./src/ft_putnbr_fd.c\
	./src/ft_putstr.c\
	./src/ft_putstr_fd.c\
	./src/ft_strcat.c\
	./src/ft_strchr.c\
	./src/ft_strclr.c\
	./src/ft_strcmp.c\
	./src/ft_strcpy.c\
	./src/ft_strdel.c\
	./src/ft_strdup.c\
	./src/ft_strequ.c\
	./src/ft_strjoin.c\
	./src/ft_strnequ.c\
	./src/ft_strlcat.c\
	./src/ft_strlen.c\
	./src/ft_strncat.c\
	./src/ft_strncmp.c\
	./src/ft_strncpy.c\
	./src/ft_strnew.c\
	./src/ft_strnstr.c\
	./src/ft_strrchr.c\
	./src/ft_strsplit.c\
	./src/ft_strstr.c\
	./src/ft_strsub.c\
	./src/ft_strtrim.c\
	./src/ft_tolower.c\
	./src/ft_striter.c\
	./src/ft_striteri.c\
	./src/ft_strmap.c\
	./src/ft_strmapi.c\
	./src/ft_toupper.c\
	./src/ft_lstadd.c\
	./src/ft_lstaddend.c\
	./src/ft_lstdel.c\
	./src/ft_lstdelone.c\
	./src/ft_lstiter.c\
	./src/ft_lstmap.c\
	./src/ft_lstnew.c\
	./src/ft_swap.c\
	./src/ft_2dintdel.c\
	./src/ft_count_char.c\
	./src/ft_2dintpushback.c\
	./src/get_next_line.c\
	./src/ft_index.c\
	./src/ft_2dputint.c\
	./src/ft_tabputint.c\
	./src/ft_addtofloat.c \
	./src/ft_countnumbers.c \
	./src/ft_round.c \
	./src/ft_intdel.c \
	./src/ft_2dstrdel.c \
	./src/ft_2dputendl.c \
	./src/ft_2dstrpushback.c \
	./src/ft_2dstrlen.c \
	./src/ft_strrev.c \
	./src/ft_count_words.c \
	./src/ft_create_elem.c \
	./src/ft_lst_pb.c \
	./src/ft_free_list.c \
	./src/ft_content_already_inlist.c

HEADER = ./includes/libft.h

OBJ = $(SRCS:.c=.o)

CFLAGS += -Wall -Wextra  -Werror

all: $(NAME)

%.o: %.c 
		@$(CC) $(CFLAGS) -c $< -o $@
		@printf "#"

$(NAME): $(OBJ)
		@printf "#"
		@ar rcs $(NAME) $(OBJ)
		@echo "\nlib compiled"

clean:
	@rm -rf $(OBJ)
	@echo "objects deleted"

fclean: clean
	rm -rf $(NAME)
	@echo "$(NAME) is deleted"

re: fclean all
