# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: diegfern <diegfern@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/24 21:13:39 by diegfern          #+#    #+#              #
#    Updated: 2025/09/06 21:29:16 by diegfern         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

# Compilador y flags
CC = cc
CFLAGS = -Wall -Wextra -Werror

# Directorios
SRCDIR = .
LIBFTDIR = libft
#MLXDIR = ./minilibx-linux	# Linux on 42
MLXDIR = ../../../minilibx	# Windows

# Archivos fuente
SRCS = $(SRCDIR)/main.c \
        $(SRCDIR)/colors.c \
        $(SRCDIR)/drawing.c \
        $(SRCDIR)/hooks.c \
        $(SRCDIR)/map_parser.c \
        $(SRCDIR)/projections.c \
        $(SRCDIR)/utils.c \
        $(SRCDIR)/bresenham_utils.c \
		$(SRCDIR)/memory_utils.c \
		$(SRCDIR)/parsing_utils.c \
		$(SRCDIR)/color_utils.c \
		$(SRCDIR)/image_utils.c \


# Archivos objeto
OBJS = $(SRCS:.c=.o)

# Librerías
LIBFT = $(LIBFTDIR)/libft.a
MLX = $(MLXDIR)/libmlx.a
MLX_FLAGS = -L$(MLXDIR) -lmlx -lXext -lX11 -lm -lz

# Includes
INCLUDES = -I. -I$(LIBFTDIR) -I$(MLXDIR)

# Regla principal
all: $(NAME)

# Compilar el programa principal
$(NAME): $(LIBFT) $(MLX) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX_FLAGS) -o $(NAME)

# Compilar libft
$(LIBFT):
	make -C $(LIBFTDIR)

# Compilar minilibx
$(MLX):
	make -C $(MLXDIR) all

# Regla para archivos objeto
%.o: %.c fdf.h
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# Limpiar archivos objeto
clean:
	rm -f $(OBJS)
	make clean -C $(LIBFTDIR)
	make clean -C $(MLXDIR)

# Limpiar todo
fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFTDIR)

# Recompilar todo
re: fclean all

.PHONY: all clean fclean re