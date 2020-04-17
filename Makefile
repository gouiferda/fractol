# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sgouifer <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/14 19:03:09 by sgouifer          #+#    #+#              #
#    Updated: 2019/06/14 19:03:13 by sgouifer         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

CC = gcc
FLAGS = -O3 -w -Wall -Werror -Wextra
LIBRARIES = -lmlx -lm -lft -L$(LIBFT_DIRECTORY) -L$(MINILIBX_DIRECTORY) -framework OpenGL -framework AppKit
INCLUDES = -I$(HEADERS_DIRECTORY) -I $(LIBFT_HEADERS) -I $(MINILIBX_HEADERS)

LIBFT = $(LIBFT_DIRECTORY)libft.a
LIBFT_DIRECTORY = ./libft/
LIBFT_HEADERS = ./includes/libft.h

MINILIBX = $(MINILIBX_DIRECTORY)libmlx.a
MINILIBX_DIRECTORY = ./minilibx/
MINILIBX_HEADERS = $(MINILIBX_DIRECTORY)

HEADERS_LIST = fractol.h\
	keys.h\
	colors.h\
	defaults.h

HEADERS_DIRECTORY = ./includes/
HEADERS = $(addprefix $(HEADERS_DIRECTORY), $(HEADERS_LIST))

SOURCES_DIRECTORY = ./sources/
SOURCES_LIST = main.c\
				validation_functions.c\
				init.c\
				utils_functions1.c\
				utils_functions2.c\
				utils_functions3.c\
				hooks_keys.c\
				hooks_mouse.c\
				events_functions1.c\
				events_functions2.c\
				events_functions3.c\
				events_functions4.c\
				events_functions5.c\
				draw_pixel.c\
				draw_line.c\
				draw_bonus.c\
				draw_easter.c\
				draw_buttons.c\
				draw_fractol_info.c\
				draw_fractol_controls.c\
				draw_f_mandelbrot.c\
				draw_f_julia.c\
				draw_f_sierpinski.c\
				draw_f_tree.c\
				draw_f_burning_ship.c\
				draw_f_barnsley.c\
				draw_f_tricon.c\
				colors_functions.c\
				draw_fractol.c

SOURCES = $(addprefix $(SOURCES_DIRECTORY), $(SOURCES_LIST))

OBJECTS_DIRECTORY = objects/
OBJECTS_LIST = $(patsubst %.c, %.o, $(SOURCES_LIST))
OBJECTS	= $(addprefix $(OBJECTS_DIRECTORY), $(OBJECTS_LIST))


all: $(NAME)

$(NAME): $(LIBFT) $(MINILIBX) $(OBJECTS_DIRECTORY) $(OBJECTS)
	@$(CC) $(FLAGS) $(LIBRARIES) $(INCLUDES) $(OBJECTS) -o $(NAME)
	@echo "$(NAME):	Compiling"

$(OBJECTS_DIRECTORY):
	@mkdir -p $(OBJECTS_DIRECTORY)

$(OBJECTS_DIRECTORY)%.o : $(SOURCES_DIRECTORY)%.c $(HEADERS)
	@$(CC) $(FLAGS) -c $(INCLUDES) $< -o $@

$(LIBFT):
	@$(MAKE) -sC $(LIBFT_DIRECTORY)
	@echo "$(NAME):	Creating $(LIBFT)"

$(MINILIBX):
	@echo "$(NAME):	Creating $(MINILIBX)"
	@$(MAKE) -sC $(MINILIBX_DIRECTORY)

clean:
	@$(MAKE) -sC $(LIBFT_DIRECTORY) clean
	@$(MAKE) -sC $(MINILIBX_DIRECTORY) clean
	@rm -rf $(OBJECTS_DIRECTORY)
	@echo "$(NAME):	Cleaning"

fclean: clean
	@rm -f $(MINILIBX)
	@rm -f $(LIBFT)
	@rm -f $(NAME)

re: 
	@$(MAKE) fclean
	@$(MAKE) all
	
#  //mandelbrot //julia //tree //sierpinski //burningship //barnsley //tricon
run: re 
	@./fractol mandelbrot 
