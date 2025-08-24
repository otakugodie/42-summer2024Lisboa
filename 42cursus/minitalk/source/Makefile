# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: diegfern <diegfern@student.42lisboa.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/24 23:48:05 by diegfern          #+#    #+#              #
#    Updated: 2025/08/24 23:48:09 by diegfern         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= minitalk
CLIENT		= client
SERVER		= server

CC			= cc
CFLAGS		= -Wall -Wextra -Werror

SRC_CLIENT	= client.c utils.c
SRC_SERVER	= server.c utils.c

OBJ_CLIENT	= $(SRC_CLIENT:.c=.o)
OBJ_SERVER	= $(SRC_SERVER:.c=.o)

all: $(NAME)

$(NAME): $(CLIENT) $(SERVER)

$(CLIENT): $(OBJ_CLIENT)
	$(CC) $(CFLAGS) $(OBJ_CLIENT) -o $(CLIENT)

$(SERVER): $(OBJ_SERVER)
	$(CC) $(CFLAGS) $(OBJ_SERVER) -o $(SERVER)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ_CLIENT) $(OBJ_SERVER)

fclean: clean
	rm -f $(CLIENT) $(SERVER)

re: fclean all

.PHONY: all clean fclean re



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