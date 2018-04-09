# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vvoytenk <vvoytenk@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/31 21:06:41 by vvoytenk          #+#    #+#              #
#    Updated: 2018/03/31 21:06:42 by vvoytenk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
MLXFLAGS = -lmlx -framework OpenGL -framework AppKit
NAME = fdf

SRC = main.c center.c change_colour.c change_fdf.c create_image.c create_window.c\
		keys.c move.c read_file.c rotate.c rows.c scale.c validation.c

.PHONY: re clean fclean all fillit libft #Указывает что это не файл
OBJ = $(SRC:.c=.o) #Делаем из того что в SRC .o
LIBFTFLAGS = -L./libft -lft #флаги для либы
LIBFT = libft 

all: $(NAME)

%.o: #правило для компиляции .o-файлов; $@ - автопеременная; меняет .o в .c
	$(CC) -c $(subst .o,.c, $@) -I./libft $(CFLAGS) -o $@ 

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(OBJ) -I./libft $(LIBFTFLAGS) $(MLXFLAGS) $(CFLAGS) -o $(NAME)

$(LIBFT):
	make -C ./libft all

clean:
	rm -f $(OBJ)
	make -C ./libft clean

fclean: clean
	rm -f $(NAME)
	make -C ./libft fclean

re: fclean all