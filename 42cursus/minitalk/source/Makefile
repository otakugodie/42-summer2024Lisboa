# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: diegfern <diegfern@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/02 19:29:35 by diegfern          #+#    #+#              #
#    Updated: 2025/06/13 17:43:30 by diegfern         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_CLIENT = client
NAME_SERVER = server

CC = cc
CFLAGS = -Wall -Wextra -Werror

# Cuando uso libft, descomentar estas líneas
# LIBFT_DIR = ./libft
# LIBFT = $(LIBFT_DIR)/libft.a


SRC_CLIENT = client.c
SRC_SERVER = server.c

OBJ_CLIENT = $(SRC_CLIENT:.c=.o)
OBJ_SERVER = $(SRC_SERVER:.c=.o)

all: $(NAME_CLIENT) $(NAME_SERVER)

$(NAME_CLIENT): $(OBJ_CLIENT)
	@echo "Compiling client..."
	@$(CC) $(CFLAGS) $(OBJ_CLIENT) -o $(NAME_CLIENT)
	@echo "Client executable created!"

$(NAME_SERVER): $(OBJ_SERVER)
	@echo "Compiling server..."
	@$(CC) $(CFLAGS) $(OBJ_SERVER) -o $(NAME_SERVER)
	@echo "Server executable created!"

%.o: %.c
	@echo "Compiling $<..."
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "Cleaning object files..."
	@rm -f $(OBJ_CLIENT) $(OBJ_SERVER)

fclean: clean
	@echo "Cleaning executables..."
	@rm -f $(NAME_CLIENT) $(NAME_SERVER)

re: fclean all



# Creación de la librería
#$(NAME): $(OBJ)
#	@echo "Creating static library $(NAME)..."
#	@ar rcs $(NAME) $(OBJ)
#	@echo "Done!"

# Compilación de archivos .c en .o
#%.o: %.c $(HDR)
#	@echo "Compiling $<..."
#	@$(CC) $(CFLAGS) -I. -c $< -o $@


# Limpieza de archivos objeto
#clean:
#	@echo "\nRemoving .o files..."
#	@rm -f $(OBJ)
#	@echo "\nDone!"


# Limpieza total de la librería y archivos objeto
#fclean: clean
#	@echo "\nRemoving library $(NAME)..."
#	@rm -f $(NAME)
#	@echo "\nDone!"

# Recompilación completa
#re: fclean all