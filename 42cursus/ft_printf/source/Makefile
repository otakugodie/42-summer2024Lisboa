# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: diegfern <diegfern@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/03 18:08:08 by diegfern          #+#    #+#              #
#    Updated: 2024/12/03 18:16:40 by diegfern         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = cc

CFLAGS = -Wall -Wextra -Werror

SRC = ft_printf.c print_numbers.c

OBJ = $(SRC:.c=.o)

HDR = ft_printf.h

all: $(NAME)

# Creación de la librería
$(NAME): $(OBJ)
	@echo "\nCreating static library $(NAME)..."
	@ar rcs $(NAME) $(OBJ)
	@echo "Done!"

# Compilación de archivos .c en .o
%.o: %.c $(HDR)
	@echo "Compiling $<..."
	@$(CC) $(CFLAGS) -I. -c $< -o $@


# Limpieza de archivos objeto
clean:
	@echo "\nRemoving .o files..."
	@rm -f $(OBJ)
	@echo "Done!"


# Limpieza total de la librería y archivos objeto
fclean: clean
	@echo "\nRemoving library $(NAME)..."
	@rm -f $(NAME)
	@echo "Done!"

# Recompilación completa
re: fclean all